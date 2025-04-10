/**
 * engine - declaration
 * 
 * Controll the engine for driving.
 * This includes an engine setup and the control of the engin speed
 * 
 * using the Library: servo.h (Arudio)
 * 
 * when using first time: Calibration of the ESC necessary (see ESC-Instructions)
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"

namespace DrivingControl {

    namespace Engine {

        /**
         * setup engine with pwm control for the ESC
         */
        void setup();

        /**
         * set the engine speed
         * @param speed: the speed the engine should run
         */
        void setSpeed(int speed);
    };
}