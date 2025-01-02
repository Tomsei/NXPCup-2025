#include "sensors/sensors.h"

#include "sensors/tofDistance.h"
#include "sensors/opticalFlow.h"

namespace Sensors {

    static rawSensorData rawData;

    void setup() {
        TofDistance::setup();
        OpticalFlow::setup();
    }

    void update() {
        int16_t opticalFlowX, opticalFlowY;
        OpticalFlow::readMotion(&opticalFlowX, &opticalFlowY);

        rawData.opticalFlowX = opticalFlowX;
        rawData.opticalFlowY = opticalFlowY;
        rawData.tofDistance = TofDistance::getDistance();
    }

    void printData() {
        Serial.print("ToF Distance: "); Serial.print(rawData.tofDistance);
        Serial.print("\t Optical Flow - X: "); Serial.print(rawData.opticalFlowX);
        Serial.print("\t Y: "); Serial.print(rawData.opticalFlowY);
        Serial.print("\t Imu: ");
        Serial.println("");
    }
}