/**
 * LineFinder - declaration
 * 
 * using the LineFinder Class to controll the lin finder sensors. 
 * This includes functions for setup and getting data
 * 
 * @todo Implement interrupt for sensor - check other sensor for direction
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace Sensors {
    
    namespace ArdLineFinder {
        
        void setup();

        int getRotationCount();

        int getSpeed();

        void calculateSpeed();
    
    }
}