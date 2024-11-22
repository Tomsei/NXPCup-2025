
#include "configuration/globalConfig.h"
#include "cameraAnalysis/cameraAnalysisMain.h"

//pre definition 
template<typename IntArray>
void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);

int sobelThreshold = 50;

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
    //printRow(0, 30);
    /* just testing different lines*/
    /*
    OpenMVCam::getImageRow(rowDataBuffer, 1);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 2);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 3);
    printRow(220, 30);
    OpenMVCam::getImageRow(rowDataBuffer, 4);
    printRow(220, 30);
    */
    
}

/**
 * method to calculate the sobel values of the row
 */
void CameraAnalysis::SingleRowAnalysis::calculateSobelRow() {
    for (int i = 0; i < VIDEO_RESOLUTION_X-2; i++) {
        //int carsting to get negativ values
        sobelRowDataBuffer[i] = ((int(rowDataBuffer[i] * 2)) + (int(rowDataBuffer[i+2] * -2)));
    }
    //printSobelRow(0,30);
}


/**
 * method to calculate the track center
 * get the left and right edge and calculate the center
 * @return trackCenter: the center of the track
 */
int CameraAnalysis::SingleRowAnalysis::calculateTrackCenter() {
    auto [leftEdge, rightEdge] = calculateEdges(VIDEO_RESOLUTION_X/2);
    int trackCenter = (leftEdge + rightEdge) / 2;
    return trackCenter;
}


/**
 * method to calculate the track edges
 * just check if the sobelThreshold ist high enough to be an edge
 * @param startSearch: the pixel to start the search to left an right (center to start)
 * @return {leftEdge, rightEdge}: a tupel of the left and right Edge 
 */
std::tuple<int, int> CameraAnalysis::SingleRowAnalysis::calculateEdges(int startSearch) {
    
    //default edges at end of line
    uint8_t leftEdge = 0;
    int rightEdge = VIDEO_RESOLUTION_X-2;

    //search left edge
    for(int i = startSearch; i >= 0; i--) {
        if (sobelRowDataBuffer[i] < - sobelThreshold) {
            leftEdge = i;
            break;
        } 
    }

    //search right edge
    for(int i = startSearch; i <= VIDEO_RESOLUTION_X-2; i++) {
        if(sobelRowDataBuffer[i] > sobelThreshold) {
            rightEdge = i;
            break;
        }
    }
    return {leftEdge, rightEdge};
}


/**
 * method to print a row
 * @param start: startpixel | default 0
 * @param length: the amount of pixel to print | default size of the video-width
 */
void CameraAnalysis::SingleRowAnalysis::printRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*/) {
    printArray(rowDataBuffer, start, length, "print img row:\t");
}

/**
 * method to print the sobel row
 * @param start: startpixel | default 0
 * @param length: the amount of pixel to print | default size of the video-width -2 (2 values less)
 */
void CameraAnalysis::SingleRowAnalysis::printSobelRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X -2*/) {
    printArray(sobelRowDataBuffer, start, length, "sobel row:\t\t");
}



/* ----- helper methods -----  */


/**
 * method to print an array.
 * concatenate an string with all the values of the array.
 * @param arrayToPrint: the array to print
 * @param start: startvalue of the array
 * @param length: the amout of values to print
 * @param linePrefix: prefix to print before the values
 * 
 * template<typename IntArray> to make sure an uint8_t and uint16_t array can be printed 
 */
template<typename IntArray>
void printArray(IntArray* arrayToPrint, int start, int length, String linePrefix) {
    String printedArray = "";
    printedArray = printedArray + linePrefix;
    for (int i = start; i < (start + length); i++) {
        printedArray = printedArray + arrayToPrint[i] + "\t";
    }
    Serial.println(printedArray);
}
