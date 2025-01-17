#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST
#define NUMBER_OF_LEDS 8

#include "FastLED.h"

#include "ledStrip_Adafruit1426.h"

namespace SingleComponent {

    void setAllLeds(CRGB color);

    CRGB lipLedStrip[NUMBER_OF_LEDS];

    bool ledState = false;

    

    /**
     * setup method to begin the led Strip
     * let all leds go on
     */
    void setupLedStrip() {
        CLEDController& ledStripController = FastLED.addLeds<WS2812, LED_STRIP, GRB>(lipLedStrip, NUMBER_OF_LEDS);
        ledStripController.clearLeds(0);
        setAllLeds(CRGB::Blue);
        FastLED.show();
    }
    
    /** 
     * run method to show leds working
     * turn leds on and off
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