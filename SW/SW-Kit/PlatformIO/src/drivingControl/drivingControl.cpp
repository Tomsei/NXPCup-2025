/**
 * driving control - definition
 * 
 * handels everything to control the car driving. 
 * This includes functions to setup engine and servo and
 * the general control of them to drive correctly.
 * 
 * @author Tom Seiffert
 */
#include "drivingControl/drivingControl.h"
#include "drivingControl/engine.h"
#include "drivingControl/servo.h"
#include "carLogic/carLogic.h"

namespace DrivingControl {
    
    /* ------- public known methods ------------------ */

    //comment in .h file
    void setup() {
        SteeringServo::setup();
        Engine::setup();
    }

    //comment in .h file
    void drive(uint8_t speed, int steeringAngle) {
            Engine::setSpeed(speed);
            SteeringServo::setSteeringAngle(steeringAngle);
    }
}