#include <Arduino.h>

#include "configuration/globalConfig.h"
#include "singleComponents/teensy.h"
#include "singleComponents/opticalFlow_PIM453.h"
#include "singleComponents/tofDistanceMeasure_VL53L0X.h"
#include "singleComponents/_ARD_LINEFINDER.h"
#include "singleComponents/servo_REELYS2210.h"
#include "singleComponents/motor_PICHLERBOOST18S.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupOpticalFlow();
  setupTofDistanceMeasure();
  setupArdLinefinder();
  setupServo();
  setupMotor();
  //pinMode(onBoardLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  runOpticalFlow();
  runTofDistanceMeasure();
  runArdLineFinder();
  runServo();
  runMotor();
  //teensyBlink();
  //Serial.println("Loop");
} 