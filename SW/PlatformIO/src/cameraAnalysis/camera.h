/**
 * camera - declaration
 * 
 * Handles everything belonging to the Camera SPI Connection. 
 * This includes the administration of the Swapped SPI Buffer 
 * and the setup and use of the spi transfer where Teensy is a slave
 * 
 * using the Library: SPISlave_T4.h
 * https://github.com/tonton81/SPISlave_T4
 * 
 * inspiration for improvments from Tjaekel: 
 * https://forum.pjrc.com/index.php?threads/teensy-4-1-spi-slave-here-it-is.72792/
 * https://github.com/tjaekel/Teesny_4_1
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#ifndef SINGLE_COMPONENTS_TEST

namespace CameraAnalysis {

    namespace OpenMVCam {

        /**
         * setup method for spi connection
         */
        void setup();

        /**
         * update image for the image analysis if there is a new image transfered
         */
        void updateImage();

        /**
         * update the trackCenters for the analyse if new track centers are transfered
         */
        void updateTrackCenters();
    
    };
}
#endif