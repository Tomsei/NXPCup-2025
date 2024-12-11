#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

namespace DataVisualisation {

    enum VisualisationLevel { 
        VisualizeLED = 0, 
        VisualizeDisplay = 1, 
        VisualizeBoth = 2 
    };
    
    void clear(int choose);
    void showNumber();

}