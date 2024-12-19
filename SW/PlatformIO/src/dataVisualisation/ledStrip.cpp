#include "ledStrip.h"
#include "configuration/globalConfig.h"
#include "Adafruit_NeoPixel.h"

#define NUMBER_OF_LEDS 8

namespace DataVisualisation {

    Adafruit_NeoPixel libLedStrip = Adafruit_NeoPixel(NUMBER_OF_LEDS, LED_STRIP);

    void LedStrip::setup() {
        libLedStrip.begin();
        //ToDo all LEDS to green
        setAllLeds(0, 125, 0);
    }

    void LedStrip::clear() {
        libLedStrip.clear();
        libLedStrip.show();
        Serial.print("ClearLEDStrip");
    }


    void LedStrip::showNumber() {
        int number = 7;

        for(int i = 0; i < number; i++) {
            libLedStrip.setPixelColor(i, libLedStrip.Color(0,25,0));
        }
        libLedStrip.show();
        Serial.print("ShowNumerLEDStrip");
    }

    /**
     * method to change all leds
     * @param r: red value
     * @param g: green value
     * @param b: blue value
     */
    void LedStrip::setAllLeds(uint8_t r, uint8_t g, uint8_t b) {
        for (int i = 0; i < NUMBER_OF_LEDS; i++) {
            libLedStrip.setPixelColor(i, libLedStrip.Color(r, g, b));
        }
        libLedStrip.show();	
    }
}