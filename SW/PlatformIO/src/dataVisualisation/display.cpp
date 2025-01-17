#include "display.h"

#include <Adafruit_SSD1306.h>
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

namespace DataVisualisation {
    // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
    namespace Display {

        Adafruit_SSD1306 lipDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

        //ToDo: Error Handling
        void setup() {
            if(!lipDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for the display
                Serial.println(F("SSD1306 allocation failed"));
            }
            lipDisplay.clearDisplay();
            lipDisplay.setTextSize(1);  
            lipDisplay.setTextColor(SSD1306_WHITE);
            lipDisplay.setCursor(0,0);
            lipDisplay.println(F("Display Setup Done"));
            lipDisplay.display();
        }  

        void clear() {
            lipDisplay.clearDisplay();
            lipDisplay.display();
        }

        void showNumber(int number) {
            lipDisplay.setCursor(0,0);
            lipDisplay.drawLine(0,15,127,15, WHITE);
            lipDisplay.clearDisplay();
            lipDisplay.print(number);
            lipDisplay.display();
        }
    }
}