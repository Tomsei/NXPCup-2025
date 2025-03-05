/**
 * ToF distance - declaration
 * 
 * Handels everything to control the ToF distance sensor (Vl53L0X). 
 * This includes functions for setup and getting data.
 * 
 * using the Library: VL53L0X.h 
 * https://github.com/pololu/vl53l0x-arduino
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace Sensors {

    namespace TofDistance {  

        /**
         * setup the ToF Sensro
         */
        void setup();

        /**
         * get distance values
         * @return the distance to the front
         */
        uint16_t getDistance();

    };
}