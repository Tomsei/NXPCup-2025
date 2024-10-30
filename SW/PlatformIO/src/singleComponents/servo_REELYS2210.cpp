#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo servo;
bool left;

void setupServo() {
    servo.attach(servoPin, 544, 2400);
}

void runServo() {
    /*if(true || (millis() % 5000) > 2500) {
        servo.write(45);
    } else {
        servo.write(130);
    } */
   servo.write(90);
    
}