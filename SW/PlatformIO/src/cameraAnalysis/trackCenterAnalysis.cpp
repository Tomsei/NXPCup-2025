/**
 * track center analysis - definitions
 * 
 * this file ist relevant if the camera sends trackcenter data! (analysis on camera)
 * 
 * handles everything belonging to the trackcenter analysis.
 * This includes the generala camera analysis method (same structure like other approach)
 * which conrols the complete analysis of Trackcenters.
 * 
 * For the management of the track center analysis the TrackCenterAnalysis class is used.
 * This class is also implemented in this file and provides methods to
 * - manage all data belonging to track center analysis
 * - calculate speed
 * - calculate steering angle
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSIS_ON_CAMERA //todo Change after copy

#include "cameraAnalysis/trackCenterAnalysis.h"
#include "cameraAnalysis/camera.h"
#include "dataVisualization/display.h"
#include "sensors/sensors.h"

//defines here to stay in context
#define MIN_STEERING_LINE 10
#define MAX_STEERING_LINE 80
#define MAX_STEERING_LINE_SLOW 30 //take slow line - in front of car
#define MAX_STEERING_LINE_CUTTING 85
#define MAX_STEERING_LINE_TURN 75 //abhängig von der Ist Geschwindigkeit die Linie nach vorne verschieben!!
#define STRAIGHT_ACCELERATION 25 //the lower the faster

#define SPEED_HIGH 27
#define SPEED_MEDIUM 23
#define SPEED_SLOW 19


namespace CameraAnalysis {

    //init static variable
    bool TrackCenterAnalysis::finishLineDetected = false;
    uint64_t TrackCenterAnalysis::finishLineDetectedTime = 100000000;

    bool farSteering = false;

    //forward declaration
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix);

    TrackCenterAnalysis currentTrackCenterAnalysis;

    uint16_t maxSteeringLine = MAX_STEERING_LINE;
    uint16_t maxSteeringLineTurn = MAX_STEERING_LINE_TURN;
    

    //comment in .h
    void setup() {

        OpenMVCam::setup();
        
        for (int i = 0; i < VIDEO_RESOLUTION_Y; i++) {
            currentTrackCenterAnalysis.trackCenters[i]  = (VIDEO_RESOLUTION_X/2);
        }
        currentTrackCenterAnalysis.lastSteeringLine = MIN_STEERING_LINE;
        currentTrackCenterAnalysis.choosenBaseSpeed = SPEED_HIGH;

    }

    
    //comment in .h
    void analyse(bool enableFinishLineDetection) {
        
        OpenMVCam::updateTrackCenters();

        if(!imageAnalysIsComplete) {

            bool straightLineFound = false;
            bool lastSteeringLineFound = false;
        
            currentTrackCenterAnalysis.enableFinishLineDetection = enableFinishLineDetection;
            DataVisualization::Display::showTrackCenters(currentTrackCenterAnalysis.trackCenters); //remove in final run
            //currentTrackCenterAnalysis.printTrackCenters(0, 20);

            //check valid data
            if(currentTrackCenterAnalysis.trackCenters[0] != 322 || currentTrackCenterAnalysis.trackCenters[1] != 0) {
                CONSOLE.print("data - error");
            }
            else {

                for(int i = 2; i < VIDEO_RESOLUTION_Y; i++) { //start by two (first two values are no track center infos!)
                
                    //no more valid track center Values (turn detected on Camera)
                    if(currentTrackCenterAnalysis.trackCenters[i] > 320 && !lastSteeringLineFound) { //use 321 becaus 255 is mapped to 321 (* 320 / 254)
                        currentTrackCenterAnalysis.lastSteeringLine = i-1; 
                        lastSteeringLineFound = true;
                    }
    
                    currentTrackCenterAnalysis.trackCenterOffset[i] = (VIDEO_RESOLUTION_X/2) - currentTrackCenterAnalysis.trackCenters[i];
                
                    if(abs(currentTrackCenterAnalysis.trackCenterOffset[i]) > STRAIGHT_THRESHOLD && !straightLineFound) {
                        currentTrackCenterAnalysis.lastStraightLine = i-1;
                        straightLineFound = true;
                    }
                }

                currentTrackCenterAnalysis.calculateSteeringAngle();
                currentTrackCenterAnalysis.calculateSpeed();
    
                //wait 10 seconds before finishline detection
                if(currentTrackCenterAnalysis.trackCenters[239] == 322 && millis() > TIME_TO_FINISHLINE_DETECTION) {
                    TrackCenterAnalysis::finishLineDetected = true;
                    TrackCenterAnalysis::finishLineDetectedTime = millis();
                }
            }
            imageAnalysIsComplete = 1; 
        }       
    }

    
    //comment in .h
    int getSteeringAngle() {
        return 90 + currentTrackCenterAnalysis.steeringAngle;
    }

    //comment in .h
    uint8_t getSpeed() {
        return currentTrackCenterAnalysis.speed;
    }


    //comment in .h
    void TrackCenterAnalysis::calculateSteeringAngle() {
        
        float tempSteeringAngle = 0;
        int steeringLine = lastSteeringLine;

        //calculate choosen steering line
        steeringLine = (lastSteeringLine > maxSteeringLineTurn) ? maxSteeringLineTurn : lastSteeringLine;
        if (lastStraightLine > steeringLine || farSteering) {
            steeringLine = (lastSteeringLine > maxSteeringLine) ? maxSteeringLine : lastSteeringLine;
            farSteering = true;
        }
        if(steeringLine < 81) {
            farSteering = false;
        }
        //slow drive after finish Line Detection -> near steering line 
        if(finishLineDetected || (!enableFinishLineDetection)) {
            if ((finishLineDetectedTime + 1000) < millis()) {
                steeringLine = MAX_STEERING_LINE_SLOW;
            }
        }


        tempSteeringAngle = trackCenterOffset[steeringLine];
    
        //map value to usable size for steering        
        tempSteeringAngle *= 0.1;

        //make stronger angles stronger!
        float factor = 0.55;
        if(tempSteeringAngle > 10) {
            factor = 0.6;
        }

        //change factor if near steering is active (slow drive)
        if(finishLineDetected || (!enableFinishLineDetection)) {
            if ((finishLineDetectedTime + 1000) < millis()) {
                factor = 0.9; 
            }
        }

        //square steering 
        if(tempSteeringAngle < 0) {
            tempSteeringAngle *= (tempSteeringAngle * factor);
            tempSteeringAngle = -tempSteeringAngle;    
        }
        else {
            tempSteeringAngle *= (tempSteeringAngle * factor);
        }   
        steeringAngle = tempSteeringAngle;
    }


    //comment in .h
    void TrackCenterAnalysis::calculateSpeed() {
        if(!TrackCenterAnalysis::finishLineDetected  || (!enableFinishLineDetection)) {
            speed = choosenBaseSpeed;
            speed += lastStraightLine/STRAIGHT_ACCELERATION;
        }
        else {
            speed = 13;
        }
    }

    //comment in .h
    void TrackCenterAnalysis::updateTrackCenters(uint32_t* trackCenterData) {
        trackCenters = trackCenterData;
    }

    //comment in .h
    void TrackCenterAnalysis::printTrackCenters(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(trackCenters, start, length, "print TC:\t");
    }

    //comment in .h
    void TrackCenterAnalysis::printTrackCenterOffsets(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(trackCenterOffset, start, length, "print TCOffset:\t");
    }


    /* ---- helper method ---*/

    /**
     * method to print an array. - helper method for image and row analysis
     * concatenate an string with all the values of the array.
     * @param arrayToPrint: the array to print
     * @param start: startvalue where to start at the array
     * @param length: the amout of values to print
     * @param linePrefix: prefix to print before the values
     * 
     * template<typename IntArray> to make sure an uint8_t and uint16_t array can be printed 
     * because camera anaylsis is not defined when using track center analysis it also implementet here
     */
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix) {
        #ifdef CONSOLE
            String printedArray = "";
            printedArray = printedArray + linePrefix;
            for (int i = start; i < (start + length); i++) {
                printedArray = printedArray + arrayToPrint[i] + "\t";
            }
            CONSOLE.println(printedArray);
        #endif
    }
}

#endif
#endif