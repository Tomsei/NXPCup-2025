//Source: https://cdn-reichelt.de/documents/datenblatt/A300/SEN-KY032-ANLEITUNG.pdf
#include <Arduino.h>

int Sensor = 2;

void setupArdLinefinder() {
    pinMode(Sensor, INPUT);
}

void runArdLineFinder() {
    bool val = digitalRead(Sensor);
    if (val == HIGH) {
        Serial.println("ARD Linefinder: HIGH");
    } else {
        Serial.println("ARD Linefinder: LOW");
    }
}