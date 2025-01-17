#include "sensors/opticalFlow.h"

#include "Bitcraze_PMW3901.h"
#include "configuration/globalConfig.h"

namespace Sensors {

    namespace OpticalFlow {
        
        Bitcraze_PMW3901 opticalFlowSensor(OPTICAL_FLOW_CHIP_SELECT);

        void setup() {
            if(!opticalFlowSensor.begin()) {
                Serial.println("Error Optical Flow: Initialization failed");
            }
            opticalFlowSensor.setLed(false);
            pinMode(OPTICAL_FLOW_LED, OUTPUT);
            digitalWrite(OPTICAL_FLOW_LED, HIGH);
        }

        void readMotion(int16_t* deltaX, int16_t* deltaY) {
            opticalFlowSensor.readMotionCount(deltaX, deltaY);
        }
    }
}