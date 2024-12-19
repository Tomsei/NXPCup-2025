
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

//Just testing variable for engine control
bool globalEngineState;


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul

  //setupCamera(); //ToDo: structure


  BoardInput::setup();
  DataVisualisation::setup();
  

  //Single Component - 
  SingleComponent::setupOpticalFlow();
  SingleComponent::setupTofDistanceMeasure();
  SingleComponent::setupArdLinefinder();
  SingleComponent::setupImu();
  //SingleComponent::setupServo();
  SingleComponent::setupMotor();
  
  //SingleComponent::setupDisplay();
  //SingleComponent::setupLedStrip();
  //SingleComponent::setupCamera();
  //SingleComponent::setupIoExpander();
  
  

  //Just testing variable
  globalEngineState = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  //runCamera();
  SingleComponent::runOpticalFlow();
  SingleComponent::runTofDistanceMeasure();
  //SingleComponent::runArdLineFinder();
  SingleComponent::runImu();
  //SingleComponent::runMotor();
  



  //DataVisualisation::LedStrip::clear();
  //DataVisualisation::Display::clear();

  BoardInput::update();
  BoardInput::printData();
  DataVisualisation::LedStrip::showNumber();
  DataVisualisation::Display::showNumber();


  //SingleComponent::runCamera();
  //SingleComponent::runServo();
  //SingleComponent::runPoti();
  //SingleComponent::runLedStrip();
  //SingleComponent::runDisplay();
  //SingleComponent::runIoExpander();
} 