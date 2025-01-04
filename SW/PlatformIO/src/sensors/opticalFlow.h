#include <Arduino.h>
namespace Sensors {
    
    namespace OpticalFlow {
        void setup();
        void readMotion(int16_t* deltaX, int16_t* deltaY); 
    };
}