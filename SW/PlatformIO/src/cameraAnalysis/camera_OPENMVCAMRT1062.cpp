#include <Arduino.h>
#include <SPI.h>
#include <pins_arduino.h>

#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysis.h"

uint32_t spiRx[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
volatile int spiRxIdx = 0;
volatile int spiRxComplete = 0;

uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
volatile int spiFrontBufferIdx = 0;
volatile int spiTransferComplete = 0;

namespace CameraAnalysis {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

  uint8_t lastTimeDiff;

  /**
   * setup method to enable slave spi communication
   */
  void OpenMVCam::setup() {
    mySPI.begin();
    mySPI.swapPins(true);
    pinMode(CAM_SPI_MISO, OUTPUT); //important!
    Serial.print("Kamera gestartet");
  }

  /**
   * method is called in loop to check if there is new spi data
   */
  void OpenMVCam::runCamera() {
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

      static CameraAnalysis::ImageAnalysis currentImageAnalysis;
      currentImageAnalysis.updateImage(spiRx);

      
      //reset spi transfer
      spiRxComplete = false;
      spiRxIdx = 0;
    }
  }