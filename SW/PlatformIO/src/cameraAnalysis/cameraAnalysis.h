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
            uint8_t imageDataBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
            
            void getImage();
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);

    };

    /**
     * class for the analysis of a single Row
     */
    class SingleRowAnalysis {
        public:
            uint8_t rowDataBuffer[VIDEO_RESOLUTION_X];
            int16_t sobelRowDataBuffer[VIDEO_RESOLUTION_X-2];

            void getRow();
            void calculateSobelRow();
            int calculateTrackCenter();
            std::tuple<int, int> calculateEdges(int startSearch);

            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);

    };

}