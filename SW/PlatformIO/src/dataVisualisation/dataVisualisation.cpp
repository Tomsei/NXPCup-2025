#include "dataVisualisation/dataVisualisation.h"
#include "dataVisualisation/display.h"
#include "dataVisualisation/ledStrip.h"

namespace DataVisualisation  {

    void clear(VisualisationLevel level) {
        if (level == VisualizeLED)
            clearLed();
        else if (level == VisualizeLED)
            clearDisplay();
        else if (level == VisualizeLED) {
            clearLed();
            clearDisplay();
        }
    }

    /* ToDo: Gedanken machen! - Die Datei Data Visualisation ist unnötig 
    - ein reines weiterreichen von Funktionen
    - stattdessen statische klassen von Display und LED Strip erstellen die
    dann jeweils aufgerunfen werden können
    - einzige Logik war bisher, dass hier gebündelt werden konnte wenn beide 
    gleichzeitig anzeigen sollen. Dies kann aber auch mit zwei Befehlen im 
    Anfwendungsfall ohne Probleme passieren.
    */
    void showNumber(VisualisationLevel level) {
        if (level == VisualizeLED)
            showNumberLed();
        else if (level == VisualizeDisplay)
            showNumberDisplay();
        else if (level == VisualizeBoth) {
            showNumberLed();
            showNumberDisplay();
        }
    }
}

/*

Versuch einer Klasse

Datavisualisierung



led.showNumber()

display.showNumber()

led.showNumber();
display.showNumber();



*/