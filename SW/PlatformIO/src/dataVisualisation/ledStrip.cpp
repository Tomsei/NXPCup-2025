#include "ledStrip.h"
#include "configuration/globalConfig.h"
#include "FastLED.h"

#define NUMBER_OF_LEDS 8

namespace DataVisualisation {

    namespace LedStrip {
        
        //pre decleration
        void setAllLeds(CRGB color);

        CRGB lipLedStrip[NUMBER_OF_LEDS];

        void setup() {
            CLEDController& ledStripController = FastLED.addLeds<WS2812, LED_STRIP, GRB>(lipLedStrip, NUMBER_OF_LEDS);
            ledStripController.clearLeds(0);
            FastLED.setBrightness(50);
            setAllLeds(CRGB::Red);
            FastLED.show();
        }

        void clear() {
            FastLED.clear();
        	FastLED.show();
        }

        void showNumber() {
            //ToDo: Servo Bug when updating the led strip - probably just update LED every second?
            bool updateLed = false;
            if(updateLed) {

                int number = 2;
                FastLED.clear();
                //ToDo Update to binary!
                for(int i = 0; i < number; i++) {
                    lipLedStrip[i] = CRGB::Green;
                }
                FastLED.show();
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
}