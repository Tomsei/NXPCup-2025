//Source: https://github.com/bitcraze/Bitcraze_PMW3901

#include "Bitcraze_PMW3901.h"


Bitcraze_PMW3901 flow(10);
int16_t deltaX, deltaY;

void printOpticalFlowData();


void setupOpticalFlow() {
    
    if(!flow.begin()) {
        Serial.println("Initialization of the optical flos sensor failed");
    }
    flow.setLed(false);
    //eigene LED
    pinMode(32, OUTPUT);
}

void runOpticalFlow() {
    flow.readMotionCount(&deltaX, &deltaY);
    digitalWrite(32, HIGH);
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