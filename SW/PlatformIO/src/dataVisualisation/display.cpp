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
    Adafruit_SSD1306 lipDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


    void Display::clear() {
        lipDisplay.clearDisplay();
        lipDisplay.display();
    }

    void Display::showNumber() {
        lipDisplay.write("1");
    }
}