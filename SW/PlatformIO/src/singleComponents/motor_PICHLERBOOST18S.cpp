#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo ESC;
bool nextShouldBeFast = false;

void setupMotor() {
    ESC.attach(motorPin, 1000, 2000); //min pulse width, max pulse width
    ESC.write(0);
    delay(5000); 
}

void runMotor() {
    if(((millis() % 10000) > 2500) && ((millis() % 10000) < 7500)) {
        ESC.write(20);
    }
    else if((millis() % 10000) < 2500) {
        ESC.write(15);
    }
    else {
        ESC.write(0);
    }
}