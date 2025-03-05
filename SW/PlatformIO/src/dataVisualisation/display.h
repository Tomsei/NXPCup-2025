/**
 * display - declaration
 * 
 * handels everything to control the display. This includes functions
 * to display sensor information and more (ToDo)
 * 
 * using the Library: Adafruit_SSD1306.h
 * https://github.com/adafruit/Adafruit_SSD1306
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


namespace DataVisualisation {

    namespace Display { 
        /**
         * setup the display and print Setup Done
         */
        void setup();

        /**
         * clear the display
         */
        void clear();

        /**
         * display a given number
         * @param number: the number to display
         */
        void showNumber(int number);
        
    };
}
