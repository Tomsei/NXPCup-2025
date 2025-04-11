
#include <Arduino.h>
#include <Wire.h>

#include "configuration/globalConfig.h"

#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/trackCenterAnalysis.h"
#include "dataVisualization/dataVisualization.h"
#include "boardInput/boardInput.h"
#include "drivingControl/drivingControl.h"
#include "sensors/sensors.h"
#include "carLogic/carLogic.h"
#include "timingControl/timingControl.h"

void checkingForErrors(); //ToDo: Just to Debug

bool setupSensor = true;

/**
 * setup the program
 * call all specific setups for the components
 */
void setup() {
  #ifdef CONSOLE
    CONSOLE.begin(115200);
  #endif
  delay(1000);

  Wire.begin();
  Wire1.begin();
  
  //remove when using IO-Expander - avoid i2c IO-Expander
  pinMode(DIPSWITSCH1, INPUT_PULLUP);
  pinMode(DIPSWITSCH2, INPUT_PULLUP);
  pinMode(DIPSWITSCH3, INPUT_PULLUP);
  pinMode(DIPSWITSCH4, INPUT_PULLUP);

  DataVisualization::setup();
  CameraAnalysis::setup();
  BoardInput::setup();
  DrivingControl::setup();
  TimingControl::setup();
  CarLogic::defineTimedTasks();
  Sensors::setup();

  DataVisualization::Display::showsetupDone();
  #ifdef CONSOLE
    CONSOLE.println("Main | Setup Done!");
  #endif
}

/**
 * while loop of the programm
 * runs the program endless to control the car through
 * updating and analysing data and controling the car.
 * 
 * it also checks if there are Timeed tasks to run
 */
void loop() {
  BoardInput::update();
  CameraAnalysis::analyse(true);
  CarLogic::runCarLogic();
  TimingControl::runTasks();
  

  //ToF sensor just every 30 ms and when finishline is detected
  if(CameraAnalysis::TrackCenterAnalysis::finishLineDetected) {

    if (setupSensor) {
      setupSensor = false;

      TimingControl::createTask([](TimingControl::Task* self) {
        Sensors::updateUsedData();
      }, 30, true, true);

    }
  }
}