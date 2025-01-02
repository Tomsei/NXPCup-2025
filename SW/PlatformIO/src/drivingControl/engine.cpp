#include "drivingControl/engine.h"

#include <Arduino.h>
#include <Servo.h>

#include "configuration/globalConfig.h"

namespace DrivingControl {

    Servo ESC;

    void Engine::setup() {
        //ToDo: checkt min and max!
        ESC.attach(MOTOR_ESC_PIN, 1000, 2000);
        ESC.write(0);
        delay(2500);
    }

    void Engine::setSpeed(int speed) {
        ESC.write(speed);
    }
}