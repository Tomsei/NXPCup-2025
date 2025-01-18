/**
 * Single component - ToF Distance sensor definition
 * 
 * Basic code to test the function of the ToF Distance sensor
 * Read and print the sensor data
 * 
 * using the Library: VL53L0X.h 
 * https://github.com/pololu/vl53l0x-arduino
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifdef SINGLE_COMPONENTS_TEST

//Source: https://github.com/pololu/vl53l0x-arduino

#include <Wire.h>
#include <VL53L0X.h>


namespace SingleComponent {
    
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
}
#endif
