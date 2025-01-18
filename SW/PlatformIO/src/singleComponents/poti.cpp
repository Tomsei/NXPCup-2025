/**
 * Single component - poti definition
 * 
 * Basic code to test the function of the poti 
 * Read and print the poti value
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

#include <Arduino.h>

namespace SingleComponent {
    
    //no setup needed
    void setupPoti() {
        return;
    }

    /**
     * method to call in loop to print poti values
     */
    void runPoti() {
        int poti1 = analogRead(POTI1);
        int poti2 = analogRead(POTI2);
        if(poti1 > 500 || poti2 > 500) {
            Serial.print("Poti 1: "); Serial.print(poti1);
            Serial.print("\t Poti 2: "); Serial.println(poti2);
        }
    }
}
#endif