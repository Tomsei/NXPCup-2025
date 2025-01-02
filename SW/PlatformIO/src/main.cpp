
#include <Arduino.h>
#include <Wire.h>

#include "singleComponents/teensy.h"
#include "singleComponents/opticalFlow_PIM453.h"
#include "singleComponents/tofDistanceMeasure_VL53L0X.h"
#include "singleComponents/irObstacleDetection_ARD_LINEFINDER.h"
#include "singleComponents/servo_REELYS2210.h"
#include "singleComponents/motor_PICHLERBOOST18S.h"
#include "singleComponents/imu_SEN0142.h"
#include "singleComponents/display_CS-ANAVI-DISPLAY1.h"
#include "singleComponents/io_expander_MCP23017.h"
#include "singleComponents/poti.h"
#include "singleComponents/ledStrip_Adafruit1426.h"


#include "cameraAnalysis/camera_OPENMVCAMRT1062.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

#include "dataVisualisation/dataVisualisation.h"
#include "boardInput/boardInput.h"
#include "drivingControl/drivingControl.h"
#include "sensors/sensors.h"


bool engineEnabled = false;
bool steeringEnabled = false;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul

  BoardInput::setup();
  DataVisualisation::setup();
  DrivingControl::setup();
  Sensors::setup();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  engineEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S4);
  steeringEnabled = BoardInput::getSingleDipswitchValue(BoardInput::DipSwitchEnum::S3);
  //engineEnabled = DipswitchValu > 7 ? true : false; //Tenary Operation

  BoardInput::update();
  //BoardInput::printData();
  
  DataVisualisation::LedStrip::showNumber();
  DataVisualisation::Display::showNumber(-2);
  DrivingControl::drive(20, 50);
  Sensors::updateRawData();
  Sensors::printData();
} 