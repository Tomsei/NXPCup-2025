/**
 * LineFinder - definition
 * 
 * @todo Clean up (description and comments)
 * 
 * using the LineFinder Class to controll the lin finder sensors. 
 * This includes functions for setup and getting data
 * 
 * @todo Implement interrupt for sensor - check other sensor for direction - Comment the new implementation
 * 
 * @author Tom Seiffert
 */
#include "sensors/lineFinder.h"

namespace Sensors {

    namespace ArdLineFinder {
        /* ------- public known methods ------------------ */
        int lineFinderRoations = 0;
        int speed = 0;

        void lineFinderInterrupt() {
            lineFinderRoations = lineFinderRoations + 1;
        }

        void setup() {
            pinMode(ARD_LINE_FINDER2, INPUT_PULLUP);
            attachInterrupt(ARD_LINE_FINDER2, &lineFinderInterrupt, RISING | FALLING);
            #ifdef CONSOLE
                CONSOLE.println("setup Ardlinfinder succesfull");
            #endif
        }

        int getRotationCount() {
            return lineFinderRoations;
        }

        int getSpeed() {
            return speed;
        }

        void calculateSpeed() {
            speed = lineFinderRoations;
            lineFinderRoations = 0;
        }

    }
    
}