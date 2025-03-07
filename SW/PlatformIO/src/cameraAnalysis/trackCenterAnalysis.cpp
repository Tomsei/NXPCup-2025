#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSE_ON_CAMERA //todo Change after copy

#include "cameraAnalysis/trackCenterAnalysis.h"
#include "cameraAnalysis/camera.h"

namespace CameraAnalysis {

    //forward declaration
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix);

    TrackCenterAnalysis currentTrackCenterAnalysis;

    void setup() {

        OpenMVCam::setup();
        
        for (int i = 0; i < VIDEO_RESOLUTION_Y; i++) {
            currentTrackCenterAnalysis.trackCenters[i]  = (VIDEO_RESOLUTION_X/2);
        }
    }

    void analyse() {
        
        OpenMVCam::updateTrackCenters();
        
        if(!imageAnalysIsComplete) {

            for(int i = 2; i < VIDEO_RESOLUTION_Y; i++) { //start by to (first two values not included!)
                
                currentTrackCenterAnalysis.trackCenterOffset[i] = (VIDEO_RESOLUTION_X/2) - currentTrackCenterAnalysis.trackCenters[i];
            
                if(abs(currentTrackCenterAnalysis.trackCenterOffset[i]) > STRAIGHT_THRESHOLD) {
                    currentTrackCenterAnalysis.lastStraightLine = i-1;

                    //calculate the offset vor all other
                    for(int j = VIDEO_RESOLUTION_Y-1; j > i; j--) {
                        currentTrackCenterAnalysis.trackCenterOffset[j] = (VIDEO_RESOLUTION_X/2) - currentTrackCenterAnalysis.trackCenters[j];
                    }
                    //CONSOLE.print(currentTrackCenterAnalysis.lastStraightLine);
                    break;
                }
            }
            currentTrackCenterAnalysis.calculateSteeringAngle();
            currentTrackCenterAnalysis.calculateSpeed();
            imageAnalysIsComplete = 1; 
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
        tempSteeringAngle = trackCenterOffset[80]; 
    
        //map value to usable size for steering
        tempSteeringAngle *= 0.1;

        //make stronger angles stronger!
        float factor = 1.0;
        if(tempSteeringAngle > 10) {
            factor = 1.0;
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
    }

    void TrackCenterAnalysis::calculateSpeed() {
        speed = 15;
        speed += lastStraightLine/20;
    }

    void TrackCenterAnalysis::updateTrackCenters(uint32_t* trackCenterData) {
        trackCenters = trackCenterData;
        //printTrackCenters(0, 20);
    }

    void TrackCenterAnalysis::printTrackCenters(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(trackCenters, start, length, "print img:\t");
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