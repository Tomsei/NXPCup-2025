/**
 * ToF distance - definition
 * 
 * Handels everything to control the ToF distance sensor (Vl53L0X). 
 * This includes functions for setup and getting data.
 * 
 * using the Library: VL53L0X.h 
 * https://github.com/pololu/vl53l0x-arduino
 * 
 * @author Tom Seiffert
 */
#include "sensors/tofDistance.h"

#include <VL53L0X.h>

namespace Sensors {

    namespace TofDistance {
        
        VL53L0X tofSensor;

        //comment in .h file
        void setup() {
            tofSensor.setTimeout(500);
            if(tofSensor.init()) {
                #ifdef CONSOLE
                    CONSOLE.println("TOF Sensor setup succesfull");
                #endif
            }
            else {
                #ifdef CONSOLE
                    CONSOLE.println("TOF Sensor setup error");
                #endif
            }
            tofSensor.startContinuous();
        }

        //comment in .h file
        uint16_t getDistance() {
            if (tofSensor.timeoutOccurred()) {
                #ifdef CONSOLE
                    CONSOLE.print(" TIMEOUT VL53L0X sensor");
                #endif
            }
            return tofSensor.readRangeContinuousMillimeters();
        }
    }
}