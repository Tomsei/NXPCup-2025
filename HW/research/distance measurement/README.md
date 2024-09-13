# Distanzmesser
Sammlung aller Relevanten Informationen zum Distanzmesser

### Nutzungsfall
- Erkenne des Würfels (Entfernung)
- Erkennen eines Hindernisses / wand (stehen Bleiben) (optional)
- Sollte in jeder Situation (Debug, Stillstand, Fahrt) angesprochen werden können. 

### Funktionale Anforderung
- Sichtweite: 
    - kleinste sichere Distanz: 2-5cm 
    - größte sichere Distanz: 1 Meter + Größer
- Stüropor erkennen!
- Farbunahbängig
- Update Rate: möglichst schnell, aber nicht so relevant (wegen langsam Fahrt vor Würfel)

Weitere Möglichkeiten zu Lidar Sensoren: [RobotShop](https://eu.robotshop.com/collections/lidar), [Eckstein](https://eckstein-shop.de/search/?qs=Lidar), [Premium-Modellbau](https://www.premium-modellbau.de/multicopter/flightcontroller-sensorik/lidar-sensoren/?p=1), [exp-tech](https://exp-tech.de/collections/lidar-sensoren)

<br>

| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | weitere Infos |
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: | :-----------: |
| **VL53L0X TOF Laser** | **Laser Abstandsmesser** | **- günstig <br> - relevanter Wertebereich** | **- ggf. zu unpräzise (testen)** | **- Auflösung: 1 mm <br> - Schnittstelle: I2C <br> - Betriebsspannung: 2.8V / 3.3V / 5V <br> - Reaktionszeit 50 ms <br> - Distanz: 0mm - 1m** | **7,49€ <br> 12€** | **[AZ-Delivery](https://www.az-delivery.de/products/vl53l0x-time-of-flight-tof-laser-abstandssensor) <br> [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0245?qs=sGAEpiMZZMu3sxpa5v1qrnJwz0aRf2JjCIBsnGk%2FV54%3D)** | **[Tutorial](https://draeger-it.blog/arduino-lektion-103-laser-distanz-sensor-vl53lxx-v2) <br> [Test](https://www.youtube.com/watch?v=cszHgfQ42Oc)** |
| Pololu Distance Sensor | Objektpräsenz Sensor (5 cm) | - 5 cm im Zielbereich <br> - günstig  | - Begrenzt bei 5cm  <br> - keine Distanz <br> - nur Objektpräsenz | - Update Rate: 145 Hz <br> - Betriebsspannung: 3.0 V bis 5.5 V <br> - Distanz: 5cm | 10,36€ | [exp-tech](https://exp-tech.de/products/pololu-digital-distance-sensor-5cm) | [weitere Messbereiche](https://exp-tech.de/collections/lidar-sensoren) |
| Pololu Distance Sensor 50 cm | Lidar basierter Distanzsensor | - Entfernung im benötigten Bereich <br> - günstig | X | - Update Rate: 50 Hz bis 110 Hz <br> - Betriebsspannung: 3.0V bis 5.5V <br> - Distanz: ? bis 50 cm  | 10,36€ <br> 15,41€ | [exp-tech](https://exp-tech.de/products/pulse-width-output-50cm) <br> [Eckstein](https://eckstein-shop.de/PololuDistanceSensorwithPulseWidthOutput2C50cmMax) | X |
| Mini Laser Distance Range | Laser Distanzsensor | - guter Messbereich <br> - 1 CM Ungenauigkeit | - Präzision nicht verifiziert | - Schnittstelle: I2C <br> - Update Rate: 19ms bis 38 ms <br> - Betriebsspannung 3.3-5V <br> - Distanz: 2cm - 400cm | 12,90$ | [DFROBOT](https://www.dfrobot.com/product-2727.html) | [Produkt Wiki](https://wiki.dfrobot.com/Laser_Ranging_Sensor_4m_SKU_SEN0590) |
| VL6180X - Satel | TOF Distanzsensor | - Mouser Einkauf <br> - [Erfahrungsbericht](https://alltag-0815.de/mikrocontroller/entfernungen-messen-vl6180x-tof-distanzsensor-arduino-uno/2724/) zeigt Erkennung von 60 mm | - keine exakte Distanzangabe im Datenblatt <br> - [Negativer Erfahrungsbericht](https://alltag-0815.de/mikrocontroller/entfernungen-messen-vl6180x-tof-distanzsensor-arduino-uno/2724/) | - Betriebsspannung 3.3V - 10 V (eigener 2.8V Regler) <br> - Distanz: ? (60 mm) | 18,54€ | [Mouser]( https://www.mouser.de/ProductDetail/STMicroelectronics/VL6180X-SATEL?qs=Ok1pvOkw6%2FofMptZ1txK%2Bg%3D%3D ) | [Negativer Erfahrungsbericht](https://alltag-0815.de/mikrocontroller/entfernungen-messen-vl6180x-tof-distanzsensor-arduino-uno/2724/) |
| Pololu Distance Sensor 130cm | Kurzstrecken-Lidar-Modul | - guter Messbereich | - ggf. Probleme im Kleinbereich | - Betriebsspannung: 3-5.5V <br> - Update Rate: 100-110 Hz <br> - Distanz: 4cm bis 130 cm | 21,36€ | [Eckstein](https://eckstein-shop.de/PololuDistanceSensorwithPulseWidthOutput2C130cmMax) | X |
| Adafruit VL53L1X | TOF Distanzsensor | - Ab 3 cm können Werte erkannt werden | - nur 50 Hz Update Rate | - Schnittstelle: I2C  <br> - Update Rate: 50 Hz <br> - Distanz: 30 mm bis 4000 mm <br> | 21,50€ | [Eckstein](https://eckstein-shop.de/Adafruit-VL53L1X-Time-of-Flight-Distance-Sensor) | X |
| VL53L5CX ToF | TOF Distanzsensor | - Breiter Wertebereich | X | - Betriebsspannung: 3.3V <br>  - Schnittstelle: I2C <br> - Distanz: 20 mm bis 400 cm  | 22,18€ | [RobotShop](https://eu.robotshop.com/products/vl53l5cx-tof-8x8-zone-distance-sensor-400-cm-carrier-w-voltage-regulator) | X |
| Pololu VL53L8CX | TOF Distanzsensor | - große Reichweite <br> - [bis 2cm erkennbar](https://eckstein-shop.de/Pololu-VL53L8CX-Time-of-Flight-8x8-Zone-Distance-Sensor-Carrier-with-Voltage-Regulators-400cm-Max) | - Nahe präzisiion unklar <br>- teuer | - Betriebsspannung: 3.2-5.5V <br> - Schnittstellen: I2C, SPI <br> - Distanz: 2cm bis 400 cm | 29,69€ | [Eckstein](https://eckstein-shop.de/Pololu-VL53L8CX-Time-of-Flight-8x8-Zone-Distance-Sensor-Carrier-with-Voltage-Regulators-400cm-Max) | X |
| Phidget VINT | TOF Distanzsensor | - guter Messbereich<br> - soll 2 cm erkennen <br> - 1 cm Ungenauigkeit | - teuer <br> - aktuell nicht verfügbar| - update Rate: 30 ms bis 60 ms <br> - Distanz: 20 mm bis 650 mm |  33,37€ | [RobotShop](https://eu.robotshop.com/products/phidget-vint-distance-sensor-650mm) | X |
| *Matek 3901-L0X* | *Lidar-Entfernungsmessung* | *- weitere Distanzen können erkannt werden* | *- ggf. 10 cm nicht erkennbar (Grenze 8 cm) <br> - teuer* | *- UART Interface <br> - Betreibsspannung: 4.5V - 5.5V <br> - Distanz: 8 cm bis 200 cm* | *42,90€* | *[Premium-Modellbau](https://www.premium-modellbau.de/matek-3901-l0x-optical-flow-und-lidar-sensor-fuer-inav)* | *X* |
| LDROBOT LD07 | Kurzdistanz 1D Laser Radar | - guter Messbereich <br> - ggf. Präziser als andere Modelle <br> - klein und leicht | - teurer <br> - Messbereich nur bis 30 cm | - Update Rate: 28 Hz <br> - Schnittstelle: UART <br> - Distanz: 30 mm bis 300 mm  | 43,38€ | [RobotShop](https://eu.robotshop.com/products/ldrobot-ld07-solid-state-lidar-sensor-only) | X |
| Garmin LIDAR-Lite v4 | Lidar basierter Distanzssensor | - großer Wertebereich (ggf. mehr Daten) | - ggf. unpräzise (5cm) <br> - teuer | - Update Rate: 200 Hz <br> - Betriebsspannung 4.75 - 5.25 VDC <br> - Distanz: 5cm bis 10 m| 54,50€ | [exp-tech](https://exp-tech.de/products/garmin-lidar-lite-v4-led-distance-measurement-sensor) | X |


### Ideen zur Verwendung:  
- ggf. Kombination aus zwei Lidar Sensoren (Polulu Distance 5 CM + 50 cm -> doppelte Sicherheit / präzisere Steuerung möglich)
- Lidar nicht ganz vorne anbringen: Umgeht die Probleme im ganz direkten Entfernungsbereich