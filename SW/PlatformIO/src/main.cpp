
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

#include "cameraAnalysis/camera_OPENMVCAMRT1062.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

//Just testing variable for engine control
//extern bool globalEngineState;


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul
  
  setupCamera();
  setupMotor();

  /*
  setupOpticalFlow();
  setupTofDistanceMeasure();
  setupArdLinefinder();
  setupImu();
  setupServo();
  setupMotor();
  setupDisplay();
  setupIoExpander();  
  */
  //void setupTeensyBlink();

  //Just testing variable
  //globalEngineState = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  runCamera();
  //static CameraAnalysis::SingleRowAnalysis currentRowAnalysis;
  //currentRowAnalysis.printImageRow(0, 30);

  /*
  runTofDistanceMeasure();
  runArdLineFinder();
  runImu();
  runServo();
  runMotor(globalEngineState);
  runCamera();
  runDisplay(globalEngineState);
  runIoExpander();
  runPoti();
  */
  //teensyBlink();
} 

