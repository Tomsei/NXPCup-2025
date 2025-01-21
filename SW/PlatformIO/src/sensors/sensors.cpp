/**
 * sensor - definition
 * 
 * controll all sensors and combine the data into one struct
 * updating the raw data and store the current values
 * provide the combined sensor data.
 * 
 * @author Tom Seiffert
 */
#include "sensors/sensors.h"

//#include "sensors/imu.h"
#include "sensors/tofDistance.h"
#include "sensors/opticalFlow.h"
#include "sensors/lineFinder.h"
#include "configuration/globalConfig.h"

namespace Sensors {

    RawSensorData rawData;
    
    //create lineFinder object and setup it with constructor
    LineFinder lineFinder1(ARD_LINE_FINDER1); 
    LineFinder lineFinder2(ARD_LINE_FINDER2);

    //comment in .h file
    void setup() {
        TofDistance::setup();
        OpticalFlow::setup();
    }

    //comment in .h file
    void updateRawData() {
        rawData.tofDistance = TofDistance::getDistance();
        OpticalFlow::readMotion(&rawData.opticalFlowX, &rawData.opticalFlowY);
        Imu::getMotion(&rawData.imu);
        rawData.linefinder1 = lineFinder1.getCurrentState();
        rawData.linefinder2 = lineFinder2.getCurrentState();
    }

    //comment in .h file
    void printData() {
        Serial.print("ToF Distance: "); Serial.print(rawData.tofDistance);
        Serial.print("\t Optical Flow - X: "); Serial.print(rawData.opticalFlowX);
        Serial.print("\t Y: "); Serial.print(rawData.opticalFlowY);
        Serial.print("\t IMU - AX:"); Serial.print(rawData.imu.ax);
        Serial.print("\t IMU - AY:"); Serial.print(rawData.imu.ay);
        Serial.print("\t IMU - AZ:"); Serial.print(rawData.imu.az);
        Serial.print("\t IMU - GX:"); Serial.print(rawData.imu.gx);
        Serial.print("\t IMU - GY:"); Serial.print(rawData.imu.gy);
        Serial.print("\t IMU - GZ:"); Serial.print(rawData.imu.gz);
        Serial.print("\t Linefinder - 1: "); Serial.print(rawData.linefinder1);
        Serial.print("\t 2: "); Serial.println(rawData.linefinder2);
    }
}