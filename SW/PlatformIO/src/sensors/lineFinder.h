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
namespace Sensors {
    
    /**
     * LineFinder class
     * controling the line finder sensors
     */
    class LineFinder {
        public:

            /**
             * constructor to configure the pin
             */
            LineFinder(uint8_t pin);

            /**
             * get the current Sensor state
             * @return the sensor state (0: nothing detected | 1: detected)
             */
            uint8_t getCurrentState(); 
        
        private:
            uint8_t pin;
    };
}