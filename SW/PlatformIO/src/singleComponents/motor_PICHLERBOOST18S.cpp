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
    if((millis() % 5000) > 2500) {
        
        ESC.write(27);
    }
    else {
        ESC.write(17);
    }
    
}

void calibrateMotor() {
    ESC.write(180);
    delay(2000);
    ESC.write(0);
}