#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "boardInput/boardInput.h"
#include "sensors/sensors.h"

namespace CarLogic {

    bool engineEnabled;
    bool steeringEnabled;

    void runCarLogic() {

        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);

        if (Sensors::rawData.tofDistance < 220) {
            engineEnabled = false;
        }
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);
    }

}
