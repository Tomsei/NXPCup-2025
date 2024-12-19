#include <Arduino.h>

namespace DataVisualisation {

    class LedStrip {
        public:
            static void setup();
            static void clear();
            static void showNumber();
        private:
            static void setAllLeds(uint8_t r, uint8_t g, uint8_t b);
    };
}