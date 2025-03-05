#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/rowAnalysis.h"


namespace CameraAnalysis {
    
    //variables -------------------------
    ImageAnalysis currentImageAnalysis;
    SingleRowAnalysis currentRowAnalysis;

    bool newImageAvailable = false;
    int sobelThreshold = 20;


    //methods ---------------------------
    void setup() {
        OpenMVCam::setup();
        for (int i = 0; i < NUMBER_OF_LINES; i++) {
            currentImageAnalysis.trackCenters[i] = 160;
        }
    }

    /**
     * Method to analyse the picture to get driving vector (steering Angel)
     */
    //comment in .h
    void analyse() {
        if (newImageAvailable) {
            for (int i = 0; i <NUMBER_OF_LINES; i++) {
                currentRowAnalysis.updateRow(currentImageAnalysis.getImage(), i);
                currentRowAnalysis.calculateSobelRow();

                currentImageAnalysis.lastTrackCenters[i] = currentImageAnalysis.trackCenters[i];
                currentImageAnalysis.trackCenters[i] = currentRowAnalysis.calculateTrackCenter(currentImageAnalysis.lastTrackCenters[i]);
                currentImageAnalysis.trackCenterOffsets[i] = abs(currentImageAnalysis.trackCenters[i] - (VIDEO_RESOLUTION_X/2));
                
                //ToDo Jump Out if it is a turn
                if(currentImageAnalysis.trackCenterOffsets[i] > 30) {
                    //CONSOLE.println("Break");
                    currentImageAnalysis.straightLinesAhead = i;
                    break;
                }
                if(i == NUMBER_OF_LINES -1) {
                    currentImageAnalysis.straightLinesAhead = i;
                }    
            }
            
            //CONSOLE.println("--------------");
            currentImageAnalysis.calculateSteeringAngle();

            newImageAvailable = false;
        }
    }

    //comment in .h
    int getSteeringAngle() {
        return 90 + currentImageAnalysis.steeringAngle;
    }

    //comment in .h
    uint8_t getSpeed() {
        int speed = 0;
        if(currentImageAnalysis.trackCenterOffsets[4] < 25 && currentImageAnalysis.straightLinesAhead > 3 ) {
            speed = 26;
        }
        else if(currentImageAnalysis.trackCenterOffsets[3] < 25 && currentImageAnalysis.straightLinesAhead > 2 ) {
            speed = 24;
        }
        else if(currentImageAnalysis.trackCenterOffsets[2] < 25  && currentImageAnalysis.straightLinesAhead > 1 ) {
            speed = 23;
        }
        else if(currentImageAnalysis.trackCenterOffsets[1] < 25  && currentImageAnalysis.straightLinesAhead > 0) {
            speed = 21;
        }
        else {
            speed = 19;
        }
        //try speed change //ToDo change
        if(abs(currentImageAnalysis.steeringAngle) > 50)
            speed *= 1.1;

        speed = 17;
        return speed;   
    }

    /* ----- helper methods -----  */

    /**
     * method to print an array.
     * concatenate an string with all the values of the array.
     * @param arrayToPrint: the array to print
     * @param start: startvalue where to start at the array
     * @param length: the amout of values to print
     * @param linePrefix: prefix to print before the values
     * 
     * template<typename IntArray> to make sure an uint8_t and uint16_t array can be printed 
     */
    template<typename IntArray>
    void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix) {
        String printedArray = "";
        printedArray = printedArray + linePrefix;
        for (int i = start; i < (start + length); i++) {
            printedArray = printedArray + arrayToPrint[i] + "\t";
        }
        CONSOLE.println(printedArray);
    }
}
#endif