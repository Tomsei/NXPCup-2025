#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

/*  X   X   X   X   X   X   X   X   X   X
Y   0   1   2   3   4   5   6   7   8   9   ... 127
Y   0   1   2   3   4   5   6   7   8   9   ...
Y   0   1   2   3   4   5   6   7   8   9   ...
Y   0   1   2   3   4   5   6   7   8   9   ...
Y   ... ... ... ... ... ... ... ... ... ... 
    63  63  63  63  63  63  63  63  63  63
*/

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setupDisplay() {

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
    }

    delay(2000);
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    // Display static text
    display.println("Hello, world!");
    display.display(); 

}

void runDisplay(bool engineState) {
    display.clearDisplay();
    if(engineState) {
        display.println("Drive");
        display.drawLine(0,30,127,30, WHITE);
        display.setCursor(0,32);
        display.print("Drive");
    } else {
        display.println("Stopp");
        display.drawLine(0,30,127,30, WHITE);
        display.setCursor(0,32);
        display.print("Stop");
    }
    display.display();
}