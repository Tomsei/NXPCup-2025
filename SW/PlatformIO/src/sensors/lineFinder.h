#include <Arduino.h>
//ToDo: When Using create new structure!
namespace Sensors {
    
    class LineFinder {
        public:
            LineFinder(uint8_t pin);

            uint8_t getCurrentState(); 
        
        private:
            uint8_t pin;
    };
}