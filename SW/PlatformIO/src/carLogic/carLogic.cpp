#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"
#include "cameraAnalysis/cameraAnalysis.h"

namespace CarLogic {

    void runCarLogic() {
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);
    }

}
