#include "Arduino.h"
#include "configuration/globalConfig.h"

namespace CameraAnalysis {

    /**
     * class for the analysis of a single Row
     */
    class SingleRowAnalysis {
        public:
            uint32_t* rowDataBufferPointer;
            int16_t sobelRowDataBuffer[VIDEO_RESOLUTION_X-2];

            void updateRow(uint32_t* pixelData, int row);
            void calculateSobelRow();
            uint16_t calculateTrackCenter(uint16_t startSearch);

            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);
        
        private:
            std::tuple<uint16_t, uint16_t> calculateEdges(uint16_t startSearch);

    };

}