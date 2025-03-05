#include "configuration/globalConfig.h"
#ifndef ANALYSE_ON_CAMERA

#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/cameraAnalysis.h"
 
namespace CameraAnalysis {

    //comment in .h
    void ImageAnalysis::updateImage(uint32_t* pixelData) {
        imageDataBuffer = pixelData;
    }

    //comment in .h
    uint32_t* ImageAnalysis::getImage() {
        return imageDataBuffer;
    }


    //comment in .h
    void ImageAnalysis::calculateSteeringAngle() {
        float tempSteeringAngle = 0;
        tempSteeringAngle = (VIDEO_RESOLUTION_X/2) - trackCenters[0]; //distance to middle

        //map value to usable size for steering
        tempSteeringAngle *= 0.1;
        
        //make stronger angles stronger!
        float factor = 0.7;
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

    //comment in .h
    void ImageAnalysis::calculateSpeed() {

        switch (straightLinesAhead)
        {
        case 0: 
            speed = 19;
            break;
        case 1:
            speed = 21;
            break;
        case 2:
            speed = 23;
            break;
        case 3: 
            speed = 24;
            break;
        case 4:
            speed = 26;        
        default:
            speed = 15;
        }
        
        //speed compensation in turn
        if(abs(steeringAngle) > 50)
            speed *= 1.1;

        speed = 17; //@todo: remove
    }

    //comment in .h
    void ImageAnalysis::printImage(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(imageDataBuffer, start, length, "print img:\t");
    }
}
#endif