#include "sensors/tofDistance.h"

#include <VL53L0X.h>

namespace Sensors {

    namespace TofDistance {
        
        VL53L0X tofSensor;

        //ToDo: Error Handling!
        void setup() {
            tofSensor.setTimeout(500);
            if(!tofSensor.init())
            {
                Serial.println("Error - TOF Sensor: failed to detect and initialize VL53L0X Sensor!");
            }
            tofSensor.startContinuous();
        }

        uint16_t getDistance() {
            //Error Handling!
            if (tofSensor.timeoutOccurred()) {
                Serial.print(" TIMEOUT VL53L0X sensor");
            }
            return tofSensor.readRangeContinuousMillimeters();
        }

        void printData() {
            Serial.print("ToF Distance: "); Serial.println(getDistance());
        }
    }
}