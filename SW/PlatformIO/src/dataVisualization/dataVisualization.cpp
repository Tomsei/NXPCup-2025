/**
 * data visualisation - definition
 * 
 * combines the data visualisation of the display and leds to provide a combined option
 * to control both the same. Just using the led and display functions
 *  
 * @author Tom Seiffert
 */
#include "dataVisualization/dataVisualization.h"

namespace DataVisualization  {

    /* ------- public known methods ------------------ */

    // comment in .h file
    void setup() {
        Display::setup();
        LedStrip::setup();
    }

    // comment in .h file
    void clear() {
        Display::clear();
        LedStrip::clear();
    }
}