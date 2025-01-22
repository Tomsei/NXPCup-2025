#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include <Arduino.h>

#include "cameraAnalysis/camera.h"


namespace CameraAnalysis {

    void setup();

    void analyse();

    int getSteeringAngle();

    uint8_t getSpeed();

    /**
     * structure for the analysis of a complete image
     */
    class ImageAnalysis {
        public:
            uint32_t* imageDataBuffer;
            uint16_t trackCenters[NUMBER_OF_LINES];
            int steeringAngle;

            u_int32_t* getImage();
            void updateImage(uint32_t* pixelData);
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);
    };

    /**
     * class for the analysis of a single Row
     */
    class SingleRowAnalysis {
        public:
            uint32_t* rowDataBufferPointer;
            int16_t sobelRowDataBuffer[VIDEO_RESOLUTION_X-2];

            void updateRow(uint32_t* pixelData, int row);
            void calculateSobelRow();
            uint16_t calculateTrackCenter();

            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);
        
        private:
            std::tuple<uint16_t, uint16_t> calculateEdges(int startSearch);

    };

}
#endif