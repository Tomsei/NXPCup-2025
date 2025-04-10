# Software-Kit

Das hier enthaltende PlatformIO Projekt und in OpenMV-Script hinterlegte Kameraskript sind die grundlegenden Basiselemente der Software. 

Sie stellen das von mir vorgeschlagene SW-Kit für zukünftige Studierende dar und bietet folgende Implementierung:

1. SPI Verbindung - OpenMV Cam: Die SPI-Verbindung der Kamera, die eine Übertragung von  5 Kamerazeilen durch das Kameraskript ```transferImageLinesSpi.py``` ausführt

2. SPI Verbindung - Teensy: Die Bibliotheksänderungen sowie die Kamera-Datei die zur Annahme der Bilddaten eingesetzt und benötigt werden. Hierbei handelt es sich nur um die reine SPI-Verbindung nicht um die weiteren vorgenommenen Optimierungne.

3. Driving Control - Basisansteuerung von Motor und Servo. 

4. Car Logic - Als Einstiegspunkt der Software / Steuerungen 

Drei und Vier sind auch gewhält worden um erste Ansätze einer möglichen Softwarestruktur aufzuzeigen, was wiederrum für zukünftige Studierende als Inspiration genutzt werden kann.