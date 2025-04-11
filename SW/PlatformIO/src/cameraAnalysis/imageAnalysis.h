/**
 * image analysis - declaration
 * 
 * this file ist relevant if the camera sends image pixel data! (No analysis on camera)
 * 
 * handles everything belonging to the analysis of the complete transfered image
 * a class is used to store all needed data like imageBuffer, calculated track centers...
 * 
 * the methods are used to administrate these data and calculate everythings that
 * belongs to the complete image like the final speed and steering angle
 * 
 * @author Tom Seiffert
 */
#include "Arduino.h"
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifndef ANALYSIS_ON_CAMERA

namespace CameraAnalysis {
    
    /**
     * class for the analysis of the complete image
     */
    class ImageAnalysis {
        
        public:

            uint32_t* imageDataBuffer;
            uint16_t trackCenters[NUMBER_OF_LINES];
            uint16_t lastTrackCenters[NUMBER_OF_LINES];
            int trackCenterOffsets[NUMBER_OF_LINES];
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
             * calcutlate the steering angle for the analysed image and store it
             * it calculates the distance from the track-center and normal track Center (VIDEO_RESOLUTION_Y)
             * and scales the value to usable steering values for the servo 
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
#endif
#endif
