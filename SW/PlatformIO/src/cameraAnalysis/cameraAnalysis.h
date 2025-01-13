#include <Arduino.h>

#include "cameraAnalysis/camera_OPENMVCAMRT1062.h"

#include "configuration/globalConfig.h"

namespace CameraAnalysis {

    void setup();

    void analyse();


    /**
     * structure for the analysis of a complete image
     */
    class ImageAnalysis {
        public:
            uint32_t* imageDataBuffer;
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
            int calculateTrackCenter();

            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);
        
        private:
            std::tuple<int, int> calculateEdges(int startSearch);

    };

}