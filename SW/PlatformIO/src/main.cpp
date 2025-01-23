
#include <Arduino.h>
#include <Wire.h>

#include "cameraAnalysis/cameraAnalysis.h"

#include "dataVisualisation/dataVisualisation.h"
#include "boardInput/boardInput.h"
#include "drivingControl/drivingControl.h"
#include "sensors/sensors.h"

#include "carLogic/carLogic.h"

void setup() {

  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul

  DataVisualisation::setup();
  CameraAnalysis::setup();
  BoardInput::setup();
  DrivingControl::setup();
  Sensors::setup();
  
}

void loop() {

  BoardInput::update();
  Sensors::updateRawData();
  CameraAnalysis::OpenMVCam::updateImage();
  CameraAnalysis::analyse();
  Sensors::printData();



  CarLogic::runCarLogic();

}