
#include <Arduino.h>
#include <Wire.h>

#include "configuration/globalConfig.h"

#include "drivingControl/drivingControl.h"
#include "carLogic/carLogic.h"
#include "cameraAnalysis/camera.h"



void setup() {

  Serial.begin(115200);

  DrivingControl::setup();
  CameraAnalysis::OpenMVCam::setup();

}

void loop() {

  CarLogic::runCarLogic();
  CameraAnalysis::OpenMVCam::updateImage();
}