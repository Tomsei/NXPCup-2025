/**
 * servo - declaration
 * 
 * Controll the servo for driving to the correct direction.
 * This includes a servo setup and the control the steeringangle
 * 
 * using the Library: servo.h (Arudio)
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"
#include "Arduino.h"

//define the steering maxima to each side!
#define MAX_STEERING_ANGLE 145
#define MIN_STEERING_ANGLE 35

namespace DrivingControl {

    namespace SteeringServo {
        
        /**
         * setup servo with pwm control
         */
        void setup();

        /**
         * control servo steering and check if input is valid
         * @param steeringAngle: the angle to steer (direction) 
         */
        void setSteeringAngle(int steeringAngle);
    };
}