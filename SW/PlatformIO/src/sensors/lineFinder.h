/**
 * LineFinder - declaration
 * 
 * using the LineFinder to track the detectet transistion of the wheel. 
 * count the detectet transistions and store ist
 * after 100 ms (car logik) calculatet speed is called and it save the
 * transistions of the past time interval as speed
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace Sensors {
    
    namespace ArdLineFinder {
        
        /**
         * setup the line finder through defining the 
         * needed interrupt method
         */
        void setup();
        
        /**
         * getter for current sensor state
         * @return: current sensor state
         */
        int getSensorState();

        /**
         * getter for calculatet speed
         * @return: calculatet speed
         */
        int getSpeed();

        /**
         * calculate speed of the past time intervall
         */
        void calculateSpeed();
    
    }
}