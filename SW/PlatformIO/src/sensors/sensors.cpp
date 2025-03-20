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
    UsedSensorData usedData;

    //comment in .h file
    void setup() {
        TofDistance::setup();
        //OpticalFlow::setup();
        //Imu::setup(); //ToDo: Check if IMU creates error
        ArdLineFinder::setup();
    }

    //comment in .h file
    void updateRawData() {
        rawData.tofDistance = TofDistance::getDistance();
        //OpticalFlow::readMotion(&rawData.opticalFlowX, &rawData.opticalFlowY);
        //Imu::getMotion(&rawData.imu);
        rawData.ardLineFinder = ArdLineFinder::getSpeed();
    }

    void updateUsedSensorData() {
        usedData.tofDistance = TofDistance::getDistance();
        usedData.speed = ArdLineFinder::getSpeed();
    }

    //comment in .h file
    void printData() {
        #ifdef CONSOLE
            CONSOLE.print("ToF Distance: "); CONSOLE.print(rawData.tofDistance);
            // CONSOLE.print("\t Optical Flow - X: "); CONSOLE.print(rawData.opticalFlowX);
            // CONSOLE.print("\t Y: "); CONSOLE.print(rawData.opticalFlowY);
            // CONSOLE.print("\t IMU - AX:"); CONSOLE.print(rawData.imu.ax);
            // CONSOLE.print("\t IMU - AY:"); CONSOLE.print(rawData.imu.ay);
            // CONSOLE.print("\t IMU - AZ:"); CONSOLE.print(rawData.imu.az);
            // CONSOLE.print("\t IMU - GX:"); CONSOLE.print(rawData.imu.gx);
            // CONSOLE.print("\t IMU - GY:"); CONSOLE.print(rawData.imu.gy);
            // CONSOLE.print("\t IMU - GZ:"); CONSOLE.print(rawData.imu.gz);
            CONSOLE.print("\t Linefinder: "); CONSOLE.print(rawData.ardLineFinder);
            CONSOLE.println("");
        #endif
    }
}