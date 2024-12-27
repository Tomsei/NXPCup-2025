#include <Arduino.h>

namespace BoardInput {

    /**
     * structure for all needed board input data
     */
    struct Data
    {
        uint16_t poti1;
        uint16_t poti2;
        uint8_t dipSwitch;
        uint8_t button1;
        uint8_t button2;
    };

    /**
     * setup function
     * - setup of IoExpander
     * - setup data struct with -1
     */
    void setup();
    
    /**
     * update function
     * - update all input values of the static data representation 
     */
    void update();
    
    /**
     * function to print the current Board Data
     */
    void printData();
    
    /**
     * function got get the current Board Data
     * @return ToDo!
     */
    void getBoardData();

    /**
     * function to get a single dip switch value
     * @param aDipSwitch: the switch to get
     * @return: the value of the choosen switch 
     */
    uint8_t getSingleDipswitchValue(uint8_t aDipSwitch);
}