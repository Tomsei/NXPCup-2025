#include <Arduino.h>
#include <SPI.h>
#include <pins_arduino.h>

#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"

SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

uint32_t spiRx[20480*3];
volatile int spiRxIdx = 0;
volatile int spiRxComplete = 0;

//Just Testing Stuff (motor control)
bool globalEngineState;

uint8_t lastTimeDiff;

/**
 * setup method to enable slave spi communication
 */
void setupCamera() {
  mySPI.begin();
  mySPI.swapPins(true);
  pinMode(12,OUTPUT); //important!
  Serial.print("Kamera gestartet");
}

/**
 * method to call in loop to print the transfered spi data
 */
void runCamera() {
  //reading SPI when transfer is finished!
  if(spiRxComplete){
    //calculate time difference
    static uint32_t last = 0;
    lastTimeDiff = millis()-last;
    last = millis();
    //print the transfered values
    for(int i = 0; i < 10; i++){
      //print values that were sent
      Serial.print("\t"); Serial.print(spiRx[i], DEC);
    }
    //amount of values and time difference
    Serial.print("\t"); Serial.print(spiRxIdx);
    Serial.print("\t"); Serial.println(lastTimeDiff);
    globalEngineState = spiRx[0];
    //reset 
    spiRxComplete = false;
    spiRxIdx = 0;
  }
}