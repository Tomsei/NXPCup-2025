#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "boardInput/boardInput.h"

namespace CarLogic {

    bool engineEnabled;
    bool steeringEnabled;

    void runCarLogic() {

        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);

        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);
    }

}
