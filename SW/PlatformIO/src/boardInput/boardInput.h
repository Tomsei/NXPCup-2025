#include <Arduino.h>

namespace BoardInput {

    struct Data
    {
        uint16_t poti1;
        uint16_t poti2;
        uint8_t dipswitch;
        uint8_t button1;
        uint8_t button2;
    };
    

    void update();
    void setup();
    void printData();
    void getBoardData();
}