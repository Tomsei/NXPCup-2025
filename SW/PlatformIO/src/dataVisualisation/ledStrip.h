/**
 * ledstrip - declaration
 * 
 * handels everything to control the ledstrip. This includes functions
 * to show sensor information and more (ToDo)
 * 
 * using the Library: FastLED
 * https://github.com/FastLED/FastLED
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"
#include "Arduino.h"

namespace DataVisualisation {

    namespace LedStrip {

        /**
         * setup ledstrip and show the color red 
         */
        void setup();

        /**
         * update the leds - show the leds on stribe
         */
        void update();

        /**
         * clear ledstrip (set all leds to black)
         */
        void clear();

        /**
         * show a number mapped to a given range
         * example range 8: 4 = 4 LEDS | example range 16: 4 = 2 LEDS
         * green leds immply a positiv number
         * blue leds imply a negativ
         * @param number: number to show
         * @param range: range to map number
         */
        void showNumberInRange(int number, int range);

        /**
         * set the leds of the strip specific to rgb color
         * @param led which leds should be set (binary representation)
         * @param r: red value
         * @param g: green value
         * @param b: blue value
         */
        void setLeds(uint8_t led, u_int8_t r, u_int8_t g, u_int8_t b);
        
    };
}