#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo servo;
bool left;

/**
 * setup the servo
 */
void setupServo() {
    servo.attach(servoPin, 544, 2400);
}

/**
 * method to call in loop to control the steering angle of the servo
 */
void runServo() {

   servo.write(130);

    /* change servo angle over time
    if(true || (millis() % 5000) > 2500) {
        servo.write(45);
    } else {
        servo.write(130);
    } */

}