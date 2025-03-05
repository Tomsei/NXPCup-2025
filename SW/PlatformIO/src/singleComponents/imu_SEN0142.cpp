/**
 * Single component - imu definition
 * 
 * Basic code to test the function of the imu sensor
 * Read and print the sensor data
 * 
 * using the Library: MPU6050.h 
 * https://github.com/ElectronicCats/mpu6050
 * 
 * @author Tom Seiffert
 */
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

        CONSOLE.println("Initializing Imu");
        accelgyro.initialize();
        // verify connection
        CONSOLE.println("Testing device connections...");
        CONSOLE.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    }

    /**
     * run method to call in loop to test imu and print values
     */
    void runImu() {
        // read raw accel/gyro measurements from device
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        // display values
        if (gx > 1000 || gx < -1000) {
            CONSOLE.print("IMU a/g:\t");
            CONSOLE.print(ax); CONSOLE.print("\t");
            CONSOLE.print(ay); CONSOLE.print("\t");
            CONSOLE.print(az); CONSOLE.print("\t");
            CONSOLE.print(gx); CONSOLE.print("\t");
            CONSOLE.print(gy); CONSOLE.print("\t");
            CONSOLE.println(gz);
        }
    }
}
#endif