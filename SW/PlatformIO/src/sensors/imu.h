#include <Arduino.h>
namespace Sensors {

    class Imu {
        public:
            struct motionData
            {
                int16_t ax, ay, az, gx, gy, gz;
            };
            
            static void setup();
            static void getMotion(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
    };

}