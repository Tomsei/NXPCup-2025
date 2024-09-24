#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo servo;
bool left;

void setupServo() {
    servo.attach(servoPin);
}

void runServo() {
    if(millis() % 5000 == 0) {
        if(left) {
            servo.write(45);
            left = false;
        } else {
            servo.write(180);
            left = true;
        }
    }
}