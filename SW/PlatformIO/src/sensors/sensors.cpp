#include "sensors/sensors.h"

#include "sensors/tofDistance.h"
#include "sensors/opticalFlow.h"
#include "sensors/imu.h"
#include "sensors/lineFinder.h"
#include "configuration/globalConfig.h"

namespace Sensors {

    RawSensorData rawData;
    LineFinder lineFinder1(ARD_LINE_FINDER1); //Setup is done here
    LineFinder lineFinder2(ARD_LINE_FINDER2); //Setup is done here

    void setup() {
        TofDistance::setup();
        OpticalFlow::setup();
    }

    void updateRawData() {
        rawData.tofDistance = TofDistance::getDistance();
        OpticalFlow::readMotion(&rawData.opticalFlowX, &rawData.opticalFlowY);
        Imu::getMotion(&rawData.imuAX, &rawData.imuAY, &rawData.imuAZ, &rawData.imuGX, &rawData.imuGY, &rawData.imuGZ);
        rawData.linefinder1 = lineFinder1.getCurrentState();
        rawData.linefinder2 = lineFinder2.getCurrentState();
    }

    void printData() {
        Serial.print("ToF Distance: "); Serial.print(rawData.tofDistance);
        Serial.print("\t Optical Flow - X: "); Serial.print(rawData.opticalFlowX);
        Serial.print("\t Y: "); Serial.print(rawData.opticalFlowY);
        Serial.print("\t IMU - AX:"); Serial.print(rawData.imuAX);
        Serial.print("\t IMU - AY:"); Serial.print(rawData.imuAY);
        Serial.print("\t IMU - AZ:"); Serial.print(rawData.imuAZ);
        Serial.print("\t IMU - GX:"); Serial.print(rawData.imuGX);
        Serial.print("\t IMU - GY:"); Serial.print(rawData.imuGY);
        Serial.print("\t IMU - GZ:"); Serial.print(rawData.imuGZ);
        Serial.print("\t Linefinder - 1: "); Serial.print(rawData.linefinder1);
        Serial.print("\t 2: "); Serial.println(rawData.linefinder2);
    }
}