#include "sensors/sensors.h"

#include "sensors/tofDistance.h"

namespace Sensors {
    void setup() {
        TofDistance::setup();
    }

    void printData() {
        Serial.print("ToF Distance: "); Serial.print(TofDistance::getDistance());
        //Serial.print("Optical Flow - X:"); Serial.print(TofDistance::getDistance()); 
        Serial.println("");
    }
}