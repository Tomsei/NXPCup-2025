/**
 * driving control - declaration
 * 
 * handels everything to control the car driving. 
 * This includes functions to setup engine and servo and
 * the general control of them to drive correctly.
 * 
 * @author Tom Seiffert
 */
#include <Arduino.h>

#include "configuration/globalConfig.h"

namespace DrivingControl {

    /**
     * setup servo and engine
     */
    void setup();

    /**
     * general control of the cardriving. 
     * controls the engine with given speed and steeringangle
     * @param speed: the engine power (car speed)
     * @param steeringAngle: the steering angle (direction) to drive
     */
    void drive(uint8_t speed, int steeringAngle);
}