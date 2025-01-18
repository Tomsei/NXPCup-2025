/**
 * Single component - engine definition
 * 
 * Basic code to test the function of the engine
 * Control the pwm signal and control the engine speed 
 * 
 * using the Library: Servo (Arduino)
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h> 
#include <Servo.h>

extern bool globalEngineState;

namespace SingleComponent {

    Servo ESC;

    /**
     * setup the motor (pwm signal)
     */
    void setupMotor() {
        ESC.attach(MOTOR_ESC_PIN, 1000, 2000);
        ESC.write(0);
        delay(5000); 
    }

    /**
     * control the motor depending on the engin state
     */
    void runMotor() {

        /* Control Test*/
        if(globalEngineState) {
            ESC.write(15);
        } else {
            ESC.write(0);
        }

        // Speed Tests - Fast
        /*
        if (millis() > 10000 && millis() < 10500) {
            ESC.write(150);
            Serial.println("Fast");
            Serial.print(millis());
        }
        else if(millis() >= 10500 && millis() < 12000) {
            ESC.write(30);
            Serial.println("Slow");
            Serial.print(millis());
        }
        else {
            ESC.write(0);
            Serial.println("Stop");
            Serial.print(millis());
        }
        */

        // continuous speed changing 
        /*
        if(((millis() % 10000) > 2500) && ((millis() % 10000) < 7500)) {
            ESC.write(20);
        }
        else if((millis() % 10000) < 2500) {
            ESC.write(15);
        }
        else {
            ESC.write(0);
        }
        */
    }
}
#endif