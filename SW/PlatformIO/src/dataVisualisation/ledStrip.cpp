/**
 * ledstrip - definition
 * 
 * handels everything to control the ledstrip. This includes functions
 * to show sensor information and more (ToDo)
 * 
 * using the Library: FastLED
 * https://github.com/FastLED/FastLED
 * 
 * @author Tom Seiffert
 */
#include "ledStrip.h"
#include "configuration/globalConfig.h"
#include "FastLED.h"

#define NUMBER_OF_LEDS 8

namespace DataVisualisation {

    namespace LedStrip {
        
        //pre decleration
        void setAllLeds(CRGB color);

        CRGB lipLedStrip[NUMBER_OF_LEDS];

        /* ------- public known methods ------------------ */

        //coment in .h file
        void setup() {
            //LED Controller needed for the use of the leds
            CLEDController& ledStripController = FastLED.addLeds<WS2812, LED_STRIP, GRB>(lipLedStrip, NUMBER_OF_LEDS);
            ledStripController.clearLeds(0);
            FastLED.setBrightness(50);
            setAllLeds(CRGB::Red);
            FastLED.show();
        }

        //coment in .h file
        void clear() {
            FastLED.clear();
        	FastLED.show();
        }

        //coment in .h file
        void showNumber(int number) {
            //ToDo: Servo Bug when updating the led strip - probably just update LED every second?
            bool updateLed = false;
            
            //convert number to positiv and show the sign with color
            CRGB color;
            if(number >= 0) {
                color = CRGB::Green;
            } else {
                color = CRGB::Blue;
            }
            number = abs(number);

            //ToDo: create binary number representation for the leds
            if(updateLed) {
                FastLED.clear();
                for(int i = 0; i < number || i <= NUMBER_OF_LEDS; i++) {
                    lipLedStrip[i] = color;
                }
                FastLED.show(); //ToDo Remove - update LED every half second
            }
        }

        /* ------- privat - public unknown methods ------- */

        /**
         * method to set all leds in the same color
         * @param color: the color of the leds
         */
        void setAllLeds(CRGB color) {
            for (int i = 0; i < NUMBER_OF_LEDS; i++) {
                lipLedStrip[i] = color;
            }
            FastLED.show(); //ToDo Remove - update LED every half second
        } 
    }
}