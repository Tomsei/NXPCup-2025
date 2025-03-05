/**
 * imu - definition
 * 
 * Handels everything to control the imu. 
 * This includes functions for setup and getting data
 * 
 * using the Library: MPU6050.h 
 * https://github.com/ElectronicCats/mpu6050
 * 
 * @author Tom Seiffert
 */
#include "sensors/imu.h"

#include "MPU6050.h"

namespace Sensors {

    namespace Imu {

        MPU6050 accelGyro;

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            accelGyro.initialize();
            #ifdef CONSOLE
                CONSOLE.println(accelGyro.testConnection() ? "IMU connection successful" : "IMU connection failed");
            #endif
        }

        //comment in .h file
        void getMotion(MotionData* data) {
            accelGyro.getMotion6(&data->ax, &data->ay, &data->az, &data->gx, &data->gy, &data->gz);
        }
    }
}