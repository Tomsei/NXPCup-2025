
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

int count;

void onInterrupt() {
  count++;
}

void setup() {
  #ifdef CONSOLE
    CONSOLE.begin(115200);
  #endif
  delay(1000);

  Wire.begin(); //later in I2C Modul //ToDo Input Pullup auf den I2C Pinnen

  DataVisualization::setup();
  CONSOLE.print("Vor kamera");
  CameraAnalysis::setup();
  BoardInput::setup();
  DrivingControl::setup();
  //Sensors::setup();
  TimingControl::setup();
  CarLogic::defineTimedTasks();

  #ifdef CONSOLE
    CONSOLE.println("Main | Setup Done!");
  #endif
}

void loop() {
  BoardInput::update();
  //Sensors::updateUsedData();
  CameraAnalysis::analyse(BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S2));
  CameraAnalysis::analyse(0);
  CarLogic::runCarLogic();
  TimingControl::runTasks();
  
  //Sensors::printData();
  //CONSOLE.println(micros());
}