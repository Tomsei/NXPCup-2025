#include <Arduino.h>

namespace Sensors {

    class TofDistance {
        public:
            static void setup();
            static uint16_t getDistance();
            static void printData();
    };

}