#include "ledStrip.h"
#include "configuration/globalConfig.h"
#include "Adafruit_NeoPixel.h"

#define NUMBER_OF_LEDS 8

namespace DataVisualisation {

    Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(NUMBER_OF_LEDS, LED_STRIP);

    void clearLed() {
        ledStrip.clear();
        ledStrip.show();
    }

    //todo: change to binary representation!
    void showNumberLed() {
        int number = 7;

        for(int i = 0; i < number; i++) {
            ledStrip.setPixelColor(i, ledStrip.Color(0,25,0));
        }
        ledStrip.show();
    }
}