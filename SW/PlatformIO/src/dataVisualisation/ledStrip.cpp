#include "ledStrip.h"
#include "configuration/globalConfig.h"
#include "Adafruit_NeoPixel.h"

#define NUMBER_OF_LEDS 8

namespace DataVisualisation {

    namespace LedStrip {
        
        //pre decleration
        void setAllLeds(uint8_t r, uint8_t g, uint8_t b);

        Adafruit_NeoPixel libLedStrip = Adafruit_NeoPixel(NUMBER_OF_LEDS, LED_STRIP);

        void setup() {
            libLedStrip.begin();
            setAllLeds(0, 50, 0);
        }

        void clear() {
            libLedStrip.clear();
            libLedStrip.show();
        }


        void showNumber() {
            //ToDo: Servo Bug when updating the led strip - probably just update LED every second?
            bool updateLed = false;
            if(updateLed) {

                int number = 2;
                libLedStrip.clear();
                //ToDo Update to binary!
                for(int i = 0; i < number; i++) {
                    libLedStrip.setPixelColor(i, libLedStrip.Color(0,25,0));
                }
                libLedStrip.show();
            }
        }

        /**
         * method to set all leds in on color (rgb)
         * @param r: red value
         * @param g: green value
         * @param b: blue value
         */
        void setAllLeds(uint8_t r, uint8_t g, uint8_t b) {
            for (int i = 0; i < NUMBER_OF_LEDS; i++) {
                libLedStrip.setPixelColor(i, libLedStrip.Color(r, g, b));
            }
            libLedStrip.show();	
        } 
    }
}