#include <Arduino.h>

namespace BoardInput {

    struct Data
    {
        uint16_t poti0;
        uint16_t poit1;
        uint8_t dipswitch;
        uint8_t button0;
        uint8_t button1;
    };
    

    void update();
    void setup();
    void printData();
    void getBoardData();
}