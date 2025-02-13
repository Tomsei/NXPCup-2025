/**
 * imu - declaration
 * 
 * Handels everything to control the imu. 
 * This includes functions for setup and getting data
 * 
 * using the Library: MPU6050.h 
 * https://github.com/ElectronicCats/mpu6050
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace Sensors {

    namespace Imu {
        
        //struct to store the imu data
        struct MotionData { 
            int16_t ax; 
            int16_t ay; 
            int16_t az; 
            int16_t gx; 
            int16_t gy; 
            int16_t gz; 
        };
        
        /**
         * setup imu with the library 
         */
        void setup();

        /**
         * get the motion data and write it into the
         * data variable.
         * @param data: pointer to the data variable the values should be written
         */
        void getMotion(MotionData* data);
    };

}