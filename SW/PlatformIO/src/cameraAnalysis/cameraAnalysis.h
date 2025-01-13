#include <Arduino.h>

#include "cameraAnalysis/camera_OPENMVCAMRT1062.h"

#include "configuration/globalConfig.h"

namespace CameraAnalysis {

    void setup();

    /**
     * structure for the analysis of a complete image
     */
    class ImageAnalysis {
        public:
            uint32_t imageDataBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
            uint32_t* imageDataBufferPointer;
            
            void updateImage();
            void updateImage(uint32_t* pixelData);
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);

    };

    /**
     * class for the analysis of a single Row
     */
    class SingleRowAnalysis {
        public:
            uint32_t rowDataBuffer[VIDEO_RESOLUTION_X];
            uint32_t* rowDataBufferPointer;
            int16_t sobelRowDataBuffer[VIDEO_RESOLUTION_X-2];

            void getRow();
            void updateRow(uint32_t* pixelData, int row);
            void updateRowBuffer(uint32_t* pixelData, int row);
            void calculateSobelRow();
            int calculateTrackCenter();
            std::tuple<int, int> calculateEdges(int startSearch);

            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);

    };

}