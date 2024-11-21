# Single Components
Jeglicher Quellcode dieses Ordners ist lediglich zum austesten der Einzelkomponenten und wird nicht in der finalen Software verwendet.

Dieser Ordner und alle Dateien die dieser beinhaltet sind Basistests der Komponenten, ohne weitere Struktur in der Programmierung. Er dient zum verifizieren, dass alle Komponenten **gleichzeitig** funktionsfähig und ansteuerbar sind.  

Auf der Kamera sollte das Script: ```Control_Engine_Accespoint``` ausgeführt werden. Somit kann auch die SPI Verbindung verifiziert werden, in dem das Steuersignal weitergeleitet wird.

In der Main Datei sollte folgender Quellcode ausgeführt werden:
```c++
#include <Arduino.h>
#include <Wire.h>

#include "singleComponents/teensy.h"
#include "singleComponents/opticalFlow_PIM453.h"
#include "singleComponents/tofDistanceMeasure_VL53L0X.h"
#include "singleComponents/irObstacleDetection_ARD_LINEFINDER.h"
#include "singleComponents/servo_REELYS2210.h"
#include "singleComponents/motor_PICHLERBOOST18S.h"
#include "singleComponents/imu_SEN0142.h"
#include "singleComponents/camera_OPENMVCAMRT1062.h"
#include "singleComponents/display_CS-ANAVI-DISPLAY1.h"
#include "singleComponents/io_expander_MCP23017.h"
#include "singleComponents/poti.h"

//Just testing variable for engine control
extern bool globalEngineState;


void setup() {
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul
  setupOpticalFlow();
  setupTofDistanceMeasure();
  setupArdLinefinder();
  setupImu();
  setupServo();
  setupMotor();
  setupCamera();
  setupDisplay();
  setupIoExpander();  
  //void setupTeensyBlink();

  //just testing variable for engine control
  globalEngineState = false;
}

void loop() {
  runOpticalFlow();
  runTofDistanceMeasure();
  runArdLineFinder();
  runImu();
  runServo();
  runMotor(globalEngineState);
  runCamera();
  runDisplay(globalEngineState);
  runIoExpander();
  runPoti();
  //teensyBlink();
} 
```