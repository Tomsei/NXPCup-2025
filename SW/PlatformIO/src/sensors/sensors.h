#include <Arduino.h>
namespace Sensors {

    struct rawSensorData {
        int tofDistance;
        int16_t opticalFlowX;
        int16_t opticalFlowY;
        int16_t imuAX;
        int16_t imuAY;
        int16_t imuAZ;
        int16_t imuGX;
        int16_t imuGY;
        int16_t imuGZ;
        bool linefinder1;
        bool linefinder2;
    };
    
    void setup();
    void updateRawData();
    void printData();
}