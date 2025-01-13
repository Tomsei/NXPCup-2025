#include <Arduino.h>
#include <SPI.h>
#include <pins_arduino.h>

#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysis.h"

volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;

uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];

uint32_t* spiBufferToRead = spiBackBuffer;

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
    if(spiTransferComplete){

      //calculate time difference
      static uint32_t last = 0;
      lastTimeDiff = millis()-last;
      last = millis();
      
      //print the transfered values
      
      /*
      Serial.print("Loop\t");
      for(int i = 0; i < 20; i++){
        //print values that were sent
        Serial.print("\t"); Serial.print(spiFrontBuffer[i], DEC);
      }  
      //amount of values and time difference
      Serial.print("\t"); Serial.print(spiBufferIdx);
      Serial.print("\t"); Serial.println(lastTimeDiff);
      */

      static CameraAnalysis::ImageAnalysis currentImageAnalysis;
      currentImageAnalysis.updateImage(spiBufferToRead);

      
      //reset spi transfer
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
} 