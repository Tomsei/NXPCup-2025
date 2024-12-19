#include "dataVisualisation/dataVisualisation.h"

namespace DataVisualisation  {
    /*
    ToDo: Hier werden einfach Methoden erzeugt, die das jeweilige für beides (LED + Display ausführen)
    */
   void setup() {
        Display::setup();
   }

    void clear() {
        Display::clear();
        LedStrip::clear();
    }

    void showNumber() {
        Display::showNumber();
        LedStrip::showNumber();
    }
}