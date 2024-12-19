#include "dataVisualisation/display.h"
#include "dataVisualisation/ledStrip.h"

namespace DataVisualisation {

    //ToDo: Remove
    enum VisualisationLevel { 
        VisualizeLED = 0, 
        VisualizeDisplay = 1, 
        VisualizeBoth = 2 
    };

    void setup();
    void clear();
    void showNumber();

}