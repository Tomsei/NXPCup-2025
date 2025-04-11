/**
 * display - declaration
 * 
 * handels everything to control the display. This includes functions
 * to display sensor information and more (ToDo - update variable to calculate just every ... seconds)
 * 
 * using the Library: Adafruit_SSD1306.h
 * https://github.com/adafruit/Adafruit_SSD1306
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"
#include "Arduino.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


namespace DataVisualization {

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
         * update display (change update state to true)
         */
        void update();
        
        /**
         * display a given number
         * @param number: the number to display
         */
        void showNumber(int number);
        
        /**
         * draw the calculatet Track Centers to display
         * @param trackCenters: the trackcenters to draw
         */
        void showTrackCenters(uint32_t* trackCenters);

        
        /**
         * test to visuzalize that setup is done
         * could be change to general show text
         */
        void showsetupDone();
    };
}
