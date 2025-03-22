#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "configuration/drivingConfig.h"
#include "carLogic/carLogic.h"
#include "drivingControl/drivingControl.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/trackCenterAnalysis.h"
#include "boardInput/boardInput.h"
#include "sensors/sensors.h"
#include "dataVisualization/display.h"
#include "dataVisualization/ledStrip.h"
#include "timingControl/timingControl.h"

namespace CarLogic {

    bool engineEnabled;
    bool steeringEnabled;

    bool changeState = false;

    //pre decleration
    void showEnableStateOnLed(bool engineEnabled, bool steeringEnabled);

    void runCarLogic() {

        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);

        //start and stop Wireles.
        if(CONSOLE.available()) {
            CONSOLE.read();
            changeState = (changeState) ? false : true;
        }
        engineEnabled = (engineEnabled && changeState);

        //DataVisualization::Display::showNumber(20);
        //DataVisualization::LedStrip::showNumberInRange(200, 32);

        if (Sensors::rawData.tofDistance < DISTANCE_TO_STOP) {
            engineEnabled = false;
        }
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        //CONSOLE.print(speed); CONSOLE.println(steeringAngle);
        DrivingControl::drive(speed, steeringAngle);
        //showEnableStateOnLed(engineEnabled, steeringEnabled);
    }



    TimingControl::Task* t_updateLed;
    TimingControl::Task* t_updateDisplay;
    TimingControl::Task* t_calculateSpeed;

    void defineTimedTasks () {

        t_updateLed = TimingControl::createTask([](TimingControl::Task* self) {
            //CONSOLE.println("every Second");
            //DataVisualization::LedStrip::update(); 
        }, 1000, true, true);

        
        t_updateDisplay = TimingControl::createTask([](TimingControl::Task* self) {
            DataVisualization::Display::update();
        }, 100, true, true);

        
        t_calculateSpeed = TimingControl::createTask([](TimingControl::Task* self) {
            Sensors::ArdLineFinder::calculateSpeed();
        }, 150, true, true); 
    }


    /* ------- privat - public unknown methods ------- */

    /**
     * method to show the car state to the leds!
     * @param engineEnabled: engine state
     * @param steeringEnabled: steering state
     */
    void showEnableStateOnLed(bool engineEnabled, bool steeringEnabled) {
        
        DataVisualization::LedStrip::clear();
        
        if(engineEnabled) {
            DataVisualization::LedStrip::setLeds(128, 0, 255, 0);
        }
        else {
            DataVisualization::LedStrip::setLeds(128, 255, 0, 0);
        }
        if(steeringEnabled) {
            DataVisualization::LedStrip::setLeds(64, 0, 255, 0);
        }
        else {
            DataVisualization::LedStrip::setLeds(64, 255, 0, 0);
        }
    }

}
#endif