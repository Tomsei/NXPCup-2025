#include "boardInput/boardInput.h"
#include "Adafruit_MCP23X17.h"
#include "configuration/globalConfig.h"

namespace BoardInput {

    Data data;
    Adafruit_MCP23X17 ioExpander;
    
    //pre decleration
    void setupIoExpander();
    void setupData();
    int readPoti(int poti);
    uint8_t readButton(int button);
    uint8_t readDipSwitch();


    /* ToDo: Error Handling!*/

    /*--------------- "Public" --------------- */

    // documentation in .h file
    void setup() {
        setupIoExpander();
        setupData();
    }

    // documentation in .h file
    // ToDo: analog Read... take time - if necessary split into stept or interupting
    void update() {
        data.poti1 = readPoti(POTI1);
        data.poti2 = readPoti(POTI2);
        data.button1 = readButton(IO_EX_BUTTON1);
        data.button2 = readButton(IO_EX_BUTTON2);
        data.dipSwitch = readDipSwitch();
    }

    // documentation in .h file
    void printData() {
        String dataToPrint = "";
        dataToPrint = dataToPrint + "Poti 1: " + data.poti1 + " Poti 2: " + data.poti2 
        + " Button 1: " + data.button1 + " Button 2 " + data.button2 + " Dip Switch: " + data.dipSwitch;
        Serial.print ("Board Input | ");
        Serial.println(dataToPrint);
    }

    // documentation in .h file
    void getData() {
        //ToDo: implement
    }

    // documentation in .h file
    bool getSingleDipswitchValue(DipSwitchEnum aDipSwitch) {
        return data.dipSwitch & (uint8_t)aDipSwitch;
        //return !ioExpander.digitalRead(aDipSwitch);
    }



    /*--------------- "Privat" ---------------*/

    /**
     * function to setup the IOExpander
     * - call ioExpander begin method
     * - initiate the pinmode for the used pins
     */
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

    /**
     * function to setup the static 
     * - set all data to -1
     */
    void setupData() {
        data.poti1 = -1;
        data.poti2 = -1;
        data.button1 = -1;
        data.button2 = -1;
        data.dipSwitch = -1;
    }

    /**
     * function to read the poti data
     * @param poti: the poti to read
     * @return: the poti value
     */
    int readPoti(int poti) {
        return analogRead(poti);
    }

    /**
     * function to read button Data
     * @param button: the button to read
     * @return: the button value
     */
    uint8_t readButton(int button) {
        return !ioExpander.digitalRead(button);
    }

    /**
     * function to read the dip switch
     * read the dip switch values an create a decimal representation
     * @return: the value of all switches in on decimal number
     */
    uint8_t readDipSwitch() {
        uint8_t dipSwitchvalue = 15;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH1) * 1;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH2) * 2;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH3) * 4;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH4) * 8;
        return dipSwitchvalue;
    }
}