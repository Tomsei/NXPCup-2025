/**
 * optical flow - definition
 * 
 * Handels everything to control the optical flow sensor. 
 * This includes functions for setup and getting data.
 * 
 * using the Library: Bitcraze_PMW3901.h 
 * https://github.com/bitcraze/Bitcraze_PMW3901
 * 
 * @author Tom Seiffert
 */
#include "sensors/opticalFlow.h"

#include "Bitcraze_PMW3901.h"
#include "configuration/globalConfig.h"

namespace Sensors {

    namespace OpticalFlow {
        
        Bitcraze_PMW3901 opticalFlowSensor(OPTICAL_FLOW_CHIP_SELECT);

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            if(opticalFlowSensor.begin()) {
                #ifdef CONSOLE
                    CONSOLE.println("Optical Flow setup succesfull");
                #endif
            }
            else {
                #ifdef CONSOLE
                    CONSOLE.println("Optical Flow setup error");    
                #endif
            }
            
            opticalFlowSensor.setLed(false);
            pinMode(OPTICAL_FLOW_LED, OUTPUT);
            digitalWrite(OPTICAL_FLOW_LED, HIGH);
        }

        //comment in .h file
        void readMotion(int16_t* deltaX, int16_t* deltaY) {
            opticalFlowSensor.readMotionCount(deltaX, deltaY);
        }
    }
}