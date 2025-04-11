/**
 * LineFinder - definition
 * 
 * using the LineFinder to track the detectet transistion of the wheel. 
 * count the detectet transistions and store ist
 * after 100 ms (car logik) calculatet speed is called and it save the
 * transistions of the past time interval as speed
 * 
 * @author Tom Seiffert
 */
#include "sensors/lineFinder.h"

namespace Sensors {

    namespace ArdLineFinder {

        int lineFinderRoations = 0;
        int speed = 0;
        
        //interupt to count the detectet transition
        void lineFinderInterrupt() {
            lineFinderRoations = lineFinderRoations + 1;
        }

        /* ------- public known methods ------------------ */

        //comment in .h
        void setup() {
            pinMode(ARD_LINE_FINDER2, INPUT_PULLUP);
            attachInterrupt(ARD_LINE_FINDER2, &lineFinderInterrupt, RISING | FALLING);
            #ifdef CONSOLE
                CONSOLE.println("setup Ardlinfinder succesfull");
            #endif
        }

        //comment in .h
        int getSensorState() {
            return digitalRead(ARD_LINE_FINDER2); //ToDo: check if this is working!
        }

        //comment in .h
        int getSpeed() {
            return speed;
        }

        //comment in .h
        void calculateSpeed() {
            speed = lineFinderRoations;
            lineFinderRoations = 0;
        }

    }
    
}