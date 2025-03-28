/**
 * Single component - optical flow definition
 * 
 * Basic code to test the function of the optical flow sensor
 * Read and print the sensor data
 * 
 * using the Library: Bitcraze_PMW3901.h 
 * https://github.com/bitcraze/Bitcraze_PMW3901
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include "Bitcraze_PMW3901.h"


namespace SingleComponent {

    Bitcraze_PMW3901 flow(OPTICAL_FLOW_CHIP_SELECT);
    int16_t deltaX, deltaY;

    //forward declaration
    void printOpticalFlowData();

    /**
     * setup method to initiate the optical flow Sensor
     */
    void setupOpticalFlow() {
        
        if(!flow.begin()) {
            CONSOLE.println("Initialization of the optical flow sensor failed");
        }
        flow.setLed(false);
        pinMode(OPTICAL_FLOW_LED, OUTPUT); //use the own led
    }

    /**
     * method to call in loop to manage optical flow sensor (read data, and control led)
     */
    void runOpticalFlow() {
        flow.readMotionCount(&deltaX, &deltaY);
        digitalWrite(OPTICAL_FLOW_LED, HIGH);
        printOpticalFlowData();
    }

    /**
     * method to print the optical flow data
     */
    void printOpticalFlowData() {

        if(deltaX > 3 || deltaY > 3 || deltaX < -3 || deltaY < -3) {
            CONSOLE.print("Optical Flow | X: "); CONSOLE.print(deltaX);
            CONSOLE.print(", Y: ");        CONSOLE.println(deltaY);
        }
    }
}
#endif