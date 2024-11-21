#include <Arduino.h>
#include <SPI.h>
#include <pins_arduino.h>

#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"

#include "cameraAnalysis/cameraAnalysisMain.h"

SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

//uint32_t spiRx[19200];
uint32_t spiRx[76800];
volatile int spiRxIdx = 0;
volatile int spiRxComplete = 0;


uint8_t lastTimeDiff;

/**
 * setup method to enable slave spi communication
 */
void setupCamera() {
  mySPI.begin();
  mySPI.swapPins(true);
  pinMode(CAM_SPI_MISO, OUTPUT); //important!
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
    Serial.print("Loop\t");
    for(int i = 0; i < 30; i++){
      //print values that were sent
      Serial.print("\t"); Serial.print(spiRx[i], DEC);
    }
    //amount of values and time difference
    Serial.print("\t"); Serial.print(spiRxIdx);
    Serial.print("\t"); Serial.println(lastTimeDiff);

    //Testing print
    static CameraAnalysis::SingleRowAnalysis currentRowAnalysis;
    currentRowAnalysis.getImageRow();

    //reset 
    spiRxComplete = false;
    spiRxIdx = 0;
  }
}



void OpenMVCam::getImage(uint8_t row, uint8_t *pixelData) {
  
  if(spiRxComplete) {

    for(int i = 0; i < 320; i++) {
      *(pixelData+i) = spiRx[i];
    }

    spiRxComplete = false;
    spiRxIdx = 0;
  }

}

