/**
 * carlogic - definition
 * 
 * entry point for general car logic
 * could be the interface of all sub modules which can bring erverything together
 * 
 * @author Tom Seiffert
 */
#include "Arduino.h"
#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"

namespace CarLogic {

    //comment in .h
    void runCarLogic() {

        uint8_t speed = 15;
        int steeringAngle = 70;
        DrivingControl::drive(speed, steeringAngle);
    }
}