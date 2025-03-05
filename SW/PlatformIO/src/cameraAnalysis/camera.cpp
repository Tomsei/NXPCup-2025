/**
 * camera - definitions
 * 
 * Handles everything belonging to the Camera SPI Connection. 
 * This includes the administration of the Swapped SPI Buffer 
 * and the setup and use of the spi transfer where Teensy is a slave
 * 
 * using the Library: SPISlave_T4.h
 * https://github.com/tonton81/SPISlave_T4
 * 
 * inspiration for improvments from Tjaekel: 
 * https://forum.pjrc.com/index.php?threads/teensy-4-1-spi-slave-here-it-is.72792/
 * https://github.com/tjaekel/Teesny_4_1
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include "SPISlave_T4.h"

#include "cameraAnalysis/camera.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/imageAnalysis.h"


//SPI Transfer variables and buffers for swapped Buffer implementation
volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;

uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];

uint32_t* spiBufferToRead = spiBackBuffer;



namespace CameraAnalysis {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;

  extern ImageAnalysis currentImageAnalysis;


  /* ------- public known methods ------------------ */

  //comment in .h
  void OpenMVCam::setup() {
    mySPI.begin();
    mySPI.swapPins(true);
    pinMode(CAM_SPI_MISO, OUTPUT); //important!
    #ifdef CONSOLE
      CONSOLE.print("camera setup done");
    #endif
  }

  //comment in .h
  void OpenMVCam::updateImage() {

    //reading SPI-data when transfer is finished!
    if(spiTransferComplete){
      currentImageAnalysis.updateImage(spiBufferToRead);
      //reset spi transfer //ToDo: das hier ist zu früh!! hier muss gewartet werden, bis das Bild analysiert wurde
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
} 
#endif