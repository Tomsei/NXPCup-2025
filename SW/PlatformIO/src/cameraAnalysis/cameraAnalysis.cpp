#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

#include "cameraAnalysis/cameraAnalysis.h"

#define CAM_OFFSET -7

namespace CameraAnalysis {

    //pre definition --------------------
    template<typename IntArray>
    void printArray(IntArray* rowToPrint, int start, int lengt, String linePrefix);
    
    //variables -------------------------
    ImageAnalysis currentImageAnalysis;
    SingleRowAnalysis currentRowAnalysis;

    bool newImageAvailable = false;
    int sobelThreshold = 20;


    //methods ---------------------------
    void setup() {
        OpenMVCam::setup();
        for (int i = 0; i < NUMBER_OF_LINES; i++) {
            currentImageAnalysis.trackCenters[i] = 160;
        }
        //currentImageAnalysis.trackCenters[0] = 160; //Todo noch für alle Zeilen durchführen und berechnen!
    }
    /**
     * Method to analyse the picture to get driving vector (steering Angel)
     */
    void analyse() {
        if (newImageAvailable) {
            for (int i = 0; i <NUMBER_OF_LINES; i++) {
                currentRowAnalysis.updateRow(currentImageAnalysis.getImage(), i);
                currentRowAnalysis.calculateSobelRow();

                currentImageAnalysis.lastTrackCenters[i] = currentImageAnalysis.trackCenters[i];
                currentImageAnalysis.trackCenters[i] = currentRowAnalysis.calculateTrackCenter(currentImageAnalysis.lastTrackCenters[i]);
                currentImageAnalysis.trackCenterOffsets[i] = abs(currentImageAnalysis.trackCenters[i] - (VIDEO_RESOLUTION_X/2));
                
                //CONSOLE.print(currentImageAnalysis.trackCenterOffsets[i]); CONSOLE.print("\t");
                //CONSOLE.println(currentImageAnalysis.trackCenters[i]);
                //ToDo Jump Out if it is a turn
                if(currentImageAnalysis.trackCenterOffsets[i] > 30) {
                    //CONSOLE.println("Break");
                    currentImageAnalysis.straightLinesAhead = i;
                    break;
                }
                if(i == NUMBER_OF_LINES -1) {
                    currentImageAnalysis.straightLinesAhead = i;
                }    
            }
            
            //CONSOLE.println("--------------");
            currentImageAnalysis.calculateSteeringAngle();

            newImageAvailable = false;
        }
    }

    int getSteeringAngle() {
        return 90 + currentImageAnalysis.steeringAngle;
    }

    uint8_t getSpeed() {
        //CONSOLE.println(currentImageAnalysis.straightLinesAhead);
        int speed = 0;
        if(currentImageAnalysis.trackCenterOffsets[4] < 25 && currentImageAnalysis.straightLinesAhead > 3 ) {
            speed = 26;
        }
        else if(currentImageAnalysis.trackCenterOffsets[3] < 25 && currentImageAnalysis.straightLinesAhead > 2 ) {
            speed = 24;
        }
        else if(currentImageAnalysis.trackCenterOffsets[2] < 25  && currentImageAnalysis.straightLinesAhead > 1 ) {
            speed = 23;
        }
        else if(currentImageAnalysis.trackCenterOffsets[1] < 25  && currentImageAnalysis.straightLinesAhead > 0) {
            speed = 21;
        }
        else {
            speed = 19;
        }

        //try speed change /ToDo change
        if(abs(currentImageAnalysis.steeringAngle) > 50)
            speed *= 1.1;
        return speed;   
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

    //ToDo: check and move to better Place!

    unsigned long lastTimeUpdated = 0;
    int lastSteeringAngle = 0;


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
        float tempSteeringAngle = 0;
        tempSteeringAngle = (VIDEO_RESOLUTION_X/2) - trackCenters[0];

        //quadratische Lenkung
        tempSteeringAngle *= 0.1;
        float factor = 0.9;
        if(tempSteeringAngle > 10) {
            factor = 1.0;
        }
        if(tempSteeringAngle < 0) {
            tempSteeringAngle *= tempSteeringAngle*factor;
            tempSteeringAngle = -tempSteeringAngle;    
        }
        else {
            tempSteeringAngle *= (tempSteeringAngle*factor);
        }

        /*
        if(tempSteeringAngle > -35 && tempSteeringAngle < 35) {
            tempSteeringAngle *= 0.5;
        }
        else if (tempSteeringAngle > 50 || tempSteeringAngle < -50 ) {
            tempSteeringAngle *= 0.9;
        }
        else {
            tempSteeringAngle *= 0.6;
        }
        */

        steeringAngle = tempSteeringAngle;
        //CONSOLE.print("Steering Angle: "); CONSOLE.println(steeringAngle);
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
        trackCenter = trackCenter + CAM_OFFSET;
        trackCenter = (trackCenter > 0) ? trackCenter : 0; //make sure trackCenter is not negativ
        return trackCenter; //ToDo Remove offset
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
        CONSOLE.println(printedArray);
    }
}
#endif