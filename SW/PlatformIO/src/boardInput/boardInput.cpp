/**
 * Board Input - definition
 * 
 * Handles everything belonging to the board inputs like the poti, button
 * and dipSwitch Values. This includes the use of the IO-Expander
 * to get the values of the Buttons and DipSwitch.
 * 
 * using the Library: Adafruit_MCP23017.h
 * https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
 * 
 * @author Tom Seiffert
 */
#include "boardInput/boardInput.h"
#include "Adafruit_MCP23X17.h"
#include "configuration/globalConfig.h"

namespace BoardInput {

    Data data;
    Adafruit_MCP23X17 ioExpander;
    
    //forward declaration
    void setupIoExpander();
    void setupData();
    int readPoti(int poti);
    uint8_t readButton(int button);
    uint8_t readDipSwitch();
    uint16_t readSpeedMode();


    /* ------- public known methods ------------------ */

    // comment in .h file
    void setup() {
        //setupIoExpander(); //ToDo: remove - avoid i2c IO-Expander
        setupData();
        pinMode(SPEED_MODE_PIN1, INPUT);
        pinMode(SPEED_MODE_PIN2, INPUT);
        pinMode(SPEED_MODE_PIN3, INPUT);
        pinMode(SPEED_MODE_PIN4, INPUT);
        pinMode(SPEED_MODE_PIN5, INPUT);
    }

    // comment in .h file
    // ToDo: analog Read... take time - if necessary split into stept or interupting
    void update() {
        data.poti1 = readPoti(POTI1);
        data.poti2 = readPoti(POTI2);
        data.speedMode = readSpeedMode();
        /*//ToDo: remove - avoid i2c IO-Expander
        data.button1 = readButton(IO_EX_BUTTON1);
        data.button2 = readButton(IO_EX_BUTTON2);
        data.dipSwitch = readDipSwitch(); */
    }

    // comment in .h file
    void printData() {
        #ifdef CONSOLE
            String dataToPrint = "";
            dataToPrint = dataToPrint + "Poti 1: " + data.poti1 + " Poti 2: " + data.poti2 
            + " Button 1: " + data.button1 + " Button 2 " + data.button2 + " Dip Switch: " + data.dipSwitch;
            CONSOLE.print ("Board Input | ");
            CONSOLE.println(dataToPrint);
        #endif
    }

    // comment in .h file
    Data* getData() {
        return &data; //ToDo: Test!
    }

    // comment in .h file
    bool getSingleDipswitchValue(DipSwitchEnum aDipSwitch) {
        return data.dipSwitch & (uint8_t)aDipSwitch;
    }


    /* ------- privat - public unknown methods ------- */

    /**
     * setup the IOExpander with the given methods
     * - begin i2C connection
     * - initiate the pinmode for the used pins
     */
    void setupIoExpander() {
        if(ioExpander.begin_I2C()) {
            #ifdef CONSOLE
                CONSOLE.println("BoardInput: IO-Expander setup sucessfull");
            #endif
        }
        else {
            #ifdef CONSOLE
                CONSOLE.println("BoardInput: IO-Expander setup error");
            #endif
        }

        ioExpander.pinMode(IO_EX_BUTTON1, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_BUTTON2, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH1, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH2, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH3, INPUT_PULLUP);
        ioExpander.pinMode(IO_EX_DIPSWITCH4, INPUT_PULLUP);
    }

    /**
     * setup the data struct
     * - sets all values to -1
     */
    void setupData() {
        data.poti1 = 0;
        data.poti2 = 0;
        data.button1 = 0;
        data.button2 = 0;
        data.dipSwitch = 0;
        data.speedMode = 0;
    }

    /**
     * read poti data
     * @param poti: the poti to read
     * @return: the poti value
     */
    int readPoti(int poti) {
        return analogRead(poti);
    }

    /**
     * read button Data
     * @param button: the button to read
     * @return: the button value
     */
    uint8_t readButton(int button) {
        return !ioExpander.digitalRead(button);
    }

    /**
     * read the dip switch
     * - create decimal representation of dip switch values 
     * @return: the value of all switches as decimal number
     */
    uint8_t readDipSwitch() {
        uint8_t dipSwitchvalue = 15;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH1) * 1;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH2) * 2;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH3) * 4;
        dipSwitchvalue -= ioExpander.digitalRead(IO_EX_DIPSWITCH4) * 8;
        return dipSwitchvalue;
    }

    /**
     * read speed mode given from extern Teensy
     * - create decimal representation of speed Mode
     * @return: speed mode wich is send
     */
    uint16_t readSpeedMode() {
        uint16_t speedMode = 0;
        speedMode += digitalRead(SPEED_MODE_PIN1) * 1;
        speedMode += digitalRead(SPEED_MODE_PIN2) * 2;
        speedMode += digitalRead(SPEED_MODE_PIN3) * 4;
        speedMode += digitalRead(SPEED_MODE_PIN4) * 8;
        speedMode += digitalRead(SPEED_MODE_PIN5) * 16;
        return speedMode;
    }
}