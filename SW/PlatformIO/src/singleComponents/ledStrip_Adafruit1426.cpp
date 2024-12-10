#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST
#define NUMBER_OF_LEDS 8

#include "Adafruit_NeoPixel.h"

#include "ledStrip_Adafruit1426.h"

namespace SingleComponent {

    Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(NUMBER_OF_LEDS, LED_STRIP);

    bool ledState = false;



    /**
     * setup method to begin the led Strip
     * let all leds go on
     */
    void setupLedStrip() {
        ledStrip.begin();
        changeLedState(0,0,125);
        ledStrip.show();
    }
    
    /** 
     * run method to show leds working
     * turn leds on and off
     */
    void runLedStrip() {
        if (millis() % 5000 <= 2500) {
            if(ledState) {
                changeLedState(0,0,5);
                ledState = false;
                Serial.print(ledState);
            }
        }
        else {
            if(!ledState) {
                changeLedState(5,0,0);
                ledState = true;
                Serial.print(ledState);
            }
        }
    }

    /**
     * method to change all leds
     * @param r: red value
     * @param g: green value
     * @param b: blue value
     */
    void changeLedState(int r, int g, int b) {
        for (int i = 0; i < NUMBER_OF_LEDS; i++) {
            ledStrip.setPixelColor(i, ledStrip.Color(r, g, b));
        }
        ledStrip.show();
    }
}
#endif