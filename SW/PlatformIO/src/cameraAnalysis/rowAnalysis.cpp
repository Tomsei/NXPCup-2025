#include "cameraAnalysis/rowAnalysis.h"
#include "cameraAnalysis/cameraAnalysis.h"

#define CAM_OFFSET -7

namespace CameraAnalysis {

    extern int sobelThreshold;

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
}