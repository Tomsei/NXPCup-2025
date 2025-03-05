/**
 * engin - definition
 * 
 * Controll the engine for driving.
 * This includes an engine setup and the control of the engin speed
 * 
 * using the Library: servo.h (Arudio)
 * 
 * @author Tom Seiffert
 */
#include "drivingControl/engine.h"

#include <Arduino.h>
#include <Servo.h>

#include "configuration/globalConfig.h"

namespace DrivingControl {

    namespace Engine {
        
        Servo ESC;

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            //use the servo library to control the PWM Pin
            //ToDo: checkt min and max!
            ESC.attach(MOTOR_ESC_PIN, 1000, 2000);
            ESC.write(0);
            delay(2500);
            #ifdef CONSOLE 
                CONSOLE.println("engine setup done");
            #endif
        }

        //comment in .h file
        void setSpeed(int speed) {
            ESC.write(speed);
        }
    }    
}