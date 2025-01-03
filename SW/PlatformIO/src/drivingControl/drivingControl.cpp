#include "drivingControl/drivingControl.h"
#include "drivingControl/engine.h"
#include "drivingControl/servo.h"

extern bool engineEnabled;
extern bool steeringEnabled;

namespace DrivingControl {

    void setup() {
        SteeringServo::setup();
        Engine::setup();
    }

    void drive(uint8_t speed, uint8_t steeringAngle) {
        if(engineEnabled) {
            Engine::setSpeed(speed);
        }
        else {
            Engine::setSpeed(0);
        }
        if(steeringEnabled) {
            SteeringServo::setSteeringAngle(steeringAngle);
        }
    }
}