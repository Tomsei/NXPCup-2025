//Source: https://github.com/pololu/vl53l0x-arduino

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

/**
 * setup to initiate the sensor
 */
void setupTofDistanceMeasure() {

    //Wire.begin(); done one time in setup

    sensor.setTimeout(500);
    if (!sensor.init())
    {
        Serial.println("Failed to detect and initialize VL53L0X sensor!");
    }
    sensor.startContinuous();
}

/**
 * method to call in loop to print the distance data of the sesnor
 */
void runTofDistanceMeasure() {
    int distance = sensor.readRangeContinuousMillimeters();
    if (sensor.timeoutOccurred()) {
        Serial.print(" TIMEOUT VL53L0X sensor");
    }
    if (distance < 150) {
        Serial.print("ToF VL53L0X distance: ");
        Serial.println(distance);
    }   
}
