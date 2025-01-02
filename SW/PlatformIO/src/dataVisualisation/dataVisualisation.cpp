#include "dataVisualisation/dataVisualisation.h"

namespace DataVisualisation  {
    /*
    ToDo: Hier werden einfach Methoden erzeugt, die das jeweilige für beides (LED + Display ausführen)
    */
   void setup() {
        Display::setup();
        LedStrip::setup();
   }

    void clear() {
        Display::clear();
        LedStrip::clear();
    }

    void showNumber() {
        Display::showNumber(-1);
        LedStrip::showNumber();
    }
}