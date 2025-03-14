/**
 * Single component - servo definition
 * 
 * Basic code to test the function of the servo
 * Control the pwm signal to control the servo
 * 
 * using the Library: Servo (Arduino)
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h> 
#include <Servo.h>

namespace SingleComponent {
    Servo servo;

    /**
     * setup the servo
     */
    void setupServo() {
        servo.attach(SERVO_PIN, 544, 2400);
    }

    /**
     * test control of the steering angle of the servo
     * change it permanently from left to right 
     */
    void runServo() {
        if((millis() % 10000) > 5000) {
            servo.write(130);
        } else {
            servo.write(50);
        }
    }
}
#endif