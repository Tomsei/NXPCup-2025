#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

//pre definition 
void printArray(uint8_t* rowToPrint, int start, int lengt, String linePrefix);



/**
 * method to get a new row
 * the call OpenMVCam::getImage write the data into the rowDataBuffer
 * 
 * ToDo: better solution needed - currently is called in camera SPI when SPI completes - problably change!
 */
void CameraAnalysis::ImageAnalysis::getImage() {
    OpenMVCam::getImage(imageDataBuffer);
    printImage();
}

/**
 * method to print an image
 * @param start: startpixel | default 0
 * @param length: the amount of pixel to print | default size of the video-width * lines (image resolution)
 */
void CameraAnalysis::ImageAnalysis::printImage(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
    printArray(imageDataBuffer, start, length, "print img:\t");
}



/**
 * method to get a new row
 * the call OpenMVCam::getImageRow write the data into the rowDataBuffer
 * 
 * ToDo: better solution needed - currently is called in camera SPI when SPI completes - problably change!
 */
void CameraAnalysis::SingleRowAnalysis::getRow() {
    OpenMVCam::getImageRow(rowDataBuffer, 0);
    printRow(220, 30);
    /* just testing different lines*/
    OpenMVCam::getImageRow(rowDataBuffer, 1);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 2);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 3);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 4);
    printRow(220, 30);
    
}

/**
 * method to print a row
 * @param start: startpixel | default 0
 * @param length: the amount of pixel to print | default size of the video-width
 */
void CameraAnalysis::SingleRowAnalysis::printRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*/) {
    printArray(rowDataBuffer, start, length, "print img row:\t");
}

/* ----- helper methods -----  */


/**
 * method to print an array.
 * concatenate an string with all the values of the array.
 * @param arrayToPrint: the array to print
 * @param start: startvalue of the array
 * @param length: the amout of values to print
 * @param linePrefix: prefix to print before the values
 */
void printArray(uint8_t* arrayToPrint, int start, int length, String linePrefix) {
    String printedArray = "";
    printedArray = printedArray + linePrefix;
    for (int i = start; i < (start + length); i++) {
        printedArray = printedArray + arrayToPrint[i] + "\t";
    }
    Serial.println(printedArray);
}