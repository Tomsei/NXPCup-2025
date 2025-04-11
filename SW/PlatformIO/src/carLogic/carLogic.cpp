/**
 * car logic - definition
 * 
 * car logic is the mergin point of all other working ears (for example cameraAnalysis, drivingControl...)
 * it connect the different areas to each other and controls the driving Behaviour of the car (stop, driving...).
 * 
 * Main parts are:
 * - controling car state (engine run...)
 * - reading data (cameraAnalysis, sensors, boardinput)
 * - use the input data to decide behavior
 * - control car witch drivingControl and Data Vizualisation
 * 
 * @author Tom Seiffert
 */
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

        /* normal i2C implementation (comment out to avoid i2c IO-Expander)
        engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
        steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);
        */
       
        engineEnabled = true;
        steeringEnabled = true;
        
        //Bluetooth Control
        /*if(CONSOLE.available()) {
            CONSOLE.read();
            changeState = (changeState) ? false : true;
        }
        engineEnabled = (engineEnabled && changeState);*/

        if (CameraAnalysis::TrackCenterAnalysis::finishLineDetected && Sensors::usedData.tofDistance < DISTANCE_TO_STOP) {
            engineEnabled = false;
            steeringEnabled = false;
            CONSOLE.println("stop");
        }
        
        uint8_t speed = CameraAnalysis::getSpeed();
        int steeringAngle = CameraAnalysis::getSteeringAngle();
        DrivingControl::drive(speed, steeringAngle);
        //showEnableStateOnLed(engineEnabled, steeringEnabled);
    }

    // ------ Timing Control ------

    TimingControl::Task* t_updateLed;
    TimingControl::Task* t_updateDisplay;
    TimingControl::Task* t_calculateSpeed;
    TimingControl::Task* t_updateSensor;

    void defineTimedTasks () {

        t_updateLed = TimingControl::createTask([](TimingControl::Task* self) {

            DataVisualization::LedStrip::update(); 
        }, 1000, true, true);

        
        t_updateDisplay = TimingControl::createTask([](TimingControl::Task* self) {
            DataVisualization::Display::update();
        }, 100, true, true);

        
        t_calculateSpeed = TimingControl::createTask([](TimingControl::Task* self) {
            Sensors::ArdLineFinder::calculateSpeed();
        }, 100, true, true);

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