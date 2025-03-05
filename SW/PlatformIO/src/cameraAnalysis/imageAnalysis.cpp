#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/cameraAnalysis.h"
 
namespace CameraAnalysis {

    extern bool newImageAvailable;

    /**
     * method to get a pointer of the current image
     * @return pointer of the current image
     */
  
    uint32_t* ImageAnalysis::getImage() {
        return imageDataBuffer;
    }

    /**
     * ToDo: comment
     * @todo Check if there is stil an analyses (then the image should not be overwritten)
     * that should also be 
     */
    void ImageAnalysis::updateImage(uint32_t* pixelData) {
        //ToDo Testing this here!!
        if(!newImageAvailable) {
            imageDataBuffer = pixelData;
            newImageAvailable = true;
        }
    }

    /**
     * @todo Comment
     */
    void ImageAnalysis::calculateSteeringAngle() {
        float tempSteeringAngle = 0;
        tempSteeringAngle = (VIDEO_RESOLUTION_X/2) - trackCenters[0];

        //quadratische Lenkung
        tempSteeringAngle *= 0.1;
        float factor = 0.7;
        if(tempSteeringAngle > 10) {
            factor = 1.0;
        }
        if(tempSteeringAngle < 0) {
            tempSteeringAngle *= tempSteeringAngle*factor;
            tempSteeringAngle = -tempSteeringAngle;    
        }
        else {
            tempSteeringAngle *= (tempSteeringAngle*factor);
        }
        steeringAngle = tempSteeringAngle;
    }

    
    /**
     * method to print an image
     * @param start: startpixel | default 0
     * @param length: the amount of pixel to print | default size of the video-width * lines (image resolution)
     */
    void ImageAnalysis::printImage(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(imageDataBuffer, start, length, "print img:\t");
    }

}