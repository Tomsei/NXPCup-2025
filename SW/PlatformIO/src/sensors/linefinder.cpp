/**
 * LineFinder - definition
 * 
 * using the LineFinder Class to controll the lin finder sensors. 
 * This includes functions for setup and getting data
 * 
 * @todo Implement interrupt for sensor - check other sensor for direction
 * 
 * @author Tom Seiffert
 */
#include "sensors/lineFinder.h"

namespace Sensors {

    /* ------- public known methods ------------------ */

    //comment in .h file
    LineFinder::LineFinder(uint8_t pin) {
        this->pin = pin;
        pinMode(pin, INPUT);
    }

    //comment in .h file
    uint8_t LineFinder::getCurrentState() {
        return digitalRead(pin);
    }

    // uint8_t LineFinder::getPastTransistions() {
    //     //ToDo: Implement!
    //     return 0;
    // }
}