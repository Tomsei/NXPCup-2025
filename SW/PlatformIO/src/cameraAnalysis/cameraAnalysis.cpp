#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "cameraAnalysis/cameraAnalysis.h"

#define CAM_OFFSET 0

namespace CameraAnalysis {

    //pre definition --------------------
    template<typename IntArray>
    void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);
    
    //variables -------------------------
    ImageAnalysis currentImageAnalysis;
    SingleRowAnalysis currentRowAnalysis;

    bool newImageAvailable = false;
    int sobelThreshold = 40;


    //methods ---------------------------
    void setup() {
        OpenMVCam::setup();
        currentImageAnalysis.trackCenters[0] = 160; //Todo noch für alle Zeilen durchführen und berechnen!
    }
    /**
     * Method to analyse the picture to get driving vector (steering Angel)
     */
    void analyse() {
        if (newImageAvailable) {
            currentRowAnalysis.updateRow(currentImageAnalysis.getImage(), 0);
            currentRowAnalysis.calculateSobelRow();

            currentImageAnalysis.lastTrackCenters[0] = currentImageAnalysis.trackCenters[0];
            Serial.print("\t"); Serial.print("lastTrackCencter: "); Serial.print(currentImageAnalysis.lastTrackCenters[0]); Serial.print("\t");
            currentImageAnalysis.trackCenters[0] = currentRowAnalysis.calculateTrackCenter(currentImageAnalysis.lastTrackCenters[0]);
            
            Serial.print(currentImageAnalysis.trackCenters[0]); Serial.print("\t");
            currentImageAnalysis.calculateSteeringAngle();

            newImageAvailable = false;
        }
    }

    int getSteeringAngle() {
        return 90 + currentImageAnalysis.steeringAngle;
    }

    uint8_t getSpeed() {
        return 16;
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
     * @todo Check if there is stil an analyses (then the image should not be overwritten)
     * that should also be 
     */
    void ImageAnalysis::updateImage(uint32_t* pixelData) {
        //ToDo Testing this here!!
        if(!newImageAvailable) {
            imageDataBuffer = pixelData;
            newImageAvailable = true;
        }

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
     * @todo Comment
     */
    void ImageAnalysis::calculateSteeringAngle() {
        int tempSteeringAngle = 0;
        tempSteeringAngle = (VIDEO_RESOLUTION_X/2) - trackCenters[0];

        tempSteeringAngle *= 0.5;
        /*
        if (steeringAngle > -20 && steeringAngle < 20) {
            steeringAngle = steeringAngle * 0.8;
        }
        else if (steeringAngle < -30 || steeringAngle > 30) {
            steeringAngle = steeringAngle * 1.1;
        }*/

        steeringAngle = tempSteeringAngle;
        Serial.print("Steering Angle: "); Serial.println(steeringAngle);
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
    uint16_t SingleRowAnalysis::calculateTrackCenter(int startSearch) {
        auto [leftEdge, rightEdge] = calculateEdges(startSearch); 
        uint16_t trackCenter = (leftEdge + rightEdge) / 2;
        return trackCenter - CAM_OFFSET; //ToDo Remove offset
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
    std::tuple<uint16_t, uint16_t> SingleRowAnalysis::calculateEdges(int startSearch) {
        
        //default edges at end of line
        uint16_t leftEdge = 0;
        uint16_t rightEdge = VIDEO_RESOLUTION_X-2;

        //ToDo: Check if the Edge is Big enaugh!

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