/**
 * camera analysis - declarations
 * 
 * this file ist relevant if the camera sends image pixel data! (No analysis on camera)
 * 
 * handles everything belonging to the camera analysis.
 * This is the high level camera analysis which administrates the 
 * individual components for each task and provides the interface of the camera analysis 
 * 
 * administrates the following tasks:
 * OpenMVCam: SPI connection to camera
 * ImageAnalysis: analysis of the whole image
 * rowAnalysis: analysis of a single row
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifndef ANALYSIS_ON_CAMERA

#include <Arduino.h>
#include "configuration/cameraConfig.h"

extern volatile int imageAnalysIsComplete;

namespace CameraAnalysis {

    /**
     * setup the camera analysis 
     * trigger the OpenMVCam (spi) setup and 
     * initiate the trackCenters to the middle of the cam
     */
    void setup();

    /**
     * trys to update Image and analyse it, 
     * if there is a new one analyse the picture data 
     * to get speed and steering angle
     * 
     * triggers all sub-methods to analyse the image data and stores the analysed trackCenter data
     */
    void analyse();

    /**
     * method to get the calculatet steering angle and map it to usabel servo value
     * @return steering angle
     */
    int getSteeringAngle();

    /**
     * method to get the calculatet speed
     * @return speed
     */
    uint8_t getSpeed();

    /**
     * method to print an array. - helper method for image and row analysis
     * concatenate an string with all the values of the array.
     * @param arrayToPrint: the array to print
     * @param start: startvalue where to start at the array
     * @param length: the amout of values to print
     * @param linePrefix: prefix to print before the values
     * 
     * template<typename IntArray> to make sure an uint8_t and uint16_t array could get printed 
     * because it is a template it must be implementet in .h
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