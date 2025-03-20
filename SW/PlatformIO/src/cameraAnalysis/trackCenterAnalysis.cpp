#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSE_ON_CAMERA //todo Change after copy

#include "configuration/cameraConfig.h"
#include "cameraAnalysis/trackCenterAnalysis.h"
#include "cameraAnalysis/camera.h"
#include "dataVisualisation/display.h"

namespace CameraAnalysis {

    //forward declaration
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix);

    TrackCenterAnalysis currentTrackCenterAnalysis;

    //Todo Move to config + work correkt!
    #define MIN_STEERING_LINE 10
    #define MAX_StEERING_LINE 100 //abhängig von der Ist Geschwindigkeit die Linie nach vorne verschieben!!

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
        //DataVisualisation::Display::showTrackCenters(currentTrackCenterAnalysis.trackCenters);
        //currentTrackCenterAnalysis.printTrackCenters(0,20);
            
        if(!imageAnalysIsComplete) {

            for(int i = 2; i < VIDEO_RESOLUTION_Y; i++) { //start by to (first two values not included!)
                
                //no more usable track center Values (turn detected on Camera)
                if(currentTrackCenterAnalysis.trackCenters[i] == 321 && !lastSteeringLineFound) { //use 321 becaus 255 is mapped to 321 (* 320 / 254)
                    //currentTrackCenterAnalysis.lastSteeringLine = ((i-1) > MIN_STEERING_LINE) ? i-1 : MIN_STEERING_LINE;  //Min Steering Line festhalten
                    currentTrackCenterAnalysis.lastSteeringLine = i-1;
                    lastSteeringLineFound = true;
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
        

        
        int steeringLine = (lastSteeringLine > MAX_StEERING_LINE) ? MAX_StEERING_LINE : lastSteeringLine; 

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
        float factor = 0.7;
        if(tempSteeringAngle > 10) {
            factor = 1.0;
        } else if (tempSteeringAngle > 15) {
            factor = 1.4;
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
        speed = 60;
        speed += lastStraightLine/25;
        //CONSOLE.print(speed); CONSOLE.print(" - "); CONSOLE.println(lastStraightLine);
    }

    void TrackCenterAnalysis::updateTrackCenters(uint32_t* trackCenterData) {
        trackCenters = trackCenterData;
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