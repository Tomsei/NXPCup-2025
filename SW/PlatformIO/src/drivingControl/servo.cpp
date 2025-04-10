/**
 * servo - definition
 * 
 * Controll the servo for driving to the correct direction.
 * This includes an servo setup and the control the steeringangle
 * 
 * using the Library: servo.h (Arudio)
 * 
 * @author Tom Seiffert
 */
#include "drivingControl/servo.h"

#include <Servo.h>

#include "configuration/globalConfig.h"

namespace DrivingControl {
    
    namespace SteeringServo {
        Servo libServo;

        /* ------- public known methods ------------------ */

        //comment in .h file
        void setup() {
            libServo.attach(SERVO_PIN, 544, 2400);
            libServo.write(90);
            #ifdef CONSOLE 
                CONSOLE.println("servo setup done");
            #endif
        }

        //comment in .h file
        void setSteeringAngle(int steeringAngle) {
            //check param input
            steeringAngle = steeringAngle > MAX_STEERING_ANGLE ? MAX_STEERING_ANGLE : steeringAngle;
            steeringAngle = steeringAngle < MIN_STEERING_ANGLE ? MIN_STEERING_ANGLE : steeringAngle;
            libServo.write(steeringAngle);
        }
    }
}