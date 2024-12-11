#include "boardInput/boardInput.h"

#include "Adafruit_MCP23X17.h"

#include "configuration/globalConfig.h"
namespace BoardInput {

    Data data;
    Adafruit_MCP23X17 ioExpander;
    
    int readPoti(int poti);


    void setupIoExpander() {
        if(!ioExpander.begin_I2C()) {
            Serial.println("BoardInput: IO-Expander Init Error");
        }
        ioExpander.pinMode(IO_EX_BUTTON1, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_BUTTON2, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH1, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH2, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH3, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH4, INPUT_PULLUP);
    }

    void update() {
        data.poti1 = readPoti(POTI1);
        data.poti2 = readPoti(POTI2);
        data.dipswitch = 5;
    }


    int readPoti(int poti) {
        return analogRead(poti);
    }

    int readButton() {
        return -1;
    }

    int readDipSwitch() {
        return -1;
    }
}