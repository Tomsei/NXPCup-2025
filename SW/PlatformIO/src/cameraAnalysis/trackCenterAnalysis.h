/**
 * track center analysis - declaration
 * 
 * this file ist relevant if the camera sends trackcenter data! (analysis on camera)
 * 
 * handles everything belonging to the trackcenter analysis.
 * This includes the generala camera analysis method (same structure like other approach)
 * which conrols the complete analysis of Trackcenters.
 * 
 * For the management of the track center analysis the TrackCenterAnalysis class is used.
 * This class is also implemented in this file and provides methods to
 * - manage all data belonging to track center analysis
 * - calculate speed
 * - calculate steering angle
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifndef SINGLE_COMPONENTS_TEST
#ifdef ANALYSIS_ON_CAMERA

#include "Arduino.h"
#include "configuration/cameraAnalysisConfig.h"

extern volatile int imageAnalysIsComplete;

namespace CameraAnalysis {

    /**
     * setup camera analysis
     * trigger the OpenMVCam (spi setup) and initiate current trackcenters
     */
    void setup();

    /**
     * trys to update track center data and analyze it 
     * if there is new data to calculate speed, and steering angle
     * 
     * uses all sup methods and the Track Center Analysis class 
     * to check if the new data is valid and to calculate and store the analyzed data
     * 
     * @param enableFinishLineDetection: flag to decide if finish line detection is on 
     */
    void analyse(bool enableFinishLineDetection);

    /**
     * getter for the calculatet steering angle (map it usable servo value)
     * @return steering angle
     */
    int getSteeringAngle();

    /**
     * getter for the calculatet speed
     * @return speed
     */
    uint8_t getSpeed();

    /**
     * class for the analysis of the track center data
     */
    class TrackCenterAnalysis {

        public:
        
            uint32_t* trackCenters;
            int16_t trackCenterOffset[VIDEO_RESOLUTION_Y];
            int lastStraightLine;
            int lastSteeringLine;
            int steeringAngle;
            uint8_t speed;
            uint8_t choosenBaseSpeed;
            bool enableFinishLineDetection;
            static bool finishLineDetected;
            static uint64_t finishLineDetectedTime;

            /**
             * update track center data pointer
             * @param trackCenterData: pointer new track center data
             */
            void updateTrackCenters(uint32_t* trackCenterData);

            /**
             * calculates the steering anlge for the current track centers
             * determine the steering row and use the trackcenter offset of this row
             * by scaling it to an usable steering angle.  
             */
            void calculateSteeringAngle();

            /**
             * calculates the speed for the current track centers
             * depending on the straight track centers ahead the speed is choosen
             */
            void calculateSpeed();
            
            /**
             * print the track centers
             * @param start: startpixel where print should begin
             * @param length: amount of pixel to print
             */
            void printTrackCenters(int start = 0, int lenght = VIDEO_RESOLUTION_Y);

            
            /**
             * print the track centers offsets
             * @param start: startpixel where print should begin
             * @param length: amount of pixel to print
             */
            void printTrackCenterOffsets(int start = 0, int lenght = VIDEO_RESOLUTION_Y);
            
    };

}

#endif
#endif