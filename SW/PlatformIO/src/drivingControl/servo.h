/**
 * servo - declaration
 * 
 * Controll the servo for driving to the correct direction.
 * This includes an servo setup and the control the steeringangle
 * 
 * using the Library: servo.h (Arudio)
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"
#include "Arduino.h"

namespace DrivingControl {

    namespace SteeringServo {
        
        /**
         * setup servo with pwm control
         */
        void setup();

        /**
         * control servo steering and check valid input
         * @todo implement mapping of angle to servo values
         * @param steeringAngle: the angle to steer (direction) 
         */
        void setSteeringAngle(int steeringAngle);
    };
}