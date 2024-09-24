#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo ESC;
bool nextShouldBeFast = false;

void setupMotor() {
    ESC.attach(motorPin, 1000, 2000); //min pulse width, max pulse width
}

void runMotor() {
    if(millis() % 5000 == 0) {
        if(nextShouldBeFast) {
            ESC.write(15);
            nextShouldBeFast = false;
        } else {
            ESC.write(12);
            nextShouldBeFast = true;
        }
    }
}

void calibrateMotor() {
    ESC.write(180);
    delay(2000);
    ESC.write(0);
}