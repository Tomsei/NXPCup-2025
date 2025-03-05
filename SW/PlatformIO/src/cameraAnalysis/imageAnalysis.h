//#include "cameraAnalysis/cameraAnalysis.h"
#include "Arduino.h"
#include "configuration/globalConfig.h"

namespace CameraAnalysis {
    
    /**
     * class for the analyses of the whole image
     */
    class ImageAnalysis {
        public:
            uint32_t* imageDataBuffer;
            uint16_t trackCenters[NUMBER_OF_LINES];
            uint16_t lastTrackCenters[NUMBER_OF_LINES];
            uint16_t trackCenterOffsets[NUMBER_OF_LINES];
            int steeringAngle;
            uint8_t speed;
            uint8_t straightLinesAhead;
            
            /**
             * updates the image
             */
            void updateImage(uint32_t* pixelData);
            

            /**
             * getter for a pointer of the current image
             * @return pointer of the current image
             */
            u_int32_t* getImage();

            /**
             * 
             */
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);
            
            /**
             * 
             */
            void calculateSteeringAngle();

            /**
             * 
             */
    };
}
