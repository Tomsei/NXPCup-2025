
#include <Arduino.h>
#include <Wire.h>

#include "configuration/globalConfig.h"

#include "cameraAnalysis/cameraAnalysis.h"
#include "cameraAnalysis/trackCenterAnalysis.h"
#include "dataVisualisation/dataVisualisation.h"
#include "boardInput/boardInput.h"
#include "drivingControl/drivingControl.h"
#include "sensors/sensors.h"

#include "carLogic/carLogic.h"

void checkingForErrors(); //ToDo: Just to Debug

int count;

void onInterrupt() {
  count++;
}

void setup() {
  #ifdef CONSOLE
    CONSOLE.begin(115200);
  #endif
  delay(1000);

  Wire.begin(); //later in I2C Modul

  //ToDo Debugging - reomve later
  checkingForErrors();

  DataVisualisation::setup();
  CameraAnalysis::setup();
  BoardInput::setup();
  DrivingControl::setup();
  Sensors::setup();
  
  //pinMode(3, INPUT_PULLUP);
  //attachInterrupt(3, &onInterrupt, RISING | FALLING);

  #ifdef CONSOLE
    CONSOLE.println("Main | Setup Done!");
  #endif
}

void loop() {
  BoardInput::update();

  Sensors::updateRawData();
  CameraAnalysis::analyse();
  //Sensors::printData();
  CarLogic::runCarLogic();
 //CONSOLE.println("loop");
}





void checkingForErrors() {
  /*Check the last restart reason*/
  CONSOLE.println();
  CONSOLE.print("SCR_SRSR: ");
  CONSOLE.println(SRC_SRSR);

  if (SRC_SRSR & (1 << 8)) {       
    CONSOLE.println("Cause of Reset = Over Temperature" );
  }
  else if (SRC_SRSR & (1 << 7)) {   
    CONSOLE.println("Cause of Reset = Watchdog Reset" );
  }
  else if (SRC_SRSR & (1 << 6)) {    
    CONSOLE.println("Cause of Reset = JTag-SW Reset" );
  }
  else if (SRC_SRSR & (1 << 5)) {    
    CONSOLE.println("Cause of Reset = JTag-HW Reset" );
  }
  else if (SRC_SRSR & (1 << 4)) {    
    CONSOLE.println("Cause of Reset = Watchdog Reset" );
  }
  else if (SRC_SRSR & (1 << 3)) {    
    CONSOLE.println("Cause of Reset = User Reset" );
  } 
  else if (SRC_SRSR & (1 << 2)) {    
    CONSOLE.println("Cause of Reset = CSU Reset (ggf. Brown Out)" );
  } 
  else if (SRC_SRSR & (1 << 1)) {    
    CONSOLE.println("Cause of Reset = Lock Up" );
  } 
  else if (SRC_SRSR & (1 << 0)) {    
    CONSOLE.println("Cause of Reset = Power Up Sequenz" );
  }

  if(SRC_SRSR != 1) {
    while(CONSOLE.available()) CONSOLE.read();
    while (1)
    {
      CONSOLE.println(SRC_SRSR);
      if(CONSOLE.available()) {
        break;
      }
      delay(100);
    }
  }
  
  CONSOLE.flush();
}

void createError() {
  /*int tetsArray[2];
  CONSOLE.print(tetsArray[400]);
  tetsArray[600] = 6;*/
  return;
}