#include <Arduino.h>

#include "cameraAnalysis/camera_OPENMVCAMRT1062.h"

#include "configuration/globalConfig.h"

//void printPictureArray(uint32_t pictureArray[76800]);

namespace CameraAnalysis {

    struct ImageAnalysis {

        uint8_t rowDataBuffer[320];
        
        void getImage();
        void printImage(int start = 0, int length = VIDEO_RESOLUTION_X);
    };
}