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
            uint8_t straightLinesAhead;
            uint8_t speed;
            int steeringAngle;
            
            /**
             * update the image pointer to new image data
             */
            void updateImage(uint32_t* pixelData);

            /**
             * getter for a pointer of the current image
             * @return pointer of the current image
             */
            u_int32_t* getImage();

            /**
             * calcutlate the steering angle for the analysed image and store it into steeringAngle
             * it calculates the distance from the track-center and normal track Center (VIDEO_RESOLUTION_Y)
             * and scales the value to usable steering values 
             */
            void calculateSteeringAngle();


            /**
             * calculate the speed for the analysed image and store it into speed
             * depending on the straight lines ahead the the speed gets calculate
             * includes also a speed compensation in very hard turns
             */
            void calculateSpeed();


            /**
             * method to print an image
             * @param start: startpixel where print should begin 
             * @param length: the amount of pixel to print)
             */
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);
    };
}
