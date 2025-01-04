#include <Arduino.h>
namespace Sensors {

    namespace Imu {
        
        struct motionData { 
            int16_t ax; 
            int16_t ay; 
            int16_t az; 
            int16_t gx; 
            int16_t gy; 
            int16_t gz; 
        };
            
        void setup();
        void getMotion(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
    };

}