/**
 * camera analysis - definitions
 * 
 * This file ist relevant if there is send image pixel data from the camera! (No analyses on camera)
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
#ifndef ANALYSE_ON_CAMERA

#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/rowAnalysis.h"
#include "cameraAnalysis/camera.h" 


namespace CameraAnalysis {
    
    /* ------- variables ------------------ */
    ImageAnalysis currentImageAnalysis;
    SingleRowAnalysis currentRowAnalysis;

    bool newImageAvailable = false;
    int sobelThreshold = 30;


    /* ------- public known methods ------------------ */

    //comment in .h
    void setup() {
        OpenMVCam::setup();
        for (int i = 0; i < NUMBER_OF_LINES; i++) {
            currentImageAnalysis.trackCenters[i] = VIDEO_RESOLUTION_X/2;
        }
    }

    //comment in .h
    void analyse() {

        OpenMVCam::updateImage();

        if (newImageAvailable) {

            //analyse each row // ToDo Überlegen ob das in die Image Analyse gewechselt werden soll!
            for (int i = 0; i <NUMBER_OF_LINES; i++) {
                currentRowAnalysis.updateRow(currentImageAnalysis.getImage(), i);
                currentRowAnalysis.calculateSobelRow();

                //trackcenter calculation
                currentImageAnalysis.lastTrackCenters[i] = currentImageAnalysis.trackCenters[i];
                currentImageAnalysis.trackCenters[i] = currentRowAnalysis.calculateTrackCenter(currentImageAnalysis.lastTrackCenters[i]);
                currentImageAnalysis.trackCenterOffsets[i] = abs(currentImageAnalysis.trackCenters[i] - (VIDEO_RESOLUTION_X/2));
                
                //Analyse tracks - is it straight or a turn 
                if(currentImageAnalysis.trackCenterOffsets[i] > 30) {
                    currentImageAnalysis.straightLinesAhead = i;
                    break;
                }
                if(i == NUMBER_OF_LINES -1) {
                    currentImageAnalysis.straightLinesAhead = i;
                }    
            }
            
            currentImageAnalysis.calculateSteeringAngle(); // todo - sollte das in image Analysis bleiben?
            //wenn caclulate Steering Angle bleibt, dann aber auch calculate Speed
            newImageAvailable = false;
            imageAnalysIsComplete = 1;
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

        speed = 17; //@todo: remove
        return speed;   
    }

    /* ------- helper methods ------------------ */

    //comment in .h
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
#endif