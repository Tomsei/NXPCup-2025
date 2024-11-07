#include <Arduino.h>
#include "Adafruit_MCP23X17.h"

#include "configuration/globalConfig.h"

Adafruit_MCP23X17 mcp;

/**
 * setup the Io-expander
 */
void setupIoExpander() {
    if(!mcp.begin_I2C()) {
        Serial.println("IO-Expander Error");
    }
    mcp.pinMode(BUTTON1, INPUT_PULLUP);
    mcp.pinMode(BUTTON2, INPUT_PULLUP);
    mcp.pinMode(DIPSWITCH1, INPUT_PULLUP);
    mcp.pinMode(DIPSWITCH2, INPUT_PULLUP);
    mcp.pinMode(DIPSWITCH3, INPUT_PULLUP);
    mcp.pinMode(DIPSWITCH4, INPUT_PULLUP);
}

/**
 * run method to call in loop to print the IO inputs of the io-expander (buttons, dipswitch)
 */
void runIoExpander() {
    if(mcp.digitalRead(BUTTON1) == 0) {
        Serial.print("IO Expander: \t");
        Serial.print(mcp.digitalRead(BUTTON1)); Serial.print("\t");
        Serial.print(mcp.digitalRead(BUTTON2)); Serial.print("\t");
        Serial.print(mcp.digitalRead(DIPSWITCH1)); Serial.print("\t");
        Serial.print(mcp.digitalRead(DIPSWITCH2)); Serial.print("\t");
        Serial.print(mcp.digitalRead(DIPSWITCH3)); Serial.print("\t");
        Serial.print(mcp.digitalRead(DIPSWITCH4)); Serial.print("\t");
        Serial.println("");
    }
}