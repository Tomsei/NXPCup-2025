//Source: https://github.com/bitcraze/Bitcraze_PMW3901

#include "Bitcraze_PMW3901.h"
#include "configuration/globalConfig.h"

Bitcraze_PMW3901 flow(OpticalFlowSensor);
int16_t deltaX, deltaY;

void printOpticalFlowData();


void setupOpticalFlow() {
    
    if(!flow.begin()) {
        Serial.println("Initialization of the optical flos sensor failed");
    }
    flow.setLed(false);
    //eigene LED
    pinMode(OpticalFlowLED, OUTPUT);
}

void runOpticalFlow() {
    flow.readMotionCount(&deltaX, &deltaY);
    digitalWrite(OpticalFlowLED, HIGH);
    printOpticalFlowData();
    
}

void printOpticalFlowData() {
    if(deltaX != 0 || deltaY != 0) {
        Serial.print("Optical Flow | X: ");
        Serial.print(deltaX);
        Serial.print(", Y: ");
        Serial.print(deltaY);
        Serial.print("\n");
    }
}