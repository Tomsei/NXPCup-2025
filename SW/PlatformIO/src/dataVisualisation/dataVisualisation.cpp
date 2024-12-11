#include "dataVisualisation/dataVisualisation.h"
#include "dataVisualisation/display.h"

void DataVisualisation::clear(int choose) {
    if(choose == 0) 
        clearDisplay();
    else if (choose == 1)
        //clear LED
        clearDisplay();
    else if (choose == 2)
        clearDisplay();
        //clear LED
}


void DataVisualisation::showNumber() {
    showNumberDisplay();
}

