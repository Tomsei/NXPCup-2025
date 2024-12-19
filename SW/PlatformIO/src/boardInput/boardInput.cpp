#include "boardInput/boardInput.h"

#include "Adafruit_MCP23X17.h"

#include "configuration/globalConfig.h"

namespace BoardInput {

    static Data data;
    Adafruit_MCP23X17 ioExpander;
    
    void setupIoExpander();
    void setupData();
    int readPoti(int poti);
    int readButton(int button);
    int readDipSwitch();


    /* ToDo: Error Handling!*/

    /*--------------- "Public" --------------- */
    void setup() {
        setupIoExpander();
        setupData();
    }

    void update() {
        data.poti1 = readPoti(POTI1);
        data.poti2 = readPoti(POTI2);
        data.button1 = readButton(IO_EX_BUTTON1);
        data.button2 = readButton(IO_EX_BUTTON2);
        data.dipSwitch = readDipSwitch();
    }

    void printData() {
        String dataToPrint = "";
        dataToPrint = dataToPrint + "Poti 1: " + data.poti1 + " Poti 2: " + data.poti2 
        + " Button 1: " + data.button1 + " Button 2 " + data.button2 + " Dip Switch: " + data.dipSwitch;
        Serial.print ("Board Input | ");
        Serial.println(dataToPrint);
    }

    void getData() {
        
    }



    /*--------------- "Privat" ---------------*/
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

    void setupData() {
        data.poti1 = -1;
        data.poti2 = -1;
        data.button1 = -1;
        data.button2 = -1;
        data.dipSwitch = -1;
    }

    int readPoti(int poti) {
        return analogRead(poti);
    }

    int readButton(int button) {
        return ioExpander.digitalRead(button);
    }

    int readDipSwitch() {
        int dipSwitchvalue = 0;
        //@ToDo: Implement
        return dipSwitchvalue;
    }
}