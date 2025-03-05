/**
 * camera analysis - definitions
 * 
 * Handles everything belonging to the camera analysis.
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

#include <Arduino.h>

namespace CameraAnalysis {

    /**
     * setup the camera analysis 
     * trigger the OpenMVCam (spi) setup and 
     * initiate the trackCenters to the middle of the cam
     */
    void setup();

    /**
     * analyse the picture data to get the speed and the steering angle
     * trys to update Image and analyse it, if there is a new one
     * 
     * triggers all sub-methods to analyse the image Data and stores the analysed trackCenter data
     */
    void analyse();

    /**
     * method to get the calculatet steering angle
     * @return steering angle
     */
    int getSteeringAngle();

    /**
     * method to geht the calculatet speed
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
     * template<typename IntArray> to make sure an uint8_t and uint16_t array can be printed 
     */
    template<typename IntArray>
    void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);

}
#endif