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

namespace DataVisualization {

    namespace LedStrip {
        
        int lastShownNumber;

        //pre decleration
        void setAllLeds(CRGB color);

        CRGB lipLedStrip[NUMBER_OF_LEDS];
 

        /* ------- public known methods ------------------ */

        //coment in .h file
        void setup() {
            //LED Controller needed for the use of the leds
            CLEDController& ledStripController = FastLED.addLeds<WS2812, LED_STRIP, GRB>(lipLedStrip, NUMBER_OF_LEDS);
            ledStripController.clearLeds(0);
            FastLED.setBrightness(255);
            setAllLeds(CRGB::White);
            FastLED.show();
            #ifdef CONSOLE
                CONSOLE.println("LEDS Setup Done");
            #endif
        }

        //comment in .h
        void update() {
            FastLED.show();
        }

        //coment in .h file
        void clear() {
            FastLED.clear();
        	FastLED.show();
        }

        //coment in .h file
        void showNumberInRange(int number, int range) {
            //ToDo: Servo Bug when updating the led strip - probably just update LED every second?
            //bool updateLed = false;
            
            //convert number to positiv and show the sign with color
            CRGB color;
            if(number >= 0) {
                color = CRGB::Green;
            } else {
                color = CRGB::Blue;
            }
            number = abs(number);

            //map number to range
            float numberInRange = 0.0;
            numberInRange = number / (range / NUMBER_OF_LEDS);

            if(lastShownNumber != (int)numberInRange) {
                lastShownNumber = (int)numberInRange;

                FastLED.clear();
                for(int i = 0; i < numberInRange && i < NUMBER_OF_LEDS; i ++) {
                    lipLedStrip[i] = color;
                }
                FastLED.show(); //ToDo: remove - update LED every half second
            }
        }

        //comment in .h
        void setLeds(uint8_t led, u_int8_t r, u_int8_t g, u_int8_t b) {
            if (1 & led) {
                lipLedStrip[0].setRGB(r, g, b);
            }
            if (2 & led) {
                lipLedStrip[1].setRGB(r, g, b);
            }
            if (4 & led) {
                lipLedStrip[2].setRGB(r, g, b);
            }
            if (8 & led) {
                lipLedStrip[3].setRGB(r, g, b);
            }
            if (16 & led) {
                lipLedStrip[4].setRGB(r, g, b);
            }
            if (32 & led) {
                lipLedStrip[5].setRGB(r, g, b);
            }
            if (64 & led) {
                lipLedStrip[6].setRGB(r, g, b);
            }
            if (128 & led) {
                lipLedStrip[7].setRGB(r, g, b);
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