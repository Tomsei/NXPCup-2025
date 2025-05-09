/**
 * Board Input - declaration
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
#include <Arduino.h>
#include "configuration/globalConfig.h"

namespace BoardInput {

    //structure to store all needed board input data
    struct Data {
        uint16_t poti1;
        uint16_t poti2;
        uint8_t dipSwitch;
        uint8_t button1;
        uint8_t button2;
        uint16_t speedMode;
    };

    enum DipSwitchEnum : uint8_t {S1 = 1, S2 = 2, S3 = 4, S4 = 8};

    //make it "public" to read data when it is needed
    extern Data data;

    /**
     * setup of IoExpander and data struct
     */
    void setup();
    
    /**
     * update all input values and store it in the data Struct 
     */
    void update();
    
    /**
     * function to print the current Board Data
     */
    void printData();
    
    /**
     * function got get the current board input Data
     * @return a pointer to the current data!
     */
    Data* getData();

    /**
     * function to get a single dip switch value
     * @param aDipSwitch: the switchvalue to get
     * @return: the value of the choosen switch 
     */
    bool getSingleDipswitchValue(DipSwitchEnum aDipSwitch);
}