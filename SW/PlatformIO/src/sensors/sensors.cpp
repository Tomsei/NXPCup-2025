#include "sensors/sensors.h"

#include "sensors/tofDistance.h"
#include "sensors/opticalFlow.h"
#include "sensors/imu.h"

namespace Sensors {

    static rawSensorData rawData;

    void setup() {
        TofDistance::setup();
        OpticalFlow::setup();
    }

    void updateRawData() {
        rawData.tofDistance = TofDistance::getDistance();
        OpticalFlow::readMotion(&rawData.opticalFlowX, &rawData.opticalFlowY);
        Imu::getMotion(&rawData.imuAX, &rawData.imuAY, &rawData.imuAZ, &rawData.imuGX, &rawData.imuGY, &rawData.imuGZ);
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
        Serial.println("");
    }
}