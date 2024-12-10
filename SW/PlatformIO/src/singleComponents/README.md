# Single Components
Jeglicher Quellcode dieses Ordners ist lediglich zum austesten der Einzelkomponenten und wird nicht in der finalen Software verwendet.

Dieser Ordner und alle Dateien die dieser beinhaltet sind Basistests der Komponenten, ohne weitere Struktur in der Programmierung. Er dient zum verifizieren, dass alle Komponenten **gleichzeitig** funktionsfähig und ansteuerbar sind.  

Auf der Kamera sollte das Script: ```Control_Engine_Accespoint``` ausgeführt werden. Somit kann auch die SPI Verbindung verifiziert werden, in dem das Steuersignal weitergeleitet wird.

In der globalConfig.h muss folgende Definition stehen ```#define SINGLE_COMPONENTS_TEST ```

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
bool globalEngineState;


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //later in I2C Modul
  SingleComponent::setupOpticalFlow();
  SingleComponent::setupTofDistanceMeasure();
  SingleComponent::setupArdLinefinder();
  SingleComponent::setupImu();
  SingleComponent::setupServo();
  SingleComponent::setupMotor();
  SingleComponent::setupCamera();
  SingleComponent::setupDisplay();
  SingleComponent::setupIoExpander();  

  //Just testing variable
  globalEngineState = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  SingleComponent::runOpticalFlow();
  SingleComponent::runTofDistanceMeasure();
  SingleComponent::runArdLineFinder();
  SingleComponent::runImu();
  SingleComponent::runServo();
  SingleComponent::runMotor();
  SingleComponent::runCamera();
  SingleComponent::runDisplay();
  SingleComponent::runIoExpander();
  SingleComponent::runPoti();
} 
```