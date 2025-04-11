/**
 * camera - definitions
 * 
 * Handles everything belonging to the Camera SPI Connection. 
 * This includes the administration of the SPI Buffer 
 * and the setup and use of the spi transfer where Teensy is a slave
 * 
 * using the library: SPISlave_T4.h
 * https://github.com/tonton81/SPISlave_T4
 * 
 * inspiration for library improvments from Tjaekel: 
 * https://forum.pjrc.com/index.php?threads/teensy-4-1-spi-slave-here-it-is.72792/
 * https://github.com/tjaekel/Teesny_4_1
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#include <Arduino.h>
#include "SPISlave_T4.h"

#include "cameraAnalysis/camera.h"



//SPI transfer variables and buffer
volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;
volatile int imageAnalysIsComplete = 1;

uint32_t spiBuffer[SPI_BUFFER_SIZE];

namespace CameraAnalysis {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

  //comment in .h
  void OpenMVCam::setup() {
    mySPI.begin();
    mySPI.swapPins(true);
    pinMode(CAM_SPI_MISO, OUTPUT);

  }

  //comment in .h
  void OpenMVCam::updateImage() {

    //reading SPI-data when transfer is finished!
    if(spiTransferComplete){
  
      //print the first 10 transfered values
      for(int i = 0; i < 10; i++){
        //print values that were sent
        Serial.print("\t"); Serial.print(spiBuffer[i], DEC);
      }
      //amount of values
      Serial.print("\t"); Serial.println(spiBufferIdx);

      //reset spi
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
} 
