/**
 * camera - declaration
 * 
 * Handles everything belonging to the Camera SPI Connection. 
 * This includes the administration of the SPI Buffer 
 * and the setup and use of the spi transfer where Teensy is a slave
 * 
 * using the Library: SPISlave_T4.h
 * https://github.com/tonton81/SPISlave_T4
 * 
 * inspiration for library improvments from Tjaekel: 
 * https://forum.pjrc.com/index.php?threads/teensy-4-1-spi-slave-here-it-is.72792/
 * https://github.com/tjaekel/Teesny_4_1
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

namespace CameraAnalysis {

    namespace OpenMVCam {

        /**
         * setup method for spi connection
         */
        void setup();

        /**
         * update image checks if new data available
         * if there is new data, print it
         */
        void updateImage();
    
    }
}