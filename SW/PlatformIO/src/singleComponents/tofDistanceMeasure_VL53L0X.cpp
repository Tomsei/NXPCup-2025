//Source: https://github.com/pololu/vl53l0x-arduino

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setupTofDistanceMeasure() {

    Wire.begin(); 

    sensor.setTimeout(500);
    if (!sensor.init())
    {
        Serial.println("Failed to detect and initialize VL53L0X sensor!");
        while (1) {Serial.println("Failed to detect and initialize VL53L0X sensor!");}
    }
    sensor.startContinuous();
}

void runTofDistanceMeasure() {
    int distance = sensor.readRangeContinuousMillimeters();
    if (sensor.timeoutOccurred()) {
        Serial.print(" TIMEOUT VL53L0X sensor");
    }
    Serial.print("ToF VL53L0X Distanz: ");
    Serial.println(distance);
}
