#include "pins_arduino.h"
#include "Arduino.h"

uint32_t spiRx[10];
volatile int spiRxIdx;
volatile int spiRxComplete = 0;

#include "SPISlave_T4.h"
SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

void myFunc();

void setupCamera() {
  mySPI.begin();
  mySPI.onReceive(myFunc);
}

void runCamera() {
  //int i;

  Serial.print("millis: "); Serial.println(millis());
  /*if (spiRxComplete) {
    Serial.println(spiRxIdx);
    for (i = 0; i < spiRxIdx; i++) {
      Serial.print(spiRx[i], HEX); Serial.print(" ");
    }
    Serial.println();
    spiRxComplete = 0;
    spiRxIdx = 0;
    delay(500); 
  }*/
}

void myFunc() {
  Serial.println("START: ");
  uint8_t arr[] = { 3, 2, 8, 3, 10, 11, 33, 13, 14 };
  uint8_t i = 0;
  while ( mySPI.active() ) {
    if (mySPI.available()) {
      if ( i++ > sizeof(arr) ) i = 0;
      mySPI.pushr(arr[i]);
      Serial.print("VALUE: ");
      Serial.println(mySPI.popr());
    }
  }
  Serial.println("END");
}