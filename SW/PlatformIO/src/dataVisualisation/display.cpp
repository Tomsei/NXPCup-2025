/**
 * display - definition
 * 
 * handels everything to control the display. This includes functions
 * to display sensor information and more (ToDo)
 * 
 * using the Library: Adafruit_SSD1306.h
 * https://github.com/adafruit/Adafruit_SSD1306
 * 
 * Display pixels:
 * -------------------------------------
 *      X   X   X   X   X
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   0   1   2   3   4   ... 127
 *  Y   ... ... ... ... ...
 *  Y   63  63  63  63  63
 * -------------------------------------
 * 
 * @author Tom Seiffert
 */

#include "display.h"

#include <Adafruit_SSD1306.h>

namespace DataVisualisation {

    namespace Display {

        Adafruit_SSD1306 lipDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            if(lipDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for the display
                CONSOLE.println("Display setup succesfull");
            }
            else {
                CONSOLE.println(F("Display setup failed"));
            }    
    
            lipDisplay.clearDisplay();
            lipDisplay.setTextSize(1);  
            lipDisplay.setTextColor(SSD1306_WHITE);
            lipDisplay.setCursor(0,0);
            lipDisplay.println(F("Display Setup Done"));
            lipDisplay.display();
        }  

        //comment in .h file
        void clear() {
            lipDisplay.clearDisplay();
            lipDisplay.display();
        }

        //comment in .h file
        void showNumber(int number) {
            lipDisplay.clearDisplay();
            lipDisplay.setCursor(0,0);
            lipDisplay.print(number);
            lipDisplay.display();
        }
    }
}