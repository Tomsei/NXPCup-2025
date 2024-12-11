#include "dataVisualisation/display.h"
#include "dataVisualisation/ledStrip.h"

namespace DataVisualisation {

    enum VisualisationLevel { 
        VisualizeLED = 0, 
        VisualizeDisplay = 1, 
        VisualizeBoth = 2 
    };

    void clear(int choose);
    void showNumber();

}