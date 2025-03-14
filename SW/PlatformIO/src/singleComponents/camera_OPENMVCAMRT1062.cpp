/**
 * Single component - camera definition
 * 
 * Basic code to test the function of the spi connection to the camera
 * The script "Control_Engine_Accespoint" should run on the openMV cam 
 * to control the global engine state via spi data
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

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include <SPI.h>

#include "SPISlave_T4.h"

volatile int spiBufferIdx = 0;
volatile int spiTransferComplete = 0;
volatile int imageAnalysIsComplete = 1; // just to make it able to run (needed for the real implementation)

uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];

uint32_t* spiBufferToRead = spiBackBuffer;

extern bool globalEngineState;


namespace SingleComponent {

  SPISlave_T4<&SPI, SPI_8_BITS> mySPI;
  uint8_t lastTimeDiff;

  /**
   * setup method to enable slave spi communication
   */
  void setupCamera() {
    mySPI.begin();
    mySPI.swapPins(true);
    pinMode(CAM_SPI_MISO, OUTPUT); //important!
    CONSOLE.println("cam started");
  }

  /**
   * method to call in loop to print the transfered spi data
   */
  void runCamera() {
    //reading SPI when transfer is finished!
    if(spiTransferComplete){
      //calculate time difference
      static uint32_t last = 0;
      lastTimeDiff = millis()-last;
      last = millis();
      //print the transfered values
      for(int i = 0; i < 10; i++){
        //print values that were sent
        CONSOLE.print("\t"); CONSOLE.print(spiBufferToRead[i], DEC);
      }
      //amount of values and time difference
      CONSOLE.print("\t"); CONSOLE.print(spiBufferIdx);
      CONSOLE.print("\t"); CONSOLE.println(lastTimeDiff);
      globalEngineState = spiBufferToRead[0];
      //reset 
      spiTransferComplete = false;
      spiBufferIdx = 0;
    }
  }
}
#endif