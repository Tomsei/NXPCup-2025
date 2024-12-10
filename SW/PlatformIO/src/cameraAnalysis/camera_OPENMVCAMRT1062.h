void setupCamera();

void runCamera();


namespace OpenMVCam {
    void getImage(uint8_t *pixelData);

    void getImageRow(uint8_t *pixelData, u_int8_t row);
}

