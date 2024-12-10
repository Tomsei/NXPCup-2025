#include "configuration/globalConfig.h"

#ifdef SINGLE_COMPONENTS_TEST

//Source: https://cdn-reichelt.de/documents/datenblatt/A300/SEN-KY032-ANLEITUNG.pdf
#include <Arduino.h>

namespace SingleComponent {

    void setupArdLinefinder() {
        pinMode(ARD_LINE_FINDER1, INPUT);
        pinMode(ARD_LINE_FINDER2, INPUT);
        //ToDo: ARD LINE FINDER change to Interrupt)
    }

    bool blackSensor1 = false;
    bool blackSensor2 = false;

    void runArdLineFinder() {
        bool valSensor1 = digitalRead(ARD_LINE_FINDER1);
        bool valSensor2 = digitalRead(ARD_LINE_FINDER2);

        if (valSensor1 == HIGH && blackSensor1) {
            Serial.println("ARD Linefinder 1: Black to White");
            blackSensor1 = false;
        } else if (valSensor1 == LOW && !blackSensor1) {
            Serial.println("ARD Linefinder 1: White to Black");
            blackSensor1 = true;
        }

        if (valSensor2 == HIGH && blackSensor2) {
            Serial.println("ARD Linefinder 2: Black to White");
            blackSensor2 = false;
        } else if (valSensor2 == LOW && !blackSensor2) {
            Serial.println("ARD Linefinder 2: White to Black");
            blackSensor2 = true;
        }
    }
}
#endif