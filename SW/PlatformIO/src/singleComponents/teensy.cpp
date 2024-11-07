#include <Arduino.h>

#include "configuration/globalConfig.h"

void setupTeensyBlink() {
    pinMode(onBoardLed, OUTPUT);
}
/**
 * teensy test blink
 */
void teensyBlink() {
    digitalWrite(onBoardLed, HIGH);
    delay(1000);
    digitalWrite(onBoardLed, LOW);
    delay(1000);
    
}