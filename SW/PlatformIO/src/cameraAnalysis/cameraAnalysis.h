#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include <Arduino.h>
#include "cameraAnalysis/camera.h" //ToDo: check why i cant move this

namespace CameraAnalysis {

    /**
     * @todo comment
     */
    void setup();

    /**
     * @todo comment
     */
    void analyse();

    /**
     * @todo comment
     */
    int getSteeringAngle();

    /**
     * @todo comment
     */
    uint8_t getSpeed();

    //pre definition --------------------
    //helper Methode 
    /**
     * @todo: comment
     */
    template<typename IntArray>
    void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);

}
#endif