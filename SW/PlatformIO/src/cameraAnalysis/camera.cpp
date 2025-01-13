#include <Arduino.h>
#include "SPISlave_T4.h"

#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysis.h"

//SPI Transfer variables and buffers
volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;

uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];

uint32_t* spiBufferToRead = spiBackBuffer;


namespace CameraAnalysis {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

  uint8_t lastTimeDiff;

  extern ImageAnalysis currentImageAnalysis;

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
  void OpenMVCam::updateImage() {
    //reading SPI when transfer is finished!
    if(spiTransferComplete){
      
      currentImageAnalysis.updateImage(spiBufferToRead);
    
      //reset spi transfer
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
} 