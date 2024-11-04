#include <Arduino.h>

// For OLED display
#include "U8g2lib.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int pinButton = 0;

void drawDisplay(const char *line1, const char *line2 = "", const char *line3 = "")
{
  // Write on OLED display
  // Clear the internal memory
  u8g2.clearBuffer();
  // Set appropriate font
  u8g2.setFont(u8g2_font_ncenR14_tr);
  u8g2.drawStr(0,14, line1);
  u8g2.drawStr(0,39, line2);
  u8g2.drawStr(0,64, line3);
  // Transfer internal memory to the display
  u8g2.sendBuffer();
}



void setupDisplay() {
    u8g2.begin();
    delay(10);
      //Button
    pinMode(pinButton, INPUT);
    Serial.println("Testing the OLED I2C display...");
    drawDisplay("Setup", "Display", "to Run");
}

void runDisplay(bool engineState) {

    if (engineState)
    {
        drawDisplay("1", "", "");
    } else {
        drawDisplay("0", "", "");
    }
    

}