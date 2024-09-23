#include <Arduino.h>

#include "configuration/globalConfig.h"
#include "singleComponents/teensy.h"
#include "singleComponents/opticalFlow_PIM453.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupOpticalFlow();
  
  //pinMode(onBoardLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  runOpticalFlow();
  //teensyBlink();
  //Serial.println("Loop");
} 