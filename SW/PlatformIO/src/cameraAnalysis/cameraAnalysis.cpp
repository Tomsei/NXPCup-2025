#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "cameraAnalysis/cameraAnalysis.h"

//ToDo Remove - Just testing
#include "drivingControl/drivingControl.h"

namespace CameraAnalysis {

    //pre definition --------------------
    template<typename IntArray>
    void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);
    
    //variables -------------------------
    ImageAnalysis currentImageAnalysis;

    bool newImageAvailable = false;
    int sobelThreshold = 40;


    //methods ---------------------------
    void setup() {
        OpenMVCam::setup();
    }

    /**
     * Method to analyse the picture to get driving vector (steering Angel)
     */
    void analyse() {
        if (newImageAvailable) {
             
            static SingleRowAnalysis currentRow;
            currentRow.updateRow(currentImageAnalysis.getImage(), 0);
            currentRow.calculateSobelRow();
            currentRow.calculateTrackCenter();
            newImageAvailable = false;
        }
    }

    /**
     * method to update the Image if there is new Image data!
     * ToDo: comment
     */
  
    uint32_t* ImageAnalysis::getImage() {
        return imageDataBuffer;
    }

    /**
     * ToDo: comment
     */
    void ImageAnalysis::updateImage(uint32_t* pixelData) {
        imageDataBuffer = pixelData;
        newImageAvailable = true;
    }

    /**
     * method to print an image
     * @param start: startpixel | default 0
     * @param length: the amount of pixel to print | default size of the video-width * lines (image resolution)
     */
    void ImageAnalysis::printImage(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*NUMBER_OF_LINES*/) {
        printArray(imageDataBuffer, start, length, "print img:\t");
    }

    /**
     * 
     * ToDo: comment!
     */
     void SingleRowAnalysis::updateRow(uint32_t* pixelData, int row) {
        int startIndexOfLine = row * VIDEO_RESOLUTION_X;
        rowDataBufferPointer = pixelData + startIndexOfLine;
        //printRow(0,20);
    }

    /**
     * method to calculate the sobel values of the row
     */
    void SingleRowAnalysis::calculateSobelRow() {
        for (int i = 0; i < VIDEO_RESOLUTION_X-2; i++) {
            //int carsting to get negativ values
            sobelRowDataBuffer[i] = ((int(rowDataBufferPointer[i] * 2)) + (int(rowDataBufferPointer[i+2] * -2)));
        }
        //printSobelRow(0,20);
    }


    /**
     * method to calculate the track center
     * get the left and right edge and calculate the center
     * @return trackCenter: the center of the track
     */
    int SingleRowAnalysis::calculateTrackCenter() {
        auto [leftEdge, rightEdge] = calculateEdges(VIDEO_RESOLUTION_X/2);
        int trackCenter = (leftEdge + rightEdge) / 2;

        int steeringTest = (VIDEO_RESOLUTION_X/2) - trackCenter;
        //Serial.print("Steering Test: "); Serial.println(steeringTest);
        steeringTest = 90 + steeringTest;
        //Serial.print("Servo Steering: "); Serial.print(steeringTest); Serial.print("track Center: "); Serial.println(trackCenter);
        //ToDo: Just testing - remove!!
        DrivingControl::drive(17, steeringTest);

        return trackCenter;
    }

    /**
     * method to print a row
     * @param start: startpixel | default 0
     * @param length: the amount of pixel to print | default size of the video-width
     */
    void SingleRowAnalysis::printRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*/) {
        printArray(rowDataBufferPointer, start, length, "print img row:\t");
    }

    /**
     * method to print the sobel row
     * @param start: startpixel | default 0
     * @param length: the amount of pixel to print | default size of the video-width -2 (2 values less)
     */
    void SingleRowAnalysis::printSobelRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X -2*/) {
        printArray(sobelRowDataBuffer, start, length, "sobel row:\t\t");
    }

    //--------------- private ----------------

    /**
     * method to calculate the track edges
     * just check if the sobelThreshold ist high enough to be an edge
     * @param startSearch: the pixel to start the search to left an right (center to start)
     * @return {leftEdge, rightEdge}: a tupel of the left and right Edge 
     */
    std::tuple<int, int> SingleRowAnalysis::calculateEdges(int startSearch) {
        
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
}
#endif