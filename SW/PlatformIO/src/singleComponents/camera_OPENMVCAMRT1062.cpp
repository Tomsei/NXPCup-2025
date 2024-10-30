#include "pins_arduino.h"
#include "Arduino.h"
#include <SPI.h>


#include "SPISlave_T4.h"
SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

uint32_t spiRx[20480*3];
volatile int spiRxIdx = 0;
volatile int spiRxComplete = 0;

uint8_t lastTimeDiff;

void setupCamera() {
  mySPI.begin();
  Serial.print("Kamera gestartet");
  //mySPI.onReceive(myFunc);
  mySPI.swapPins(true);
  pinMode(12,OUTPUT);
}

void runCamera() {
  if(spiRxComplete){
    static uint32_t last = 0;
    lastTimeDiff = millis()-last;
    last = millis();
    for(int i = 0; i < 10; i++){
      Serial.print("\t"); Serial.print(spiRx[i], DEC);
    }
    Serial.print("\t"); Serial.print(spiRxIdx);
    Serial.print("\t"); Serial.println(lastTimeDiff);
    spiRxComplete = false;
    spiRxIdx = 0;
  }
}