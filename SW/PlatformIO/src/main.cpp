
#include <Arduino.h>
#include <Wire.h>

#include "cameraAnalysis/cameraAnalysis.h"

#include "dataVisualisation/dataVisualisation.h"
#include "boardInput/boardInput.h"
#include "drivingControl/drivingControl.h"
#include "sensors/sensors.h"

bool engineEnabled = false;
bool steeringEnabled = false;

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

  engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
  steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);

  BoardInput::update();
  //BoardInput::printData();
  
  DataVisualisation::LedStrip::showNumber(3);
  DataVisualisation::Display::showNumber(5);
  Sensors::updateRawData();
  //Sensors::printData();

  CameraAnalysis::OpenMVCam::updateImage();
  CameraAnalysis::analyse();

}