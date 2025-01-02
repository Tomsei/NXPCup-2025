#include <Arduino.h>
namespace Sensors {
    
    class OpticalFlow {
        public:
            static void setup();
            static void readMotion(int16_t* deltaX, int16_t* deltaY); 
    };
}