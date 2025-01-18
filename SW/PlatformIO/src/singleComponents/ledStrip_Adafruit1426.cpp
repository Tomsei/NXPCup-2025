/**
 * Single component - led strip definition
 * 
 * Basic code to test the function of the led strip 
 * Turn on the leds and let them blink
 * 
 * using the Library: FastLED
 * https://github.com/FastLED/FastLED
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST
#define NUMBER_OF_LEDS 8

#include "FastLED.h"

#include "ledStrip_Adafruit1426.h"

namespace SingleComponent {

    //forward declaration
    void setAllLeds(CRGB color);

    CRGB lipLedStrip[NUMBER_OF_LEDS];

    bool ledState = false;
    

    /**
     * setup method to begin the led Strip
     * set all leds to blue
     */
    void setupLedStrip() {
        CLEDController& ledStripController = FastLED.addLeds<WS2812, LED_STRIP, GRB>(lipLedStrip, NUMBER_OF_LEDS);
        ledStripController.clearLeds(0);
        setAllLeds(CRGB::Blue);
        FastLED.show();
    }
    
    /** 
     * run method to show leds working
     * turn leds blue and red
     */
    void runLedStrip() {
        if (millis() % 5000 <= 2500) {
            if(ledState) {
                setAllLeds(CRGB::Blue);
                ledState = false;
            }
        }
        else {
            if(!ledState) {
                setAllLeds(CRGB::Red);
                ledState = true;
            }
        }
    }

    /**
     * method to set all leds in the same color
     * @param color: the color of the leds
     */
    void setAllLeds(CRGB color) {
        for (int i = 0; i < NUMBER_OF_LEDS; i++) {
            lipLedStrip[i] = color;
        }
        FastLED.show();
    } 
}
#endif