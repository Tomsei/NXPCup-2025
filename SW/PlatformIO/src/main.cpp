
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

void setup() {
  #ifdef CONSOLE
    CONSOLE.begin(115200);
  #endif
  delay(1000);

  Wire.begin();
  Wire1.begin();
  
  //ToDo: remove - avoid i2c IO-Expander
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

void loop() {
  BoardInput::update();
  CameraAnalysis::analyse(true);
  CarLogic::runCarLogic();
  TimingControl::runTasks();
  

  if(CameraAnalysis::TrackCenterAnalysis::finishLineDetected) {

    if (setupSensor) {
      setupSensor = false;

      TimingControl::createTask([](TimingControl::Task* self) {
        Sensors::updateUsedData();
      }, 30, true, true);

    }
    //Sensors::printData();
  }

  //Sensors::printData();
  //CONSOLE.println(micros());
}