#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSE_ON_CAMERA //todo Change after copy

#include "cameraAnalysis/trackCenterAnalysis.h"
#include "cameraAnalysis/camera.h"
#include "dataVisualization/display.h"
#include "sensors/sensors.h"

namespace CameraAnalysis {

    //forward declaration
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix);

    TrackCenterAnalysis currentTrackCenterAnalysis;

    //Todo Move to config + work correkt!
    #define MIN_STEERING_LINE 10
    #define MAX_STEERING_LINE 100
    #define MAX_STEERING_LINE_TURN 80 //abhängig von der Ist Geschwindigkeit die Linie nach vorne verschieben!!
    
    void setup() {

        OpenMVCam::setup();
        
        for (int i = 0; i < VIDEO_RESOLUTION_Y; i++) {
            currentTrackCenterAnalysis.trackCenters[i]  = (VIDEO_RESOLUTION_X/2);
        }
        currentTrackCenterAnalysis.lastSteeringLine = MIN_STEERING_LINE;
    }

    void analyse() {
        
        bool straightLineFound = false;
        bool lastSteeringLineFound = false;

        OpenMVCam::updateTrackCenters();
        //DataVisualisation::Display::showTrackCenters(currentTrackCenterAnalysis.trackCenters); //TODo: Überlastung
        //currentTrackCenterAnalysis.printTrackCenters(0,20);
            
        if(!imageAnalysIsComplete) {

            for(int i = 2; i < VIDEO_RESOLUTION_Y; i++) { //start by to (first two values not included!)
                
                //no more usable track center Values (turn detected on Camera)
                if(currentTrackCenterAnalysis.trackCenters[i] == 321 && !lastSteeringLineFound) { //use 321 becaus 255 is mapped to 321 (* 320 / 254)
                    //currentTrackCenterAnalysis.lastSteeringLine = ((i-1) > MIN_STEERING_LINE) ? i-1 : MIN_STEERING_LINE;  //Min Steering Line festhalten
                    currentTrackCenterAnalysis.lastSteeringLine = i-2;
                    lastSteeringLineFound = true;
                    //CONSOLE.println("Test");
                }

                //Todo: if needed the calculation can stop here
                currentTrackCenterAnalysis.trackCenterOffset[i] = (VIDEO_RESOLUTION_X/2) - currentTrackCenterAnalysis.trackCenters[i];
            
                if(abs(currentTrackCenterAnalysis.trackCenterOffset[i]) > STRAIGHT_THRESHOLD && !straightLineFound) {
                    currentTrackCenterAnalysis.lastStraightLine = i-1;
                    straightLineFound = true;
                }
            }
            currentTrackCenterAnalysis.calculateSteeringAngle();
            currentTrackCenterAnalysis.calculateSpeed();

            //finishline detected and wait 10 seconds
            if(currentTrackCenterAnalysis.trackCenters[239] == 322 && millis() > 10000) {
                Serial.print("FINISH");
                currentTrackCenterAnalysis.finishLineDetected = true;
            }

            imageAnalysIsComplete = 1; 
            //CONSOLE.print("Steering Row"); CONSOLE.println(currentTrackCenterAnalysis.lastSteeringLine);
        }       
    }

    int getSteeringAngle() {
        return 90 + currentTrackCenterAnalysis.steeringAngle;
    }

    uint8_t getSpeed() {
        return currentTrackCenterAnalysis.speed;
    }


    void TrackCenterAnalysis::calculateSteeringAngle() {
        float tempSteeringAngle = 0;
        
        int steeringLine = lastSteeringLine;
        //CONSOLE.print("lastSteeringLine "); CONSOLE.print(lastSteeringLine);
        /*if(steeringAngle > 30 || Sensors::usedData.speed < 8) {
            steeringLine = (lastSteeringLine > MAX_STEERING_LINE_TURN) ? MAX_STEERING_LINE_TURN : lastSteeringLine;
            CONSOLE.print("Nah - -");
        } else {
            steeringLine = (lastSteeringLine > MAX_STEERING_LINE) ? MAX_STEERING_LINE : lastSteeringLine;
            CONSOLE.print("Fern - - ");
        } */
        steeringLine = (lastSteeringLine > MAX_STEERING_LINE_TURN) ? MAX_STEERING_LINE_TURN : lastSteeringLine;
        
        /*if (lastSteeringLine > MAX_STEERING_LINE_TURN) {
            steeringLine = MAX_STEERING_LINE_TURN;
        }
        else {
            steeringLine = lastSteeringLine;
        }*/
        
        //CONSOLE.print(" steeringLine: "); CONSOLE.print(steeringLine); CONSOLE.print("-----------");
        
        //CONSOLE.print(" steeringLine "); CONSOLE.print(steeringLine); 
        //CONSOLE.print(" TrackCenter"); CONSOLE.print(trackCenters[steeringLine]);
        //CONSOLE.print(" TrackCenter Offset"); CONSOLE.print(trackCenterOffset[steeringLine]);

        tempSteeringAngle = trackCenterOffset[steeringLine];
        
        //if (steeringAngle > 30) 
        //    tempSteeringAngle = trackCenterOffset[45];
        //else
        //    tempSteeringAngle = trackCenterOffset[90];

        //uint16_t steeringRow = (lastStraightLine  > MIN_STEERING_LINE)  ? lastStraightLine : MIN_STEERING_LINE; 
        //tempSteeringAngle = trackCenterOffset[steeringRow]; 
    
        //CONSOLE.print("Steering Test:"); CONSOLE.println(tempSteeringAngle);

        //map value to usable size for steering
        
        if (steeringLine < 30) {
            tempSteeringAngle *= 0.1;
        }
        else {
            tempSteeringAngle *= 0.1;
        }

        //make stronger angles stronger!
        float factor = 0.6;
        if(tempSteeringAngle > 10) {
            factor = 0.8;
        }

        //square steering 
        if(tempSteeringAngle < 0) {
            tempSteeringAngle *= tempSteeringAngle*factor;
            tempSteeringAngle = -tempSteeringAngle;    
        }
        else {
            tempSteeringAngle *= (tempSteeringAngle*factor);
        }   
        steeringAngle = tempSteeringAngle;
        //CONSOLE.print("steering Angle: "); CONSOLE.println(steeringAngle);
    }

    void TrackCenterAnalysis::calculateSpeed() {
        if(!finishLineDetected) {
            speed = 19;
            speed += lastStraightLine/25;
        }
        else {
            speed = 19;
        }

        //CONSOLE.print(speed); CONSOLE.print(" <- speed - lastStraigLine -> "); CONSOLE.print(lastStraightLine); CONSOLE.print(" ----");
    }

    void TrackCenterAnalysis::updateTrackCenters(uint32_t* trackCenterData) {
        trackCenters = trackCenterData;
        //printArray(trackCenterOffset, 0, 20, "print Offsets;");
    }

    void TrackCenterAnalysis::printTrackCenters(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(trackCenters, start, length, "print TC:\t");
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