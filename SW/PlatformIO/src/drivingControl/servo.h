/**
 * servo - declaration
 * 
 * Controll the servo for driving to the correct direction.
 * This includes an engine setup and the control the steeringangle
 * 
 * using the Library: servo.h (Arudio)
 * 
 * @author Tom Seiffert
 */

#include "configuration/globalConfig.h"

namespace DrivingControl {

    //ToDo determine the correct values!
    #define MAX_STEERING_ANGLE 145
    #define MIN_STEERING_ANGLE 35

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