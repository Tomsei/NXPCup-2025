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
| MPU6050 Beschleunigungssensor | 3 Beschleunigungsachsen <br> 3 Lageachsen | - günstig | - Präzision unklar | - I2C Anbindung <br> - 6 Achsen | 4,99€ | [Conrad](https://www.conrad.de/de/p/joy-it-mpu6050-beschleunigungssensor-1-st-passend-fuer-entwicklungskits-bbc-micro-bit-arduino-raspberry-pi-rock-pi-2136256.html) | X |
| **SEN0142** | **6 DOF Sensor** | **- günstig <br> - positive Erfahrung mit gleicher Serie** | **X** | **[Datenblatt](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)** | **9,21€** | **[Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0142?qs=Zcin8yvlhnO0Rr0B1JJGiw%3D%3D)** | **X** | 