#pragma once

namespace CameraAnalysis {

    class OpenMVCam {
        public:
            static void setup();
            static void runCamera();
            static void getImage(uint8_t *pixelData);
            static void getImageRow(uint8_t *pixelData, u_int8_t row);
    };
}

