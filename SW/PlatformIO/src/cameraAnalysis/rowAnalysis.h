/**
 * row analysis - declaration
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
#include "configuration/cameraAnalysisConfig.h"
#ifndef SINGLE_COMPONENTS_TEST
#ifndef ANALYSIS_ON_CAMERA
#include "Arduino.h"

namespace CameraAnalysis {

    /**
     * class for the analysis of a single row
     */
    class SingleRowAnalysis {
        public:
            uint32_t* rowDataBufferPointer;
            int sobelRowDataBuffer[VIDEO_RESOLUTION_X-2];

            /**
             * update the row data to new row data
             * set rowDataBuffer to the data that should be analysed
             * @param pixelData: the data (image) to analyse
             * @param row: the row of the image that should get analysed
             */
            void updateRow(uint32_t* pixelData, int row);

            /**
             * calculate the sobel values for the row and store it in sobelRowDataBuffer
             */
            void calculateSobelRow();

            /**
             * calculate the track center
             * get the left and right edge and calculate the center
             * @param startSearch: start pixel to look for left and right edge
             * @return trackCenter: the center of the track
             */
            uint16_t calculateTrackCenter(uint16_t startSearch);
            
            /**
             * print the row
             * @param start: startpixel 
             * @param length: the amount of pixel to print
             */
            void printRow(int start = 0, int length = VIDEO_RESOLUTION_X);

            /**
             * print the calculatet sobel row
             * @param start: startpixel 
             * @param length: the amount of pixel to print
             */
            void printSobelRow(int start = 0, int length = VIDEO_RESOLUTION_X -2);
        
        private:
            /**
             * calulate the track edges of the row
             * just checking if the sobelThreshold is high enough to be an edge
             * it starts from a beginning point and track the first edge to left and right of it
             * it just calculate one edge to each direction (the first)
             * @param startSearch: the pixel to start looking left and right
             * @return {leftEdge, rightEdge}: a tupel of the left and right Edge 
             */
            std::tuple<uint16_t, uint16_t> calculateEdges(uint16_t startSearch);

    };
}
#endif
#endif