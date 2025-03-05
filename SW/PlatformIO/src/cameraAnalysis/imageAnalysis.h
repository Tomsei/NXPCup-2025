//#include "cameraAnalysis/cameraAnalysis.h"
#include "Arduino.h"
#include "configuration/globalConfig.h"

/**
 * structure for the analysis of a complete image
 */
namespace CameraAnalysis {
    class ImageAnalysis {
        public:
            uint32_t* imageDataBuffer;
            uint16_t trackCenters[NUMBER_OF_LINES];
            uint16_t lastTrackCenters[NUMBER_OF_LINES];
            uint16_t trackCenterOffsets[NUMBER_OF_LINES];
            int steeringAngle;
            uint8_t straightLinesAhead;

            u_int32_t* getImage();
            void updateImage(uint32_t* pixelData);
            void printImage(int start = 0, int length = VIDEO_RESOLUTION_X*NUMBER_OF_LINES);
            void calculateSteeringAngle();
    };
}
