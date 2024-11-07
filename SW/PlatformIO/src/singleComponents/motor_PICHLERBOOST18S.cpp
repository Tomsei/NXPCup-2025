#include <Arduino.h> 
#include <Servo.h>

#include "configuration/globalConfig.h"

Servo ESC;

/**
 * setup the motor (pwm signal)
 */
void setupMotor() {
    ESC.attach(motorPin, 1000, 2000); //min pulse width, max pulse width
    ESC.write(0);
    delay(5000); 
}

/**
 * control the motor
 * @param engineState to deciede if the engine should dirve (just for testing!)
 */
void runMotor(bool engineState) {

    /* Control Test*/
    if(engineState) {
        ESC.write(17);
    } else {
        ESC.write(0);
    }

    /* Speed Tests
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

    /* continuous speed changing
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