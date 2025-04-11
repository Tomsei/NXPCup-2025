/**
 * general main file with setup and loop
 * calls the required methods of the implemented modules
 */
#include <Arduino.h>
#include <Wire.h>

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