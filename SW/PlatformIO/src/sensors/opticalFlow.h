/**
 * optical flow - declaration
 * 
 * Handels everything to control the optical flow sensor. 
 * This includes functions for setup and getting data.
 * 
 * using the Library: Bitcraze_PMW3901.h 
 * https://github.com/bitcraze/Bitcraze_PMW3901
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace Sensors {
    
    namespace OpticalFlow {

        /**
         * setup optical flow with the library
         * turn on the additional red optical flow LED
         */
        void setup();

        /**
         * get motion data and write it to the pointer variables
         * @param detlaX: pointer to variable to store the x value
         * @param deltaY: pointer to variable to store the y value
         */
        void readMotion(int16_t* deltaX, int16_t* deltaY); 
    };
}