#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "configuration/drivingConfig.h"
#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "boardInput/boardInput.h"
#include "sensors/sensors.h"
#include "dataVisualisation/display.h"
#include "dataVisualisation/ledStrip.h"

namespace CarLogic {

    bool engineEnabled;
    bool steeringEnabled;

    //pre decleration
    void showEnableStateOnLed(bool engineEnabled, bool steeringEnabled);

    void runCarLogic() {

        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);

        //DataVisualisation::Display::showNumber(20);
        //DataVisualisation::LedStrip::showNumberInRange(200, 32);

        if (Sensors::rawData.tofDistance < DISTANCE_TO_STOP) {
            engineEnabled = false;
        }
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);

        showEnableStateOnLed(engineEnabled, steeringEnabled);
    }


    /* ------- privat - public unknown methods ------- */

    /**
     * method to show the car state to the leds!
     * @param engineEnabled: engine state
     * @param steeringEnabled: steering state
     */
    void showEnableStateOnLed(bool engineEnabled, bool steeringEnabled) {
        
        DataVisualisation::LedStrip::clear();
        
        if(engineEnabled) {
            DataVisualisation::LedStrip::setLeds(128, 0, 255, 0);
        }
        else {
            DataVisualisation::LedStrip::setLeds(128, 255, 0, 0);
        }
        if(steeringEnabled) {
            DataVisualisation::LedStrip::setLeds(64, 0, 255, 0);
        }
        else {
            DataVisualisation::LedStrip::setLeds(64, 255, 0, 0);
        }
        DataVisualisation::LedStrip::updateLeds(); //todo: remove to timing System
    }

}
#endif