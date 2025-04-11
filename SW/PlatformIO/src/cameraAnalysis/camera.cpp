/**
 * camera - definitions
 * 
 * Handles everything belonging to the Camera SPI Connection. 
 * This includes the administration of the Swapped SPI Buffer 
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
#ifndef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include "SPISlave_T4.h"

#include "cameraAnalysis/camera.h"
#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/imageAnalysis.h"
#include "cameraAnalysis/trackCenterAnalysis.h"


//SPI transfer variables and buffers for swapped Buffer implementation
volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;
volatile int imageAnalysIsComplete = 1;

#ifndef ANALYSIS_ON_CAMERA
uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
#endif

#ifdef ANALYSIS_ON_CAMERA
uint32_t spiFrontBuffer[SPI_BUFFER_WIDTH];
uint32_t spiBackBuffer[SPI_BUFFER_WIDTH];
#endif

uint32_t* spiBufferToRead = spiBackBuffer;



namespace CameraAnalysis {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;


  #ifndef ANALYSIS_ON_CAMERA
  extern ImageAnalysis currentImageAnalysis;
  #endif

  #ifdef ANALYSIS_ON_CAMERA
  extern TrackCenterAnalysis currentTrackCenterAnalysis;
  #endif

  /* ------- public known methods ------------------ */

  //comment in .h
  void OpenMVCam::setup() {
    mySPI.begin();
    mySPI.swapPins(true);
    pinMode(CAM_SPI_MISO, OUTPUT); 

    #ifdef ANALYSIS_ON_CAMERA
      currentTrackCenterAnalysis.updateTrackCenters(spiBufferToRead);
    #endif

    #ifdef CONSOLE
      CONSOLE.println("camera setup done");
    #endif
  }


  
  #ifndef ANALYSIS_ON_CAMERA
  
  //comment in .h
  void OpenMVCam::updateImage() {

    //reading SPI-data when transfer is finished!
    if(spiTransferComplete){
      
      //just updating image if analysis is finished (otherwise skip the frame)
      if(imageAnalysIsComplete) {
        imageAnalysIsComplete = 0;
        currentImageAnalysis.updateImage(spiBufferToRead);
      }
      //reset spi (start getting the new data)
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
  #endif

  #ifdef ANALYSIS_ON_CAMERA //todo change!

  //coment in .h
  void OpenMVCam::updateTrackCenters() {
    //reading SPI-data when transfer is finished!
    if(spiTransferComplete){

      //just updating image if analysis is finished (otherwise skip the frame)
      if(imageAnalysIsComplete) {
        imageAnalysIsComplete = 0;
        currentTrackCenterAnalysis.updateTrackCenters(spiBufferToRead);
      }
      //reset spi (start getting the new data)
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
  #endif

} 
#endif