
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Wire.h>
#include "MPU6050.h"



namespace SingleComponent {

    MPU6050 accelgyro;

    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    /**
     * setup method to initiate imu
     */
    void setupImu() {
        //Wire.begin(); is done before (general setup)

        Serial.println("Initializing Imu");
        accelgyro.initialize();
        // verify connection
        Serial.println("Testing device connections...");
        Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    }

    /**
     * run method to call in loop to test imu and print values
     */
    void runImu() {
        // read raw accel/gyro measurements from device
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        // display values
        if (gx > 1000 || gx < -1000) {
            Serial.print("IMU a/g:\t");
            Serial.print(ax); Serial.print("\t");
            Serial.print(ay); Serial.print("\t");
            Serial.print(az); Serial.print("\t");
            Serial.print(gx); Serial.print("\t");
            Serial.print(gy); Serial.print("\t");
            Serial.println(gz);
        }
    }
}
#endif