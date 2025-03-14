/**
 * Single component - io expander definition
 * 
 * Basic code to test the function of the io expander 
 * Read and print the data of the dipswitch and the buttons
 * 
 * using the Library: Adafruit_MCP23017.h
 * https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include "Adafruit_MCP23X17.h"

namespace SingleComponent {

    Adafruit_MCP23X17 mcp;

    /**
     * setup the Io-expander
     */
    void setupIoExpander() {
        if(!mcp.begin_I2C()) {
            CONSOLE.println("IO-Expander Error");
        }
        mcp.pinMode(IO_EX_BUTTON1, INPUT_PULLUP);
        mcp.pinMode(IO_EX_BUTTON2, INPUT_PULLUP);
        mcp.pinMode(IO_EX_DIPSWITCH1, INPUT_PULLUP);
        mcp.pinMode(IO_EX_DIPSWITCH2, INPUT_PULLUP);
        mcp.pinMode(IO_EX_DIPSWITCH3, INPUT_PULLUP);
        mcp.pinMode(IO_EX_DIPSWITCH4, INPUT_PULLUP);
    }

    /**
     * run method to call in loop to print the IO inputs of the io-expander (buttons, dipswitch)
     */
    void runIoExpander() {
        if(mcp.digitalRead(IO_EX_BUTTON1) == 0) {
            CONSOLE.print("IO Expander: \t");
            CONSOLE.print(mcp.digitalRead(IO_EX_BUTTON1)); CONSOLE.print("\t");
            CONSOLE.print(mcp.digitalRead(IO_EX_BUTTON2)); CONSOLE.print("\t");
            CONSOLE.print(mcp.digitalRead(IO_EX_DIPSWITCH1)); CONSOLE.print("\t");
            CONSOLE.print(mcp.digitalRead(IO_EX_DIPSWITCH2)); CONSOLE.print("\t");
            CONSOLE.print(mcp.digitalRead(IO_EX_DIPSWITCH3)); CONSOLE.print("\t");
            CONSOLE.print(mcp.digitalRead(IO_EX_DIPSWITCH4)); CONSOLE.print("\t");
            CONSOLE.println("");
        }
    }
}
#endif