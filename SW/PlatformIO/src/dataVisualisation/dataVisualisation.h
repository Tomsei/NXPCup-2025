/**
 * data visualisation - declaration
 * 
 * combines the data visualisation of the display and leds to provide a combined option
 * to control both the same. Just using the led and display functions
 *  
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#include "dataVisualisation/display.h"
#include "dataVisualisation/ledStrip.h"

namespace DataVisualisation {
    
    /**
     * setup display and led
     */
    void setup();

    /**
     * clear display and led
     */
    void clear();
    
}