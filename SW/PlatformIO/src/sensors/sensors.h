namespace Sensors {

    struct rawSensorData {
        int tofDistance;
        int opticalFlowX;
        int opticalFlowY;
    };
    
    void setup();
    void update();
    void printData();
}