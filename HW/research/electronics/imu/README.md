# IMU
Sammlung aller Relevanten Informationen zum IMU

### Nutzungsfall
- Informationen über die Bewegungen im Raum.
- Debug-Fahrt Validierung der gegebenen Daten (kann Geschwindigkeit... stimmen)
- Kalibireren
- ggf. Alternative / Ergänzung zur Geschwindigkeitsmessung
- ggf. Ergänzung zur Ziellinien Erkennung.

### Funktionale Anforderung
- Update Rate Richtung: 500 - 1000/Sekunde
- Update Rate Orientierung: 100/sekunde 
- geringe Schwankungen (bspw. unter 5° Schwankung je 10 Sekunden) 

| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | weitere Infos |
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: | :-----------: |
| Adafruit's 9DOF | Schnell Sensordaten zur Orientierung erhalten | X | X | - I2C Anbindung (0x28 / 0x29) | 34,95$ | [adafruit](https://www.adafruit.com/product/2472) | [Arduino Tutorial](https://learn.adafruit.com/adafruit-9-dof-imu-breakout/introduction) |
| MPU6050 Beschleunigungssensor | 3 Beschleunigungsachsen <br> 3 Lageachsen | X | X | - I2C Anbindung <br> - 6 Achsen | 4,99€ | [Conrad](https://www.conrad.de/de/p/joy-it-mpu6050-beschleunigungssensor-1-st-passend-fuer-entwicklungskits-bbc-micro-bit-arduino-raspberry-pi-rock-pi-2136256.html) | X |