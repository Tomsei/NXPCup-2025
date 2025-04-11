/**
 * sensor - declaration
 * 
 * controll all sensors and combine the data into one struct
 * updating the raw data and store the current values
 * provide the combined sensor data.
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

#include "sensors/imu.h"
#include "lineFinder.h"

namespace Sensors {

    //structure for basic sensor data
    struct RawSensorData { 
        int tofDistance;
        int16_t opticalFlowX;
        int16_t opticalFlowY;
        Imu::MotionData imu;
        int ardLineFinder;
    };

    //structure of used sensor data
    struct UsedSensorData {
        int tofDistance;
        int speed;
    };
    
    //make it "public" to read data when it is needed
    extern RawSensorData rawData;
    extern UsedSensorData usedData;
    
    /**
     * setup all sensors
     */
    void setup();

    /**
     * update the sensor data of all sensors
     * just call the getData functions of the sensors
     */
    void updateRawData();

    /**
     * update the sensor data of all sensors
     * just call the getData functions of the sensors
     */
    void updateUsedData();


    /**
     * print the sensor data of all sensors
     */
    void printData();
}