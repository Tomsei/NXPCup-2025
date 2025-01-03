#include <Arduino.h>

namespace Sensors {
    
    class LineFinder {
        public:
            LineFinder(uint8_t pin);

            uint8_t getCurrentState(); 
        
        private:
            uint8_t pin;
    };
}