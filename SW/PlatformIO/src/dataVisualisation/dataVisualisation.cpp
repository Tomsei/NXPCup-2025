#include "dataVisualisation/dataVisualisation.h"

namespace DataVisualisation  {

    void clear(VisualisationLevel level) {
        if (level == VisualizeLED)
            return; //clearLed();
        else if (level == VisualizeLED)
            return; //clearDisplay();
        else if (level == VisualizeLED) {
            return; //clearLed();
            //clearDisplay();
        }
    }

    /* ToDo: Gedanken machen! - Die Datei Data Visualisation ist unnötig 
    - ein reines weiterreichen von Funktionen
    - stattdessen statische klassen von Display und LED Strip erstellen die
    dann jeweils aufgerunfen werden können
    - einzige Logik war bisher, dass hier gebündelt werden konnte wenn beide 
    gleichzeitig anzeigen sollen. Dies kann aber auch mit zwei Befehlen im 
    Anfwendungsfall ohne Probleme passieren.

    ToDo - Das könnte eine reine übergeordnete Steuerung werden, durch welche Display... inkludiert werden
    und kombinationen gebündelt werden (bsp. clear - ...)
    */
    void showNumber(VisualisationLevel level) {
        if (level == VisualizeLED)
            return;// showNumberLed();
        else if (level == VisualizeDisplay)
            return;//showNumberDisplay();
        else if (level == VisualizeBoth) {
            return;//showNumberLed();
            //showNumberDisplay();
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