#include "sensors/lineFinder.h"

namespace Sensors {

    LineFinder::LineFinder(uint8_t pin) {
        this->pin = pin;
        pinMode(pin, INPUT);
    }

    uint8_t LineFinder::getCurrentState() {
        return digitalRead(pin);
    }

    // uint8_t LineFinder::getPastTransistions() {
    //     //ToDo: Implement!
    //     return 0;
    // }
}