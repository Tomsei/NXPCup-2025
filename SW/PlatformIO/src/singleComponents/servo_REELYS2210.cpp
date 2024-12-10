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
     * method to call in loop to control the steering angle of the servo
     */
    void runServo() {
    servo.write(130);
    }

    /* ToDo: just testing - better way needed!*/
    void servoSteering(int value) {
        if(value > 130)
            value = 130;
        if(value < 50)
            value = 50;
        servo.write(value);
    }
}


#endif