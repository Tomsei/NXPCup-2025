#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

void printArray(uint8_t* rowToPrint, int start, int length);

void CameraAnalysis::ImageAnalysis::getImage() {
    OpenMVCam::getImage(1, rowDataBuffer);
    printImage();
}

void CameraAnalysis::ImageAnalysis::printImage(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*/) {
    printArray(rowDataBuffer, start, length);
    Serial.print("Ausgabe der Reihe X von "); Serial.println(start);

}


void printArray(uint8_t* rowToPrint, int start = 0, int length = VIDEO_RESOLUTION_X) {
    String printedArray = "print img row: \t";
    for (int i = start; i < (start + length); i++) {
        printedArray = printedArray + rowToPrint[i] + "\t";
    }
    Serial.println(printedArray);
}
