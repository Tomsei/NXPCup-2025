#include "Arduino.h"
#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"

namespace CarLogic {

    void runCarLogic() {

        uint8_t speed = 15;
        int steeringAngle = 70;
        DrivingControl::drive(speed, steeringAngle);
    }
}