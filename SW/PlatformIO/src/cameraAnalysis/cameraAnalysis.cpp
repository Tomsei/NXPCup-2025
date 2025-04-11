/**
 * camera analysis - definitions
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

#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/rowAnalysis.h"
#include "cameraAnalysis/camera.h" 


namespace CameraAnalysis {
    
    /* ------- variables ------------------ */
    ImageAnalysis currentImageAnalysis;
    SingleRowAnalysis currentRowAnalysis;

    int sobelThreshold = 20;


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


        if (!imageAnalysIsComplete) {
            
            //analyse each row 
            for (int i = 0; i < NUMBER_OF_LINES; i++) {
                currentRowAnalysis.updateRow(currentImageAnalysis.getImage(), i);
                currentRowAnalysis.calculateSobelRow();

                //trackcenter calculation
                currentImageAnalysis.lastTrackCenters[i] = currentImageAnalysis.trackCenters[i];
                currentImageAnalysis.trackCenters[i] = currentRowAnalysis.calculateTrackCenter(currentImageAnalysis.lastTrackCenters[i]);
                currentImageAnalysis.trackCenterOffsets[i] = currentImageAnalysis.trackCenters[i] - (VIDEO_RESOLUTION_X/2); //todo change!
                
                //Analyse tracks - is it straight or a turn 
                if(abs(currentImageAnalysis.trackCenterOffsets[i]) > STRAIGHT_THRESHOLD) {
                    currentImageAnalysis.straightLinesAhead = i;
                    
                    //reset last Trackcenters for all lines not found
                    for(int j = NUMBER_OF_LINES-1; j > i; j--) {
                        currentImageAnalysis.lastTrackCenters[j] = VIDEO_RESOLUTION_X/2;
                    }

                    break;
                }
                if(i == NUMBER_OF_LINES - 1) {
                    currentImageAnalysis.straightLinesAhead = i;
                }    
            }
            
            currentImageAnalysis.calculateSteeringAngle(); 
            currentImageAnalysis.calculateSpeed();
            imageAnalysIsComplete = 1;
        }
    }

    //comment in .h
    int getSteeringAngle() {
        return 90 + currentImageAnalysis.steeringAngle;
    }

    //comment in .h
    uint8_t getSpeed() {
        return currentImageAnalysis.speed;
    }

}
#endif
#endif