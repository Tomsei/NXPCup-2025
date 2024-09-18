#include <Arduino.h>

#include "configuration/globalConfig.h"
#include "singleComponents/teensy.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(onBoardLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  teensyBlink();
  Serial.println("Loop");
} 