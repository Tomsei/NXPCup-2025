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

namespace DataVisualisation {

    namespace LedStrip {

        /**
         * setup ledstrip and show the color red 
         */
        void setup();

        /**
         * clear ledstrip (set all leds to black)
         */
        void clear();

        /**
         * show a binary number to ledstrip
         * green leds immply a positiv number
         * blue leds imply a negativ
         * @todo implement!
         * @param number: number to show
         */
        void showNumber(int number);
    };
}