#include "drivingControl/servo.h"

#include <Servo.h>
#include <Arduino.h>

#include "configuration/globalConfig.h"

//ToDo determine the correct values!
#define MAX_STEERING_ANGLE 130
#define MIN_STEERING_ANGLE 50


namespace DrivingControl {
    Servo libServo;

    void SteeringServo::setup() {
        libServo.attach(SERVO_PIN, 544, 2400);
        libServo.write(90);
    }

    void SteeringServo::setSteeringAngle(int steeringAngle) {
        steeringAngle = steeringAngle > MAX_STEERING_ANGLE ? MAX_STEERING_ANGLE : steeringAngle;
        steeringAngle = steeringAngle < MIN_STEERING_ANGLE ? MIN_STEERING_ANGLE : steeringAngle;
        //Serial.print("Servo Value: "); Serial.println( steeringAngle);
        libServo.write(steeringAngle);
    }
}