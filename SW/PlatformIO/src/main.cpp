#include <Arduino.h>
#include <Wire.h>

#include "configuration/globalConfig.h"
#include "singleComponents/teensy.h"
#include "singleComponents/opticalFlow_PIM453.h"
#include "singleComponents/tofDistanceMeasure_VL53L0X.h"
#include "singleComponents/_ARD_LINEFINDER.h"
#include "singleComponents/servo_REELYS2210.h"
#include "singleComponents/motor_PICHLERBOOST18S.h"
#include "singleComponents/imu_SEN0142.h"
#include "singleComponents/camera_OPENMVCAMRT1062.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul
  //setupOpticalFlow();
  //setupTofDistanceMeasure();
  //setupArdLinefinder();
  //setupImu();
  //setupServo();
  //setupMotor();
  
  setupCamera();
  //pinMode(onBoardLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //runOpticalFlow();
  //runTofDistanceMeasure();
  //runArdLineFinder();
  //runImu();
  //runServo();
  //runMotor();
  runCamera();
  //teensyBlink();
  //Serial.println("Loop");
} 