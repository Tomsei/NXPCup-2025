/**
 * Single component - display definition
 * 
 * Basic code to test the function of the display
 * Write some text and draw a line to the display
 * 
 * using the Library: Adafruit_SSD1306.h
 * https://github.com/adafruit/Adafruit_SSD1306
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
/**
 * Display pixel
 *      X   X   X   X   X
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   ... ... ... ... ...
 *  Y   63  63  63  63  63
 */


extern bool globalEngineState;

namespace SingleComponent {
    
    // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

    /**
     * setup the display. Try to connect and initiate with an basic hello world.
     */
    void setupDisplay() {

        if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
            CONSOLE.println(F("SSD1306 allocation failed"));
        }
        delay(2000);
        
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("Hello, world!");
        display.display(); 
        delay(1000);

    }

    /**
     * method to call in loop to change the display
     */
    void runDisplay() {
        display.clearDisplay();
        display.setCursor(0,0);
        if(globalEngineState) {
            display.println("Drive");
            display.drawLine(0,30,127,30, WHITE);
            display.setCursor(0,32);
            display.print("Drive");
        } else {
            display.println("Stop");
            display.drawLine(0,30,127,30, WHITE);
            display.setCursor(0,32);
            display.print("Stop");
        }
        display.display();
    }
}
#endif