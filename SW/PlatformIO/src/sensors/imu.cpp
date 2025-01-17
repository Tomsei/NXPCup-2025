#include "sensors/imu.h"

#include "MPU6050.h"

namespace Sensors {

    namespace Imu {

        MPU6050 accelGyro;

        void setup() {
            accelGyro.initialize();
            Serial.println(accelGyro.testConnection() ? "IMU connection successful" : "IMU connection failed");
        }

        void getMotion(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
            accelGyro.getMotion6(ax, ay, az, gx, gy, gz);
        }
    }
}