#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "Arduino.h"
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

        /*//ToDo: normal i2C
        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);
        */

        //ToDo: remove - avoid i2c IO-Expander
        engineEnabled = true;
        steeringEnabled = true;
        
        //Bluetooth Control - comment out in final run
        if(CONSOLE.available()) {
            CONSOLE.read();
            changeState = (changeState) ? false : true;
        }
        engineEnabled = (engineEnabled && changeState);

        if (CameraAnalysis::TrackCenterAnalysis::finishLineDetected && Sensors::usedData.tofDistance < DISTANCE_TO_STOP) {
            engineEnabled = false;
            steeringEnabled = false;
            CONSOLE.println("stop");
        }
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);
        showEnableStateOnLed(engineEnabled, steeringEnabled); //remove in final run
    }



    TimingControl::Task* t_updateLed;
    TimingControl::Task* t_updateDisplay;
    TimingControl::Task* t_calculateSpeed;
    TimingControl::Task* t_updateSensor;

    void defineTimedTasks () {

        /*t_updateLed = TimingControl::createTask([](TimingControl::Task* self) {
            //CONSOLE.println("every Second");
            //DataVisualization::LedStrip::update(); 
        }, 1000, true, true);*/

        
        /*t_updateDisplay = TimingControl::createTask([](TimingControl::Task* self) {
            DataVisualization::Display::update();
        }, 100, true, true);*/

        
        /*t_calculateSpeed = TimingControl::createTask([](TimingControl::Task* self) {
            Sensors::ArdLineFinder::calculateSpeed();
        }, 100, true, true);*/ 

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