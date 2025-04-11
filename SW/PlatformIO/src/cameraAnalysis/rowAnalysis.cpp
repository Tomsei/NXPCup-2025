/**
 * row analysis - definitions
 * 
 * this file ist relevant if the camera sends image pixel data! (No analysis on camera)
 * 
 * handles everything belonging to the analysis of a single row 
 * a class is used to store all needed data like the sobel values for the row 
 * 
 * the class administrate the data of the single row and anlayse it
 * this includes different steps like: 
 * - calculate sobel
 * - calculate edges
 * - calculate track center
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifndef ANALYSIS_ON_CAMERA

#include "cameraAnalysis/rowAnalysis.h"
#include "cameraAnalysis/cameraAnalysis.h"

namespace CameraAnalysis {

    extern int sobelThreshold;

    /* ------- public known methods ------------------ */

    //comment in .h
    void SingleRowAnalysis::updateRow(uint32_t* pixelData, int row) {
        int startIndexOfLine = row * VIDEO_RESOLUTION_X;
        rowDataBufferPointer = pixelData + startIndexOfLine;
    }

    //comment in .h
    void SingleRowAnalysis::calculateSobelRow() {
        for (int i = 0; i < VIDEO_RESOLUTION_X-2; i++) {
            //int carsting to get negativ values
            sobelRowDataBuffer[i] = ((int(rowDataBufferPointer[i] * 2)) + (int(rowDataBufferPointer[i + 2] * -2)));
        }
    }

    //comment in .h
    uint16_t SingleRowAnalysis::calculateTrackCenter(uint16_t startSearch) {
        auto [leftEdge, rightEdge] = calculateEdges(startSearch); 
        uint16_t trackCenter = (leftEdge + rightEdge) / 2;
        trackCenter = trackCenter + CAM_OFFSET;
        trackCenter = (trackCenter > 0) ? trackCenter : 0; //make sure trackCenter is not negativ
        return trackCenter; 
    }
    
    //comment in .h
    void SingleRowAnalysis::printRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X*/) {
        printArray(rowDataBufferPointer, start, length, "print img row:\t");
    }

    //comment in .h
    void SingleRowAnalysis::printSobelRow(int start /*= 0*/, int length /*= VIDEO_RESOLUTION_X -2*/) {
        printArray(sobelRowDataBuffer, start, length, "sobel row:\t\t");
    }

    /* ------- privat - public unknown methods ------- */

    //comment in .h
    std::tuple<uint16_t, uint16_t> SingleRowAnalysis::calculateEdges(uint16_t startSearch) {
        
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
#endif
#endif