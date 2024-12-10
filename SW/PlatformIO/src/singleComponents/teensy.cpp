#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h>

namespace SingleComponent {
    void setupTeensyBlink() {
        pinMode(ON_BOARD_LED, OUTPUT);
    }
    /**
     * teensy test blink
     */
    void teensyBlink() {
        digitalWrite(ON_BOARD_LED, HIGH);
        delay(1000);
        digitalWrite(ON_BOARD_LED, LOW);
        delay(1000);   
    }
}
#endif