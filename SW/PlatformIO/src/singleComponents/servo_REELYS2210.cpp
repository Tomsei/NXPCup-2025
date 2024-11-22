#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo servo;

/**
 * setup the servo
 */
void setupServo() {
    servo.attach(SERVO_PIN, 544, 2400);
}

/**
 * method to call in loop to control the steering angle of the servo
 */
void runServo() {
   servo.write(90);
}

/* ToDo: just testing - better way needed!*/
void servoSteering(int value) {
    if(value > 130)
        value = 130;
    if(value < 50)
        value = 50;
    servo.write(value);
}