#include <Arduino.h>
#include <SPI.h>
#include <pins_arduino.h>

#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

uint32_t spiRx[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
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
    /*
    Serial.print("Loop\t");
    for(int i = 0; i < 30; i++){
      //print values that were sent
      Serial.print("\t"); Serial.print(spiRx[i], DEC);
    }  
    //amount of values and time difference
    Serial.print("\t"); Serial.print(spiRxIdx);
    Serial.print("\t"); Serial.println(lastTimeDiff);
    */
    //triger Analysis to get new Row | ToDo: find a better way!
    static CameraAnalysis::SingleRowAnalysis currentRowAnalysis;
    currentRowAnalysis.getRow();
    currentRowAnalysis.calculateSobelRow();

    //reset spi transfer
    spiRxComplete = false;
    spiRxIdx = 0;
  }
}

/**
 * method to provide an image
 * @param pixelData: pointe to the array to write the image data in
 */
void OpenMVCam::getImage(uint8_t *pixelData) {
  if(spiRxComplete) {
    //write each pixel 
    for(int i = 0; i < VIDEO_RESOLUTION_X*NUMBER_OF_LINES; i++) {
      *(pixelData+i) = spiRx[i];
    }
  }
}

/**
 * method to provide an image
 * @param pixelData: pointe to the array to write the image data in
 * @param row: the imagerow to get (start by index 0)
 */
void OpenMVCam::getImageRow(uint8_t *pixelData, uint8_t row) {
  if(spiRxComplete) {
    int startIndexOfLine = row * VIDEO_RESOLUTION_X;
    //write each pixel
    for(int i = startIndexOfLine; i < startIndexOfLine + VIDEO_RESOLUTION_X; i++) {
      *(pixelData+i - startIndexOfLine) = spiRx[i];
    }
  }
}