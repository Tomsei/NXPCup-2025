#include "configuration/globalConfig.h"

#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSE_ON_CAMERA

#include "Arduino.h"
#include "configuration/cameraAnalysisConfig.h"

extern volatile int imageAnalysIsComplete;

namespace CameraAnalysis {

    void setup();

    void analyse();

    int getSteeringAngle();

    uint8_t getSpeed();

    class TrackCenterAnalysis {
        public:
            uint32_t* trackCenters; //ToDo: uint32_t could be change to uint8_t (then also change image Buffer - Testing!)
            int16_t trackCenterOffset[VIDEO_RESOLUTION_Y]; //could be int 16
            int lastStraightLine;
            int lastSteeringLine;
            int steeringAngle;
            uint8_t speed;
        
            void updateTrackCenters(uint32_t* trackCenterData);
            void calculateSteeringAngle();
            void calculateSpeed();
            void printTrackCenters(int start = 0, int lenght = VIDEO_RESOLUTION_Y);
    };

}

#endif
#endif