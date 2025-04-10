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

namespace DataVisualization {

    namespace Display {

        Adafruit_SSD1306 lipDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

        bool updateDisplay = true;

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            if(lipDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for the display
                #ifdef CONSOLE
                    CONSOLE.println("Display setup succesfull");
                #endif
            }
            else {
                #ifdef CONSOLE
                    CONSOLE.println(F("Display setup failed"));
                #endif
            }    
            CONSOLE.println(lipDisplay.availableForWrite());

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
        void update() {
            updateDisplay = true;
        }

        void showsetupDone() {
            lipDisplay.println(F("Complete Setup done"));
            lipDisplay.display();
        }

        //comment in .h file
        void showNumber(int number) {
            if(updateDisplay) {
                lipDisplay.clearDisplay();
                lipDisplay.setCursor(0,0);
                lipDisplay.print(number);
                lipDisplay.display();
                
                updateDisplay = false;   
            }
        }

        //comment in .h file
        void showTrackCenters(uint32_t* trackCenters) {
            if (updateDisplay) {
                lipDisplay.clearDisplay();
                
                
                for(int i = 0; i < SCREEN_HEIGHT; i++) {
                    int trackCenterPos = trackCenters[i*3] * 128 / 320;
                    if(trackCenterPos > SCREEN_WIDTH-1) {
                        trackCenterPos = SCREEN_WIDTH-1;
                    } 
                    lipDisplay.drawPixel(trackCenterPos, SCREEN_HEIGHT - 1 - i, SSD1306_WHITE); //track Center zugriff noch prüfen!
                }
                lipDisplay.display();
                updateDisplay = false;
            }
        }
    }
}