#include <Arduino.h>
#include "Adafruit_MCP23X17.h"

#define device_adress 0x20
#define button1 8
#define button2 9

#define dipswitch1 0
#define dipswitch2 1
#define dipswitch3 2
#define dipswitch4 3

Adafruit_MCP23X17 mcp;

void setupIoExpander() {
    if(!mcp.begin_I2C()) {
        Serial.println("Error");
    }

    mcp.pinMode(button1, INPUT_PULLUP);
    mcp.pinMode(button2, INPUT_PULLUP);
    mcp.pinMode(dipswitch1, INPUT_PULLUP);
    mcp.pinMode(dipswitch2, INPUT_PULLUP);
    mcp.pinMode(dipswitch3, INPUT_PULLUP);
    mcp.pinMode(dipswitch4, INPUT_PULLUP);
}

void runIoExpander() {

    if(mcp.digitalRead(button1) == 0) {
        Serial.print("IO Expander: \t");
        Serial.print(mcp.digitalRead(button1)); Serial.print("\t");
        Serial.print(mcp.digitalRead(button2)); Serial.print("\t");
        Serial.print(mcp.digitalRead(dipswitch1)); Serial.print("\t");
        Serial.print(mcp.digitalRead(dipswitch2)); Serial.print("\t");
        Serial.print(mcp.digitalRead(dipswitch3)); Serial.print("\t");
        Serial.print(mcp.digitalRead(dipswitch4)); Serial.print("\t");
        Serial.println("");
    }
}