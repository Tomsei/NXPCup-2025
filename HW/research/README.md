# Recherche

Dieser Bereich dient zur Übersicht der Recherche Ergebnisse für die verwendeten Komponenten des Automodells.

Jede relevante Komponente hat einen eigenen Unterordner mit einer eigenen README, in welcher alle Rechercheergebnisse und möglichen Komponenten hinterlegt sind. Ebenso kann dort ein weitere Ordner für spezifische Informationen zu jeweiligen Komponenten angelegt werden.

**Erläuterung Formatierung:** Die Formatierung gilt für alle detaillierten Komponentendateien.
- **Fett:** Genutzt in einem Kit Vorschlag
- normal: relevante Option, aber in keinem Kit Vorschlag
- *kursiv*: Option die "irrelevant" geworden ist (Historie, aber nicht realistisch)

<br>
Hier werden lediglich die besten Zusammenstellungen der Komponente festgehalten und zu einem gemeinsamen Kit mit den Relevanten Informationen zusammen geführt.

Nach Beendigung der Recherche Phase sollen die Schriftlichen Erkenntnisse ins Wiki übertragen werden und alle Relevanten Dokumente in den Hardware Ordner integriert werden.

# Kit 1 - Mikrocontroller (Teensy) + eigene Platine
| Komponente | Beschreibung | Bestellung / Link | Preis | Begründung der Auswahl | Details/Datenblatt | Notizen | Pflicht |
| :--------: | :-------: | :---------------: | :---: | :--------------------: | :-----: | :-----:| :------: |
| Bodenplatte                   | M210R - Car Racing Kit | [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz) | 158,95€ | - Gute Rezensionen <br> - Preisleistung  | [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz) | - fertig Bausatz <br> - Alternative Kit Möglichkeiten | &check; |
| Lenksystem                    | M210R - Car Racing Kit | [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz) | X | - Ackermannlenkung <br> - Preisleistungsverhältnis (Kit)| [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz) | - fertig Bausatz <br> - Alternative Kit Möglichkeiten | &check; |
| Räder / Reifen                | M210R - Car Racing Kit | [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz)  | X | - inkludiert im Kit | [Berlinski](https://www.modellbau-berlinski.de/rc-fahrzeuge-und-zubehoer/autos-und-zubehoer/elektro-onroad/m210r-1_10-on-road-4wd-m-chassis-kohlefaser-bausatz) | - ggf. Eigenbau | &check; |
| Kamerahalterung               | 3D Modelle der Kamera | [Modell 1](https://grabcad.com/library/tripod-1-4-20-1-2mm-styled-board-mount-1) <br> [Modell 2](https://grabcad.com/library/tripod-1-4-20-1-2mm-flat-board-mount-1) <br> [Modell 3](https://grabcad.com/library/gopro-1-2mm-board-mount-1) | 5€ | Mit Kamera mitgegeben | [OpenMV Downloads](https://openmv.io/products/openmv-cam-rt) | - 3D Druck zur Not per Unternehmen | &check; |
| Akku | 3 AH S3 Lipo | [Rechelt](https://www.reichelt.de/akku-pack-li-polymer-11-1-v-3000-mah-rd-xt-3000-s3-p336967.html?&trstct=pol_2&nbc=1) | 34,20€ | - ausreichen Stark für Motoren | [Datenblatt reichelt](https://www.reichelt.de/akku-pack-li-polymer-11-1-v-3000-mah-rd-xt-3000-s3-p336967.html?&trstct=pol_2&nbc=1)  | - Es braucht ein [Lipo Quard](https://www.reichelt.de/brandschutzbeutel-fuer-li-polymer-akkus-lipo-guard-p108492.html) | &check; | 
| Prozessor - Board             | Teensy 4.1 | [Reichelt](https://www.reichelt.de/teensy-4-1-usb-mit-header-teensy-4-1-h-p318654.html) | 44,95€ <br> + 15€  | - Rechenstark <br> - viele Pins <br> - gute Programmierung | [Teensy Datenblatt](https://www.pjrc.com/store/teensy41.html) | - Eigene Verkabelungsplatine (15€) | &check; |
| Motorset                       | Set Dragster Turbo 4370 KV  | [Berlinski](https://www.modellbau-berlinski.de/rc-antriebe/combos/auto/brushless-1_10/1_10-brushless-set-dragster-turbo-4370-kv) | 64,95€ | - Leistungsstark <br> - ausreichende Drehzahl, Beschleunigung | [Datenblatt](https://cdn.simba-dickie-group.de/downloads/500906301/500906301_Anleitung-Instruction_FahrreglerCombo_80x130mm_05-2023.pdf) | - benötigt ggf. teuren Akku | &check; |
| Geschwindigkeitsmessung       | Optical Flow Sensor | [Mouser](https://www.mouser.de/ProductDetail/Pimoroni/PIM453?qs=PzGy0jfpSMuJnlsymXyulA%3D%3D) | 22,32€ | - Messbare Fahrzeuggeschwindigkeit <br> - 2 Achsen messbar | [Datenblatt](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/306/PIM453_Web.pdf) | - **Funktionsfähigkeit verfizieren!** <br> - ggf. später alternatives System | &check; |
| Servo                         | ToDo | ToDo | ToDo ca 30€ | ToDo | ToDo | - bestehender Servo <br> Kit Kompatibilität prüfen! | &check; |
| Kamera                        | Programmierbare Kamera | [OpenMV](https://openmv.io/products/openmv-cam-rt) <br> [Robotshop](https://eu.robotshop.com/de/products/openmv-cam-rt1062)  | 133,46€ | - Rechenstarker NXP Chip <br> - auf Kamera Programmierbar  | [Kamera Datenblatt](https://pdf1.alldatasheet.com/datasheet-pdf/view/587044/OMNIVISION/OV5640.html) <br>[NXP-Prozessor](https://cdn.shopify.com/s/files/1/0803/9211/files/IMXRT1060IEC.pdf?v=1681075136) | - WiFi Chip entfernen / absprechen | &check; |
| Distanzmesser                 | ToF Distanzsensor | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0245?qs=sGAEpiMZZMu3sxpa5v1qrnJwz0aRf2JjCIBsnGk%2FV54%3D) | 12€ | - günstig + präzise | [Datenblatt](https://www.mouser.de/datasheet/2/830/en_DM00279086-2488743.pdf) | - Ansteuerung von mehreren (3) verifizieren | &check; |
| Spannungswandler              | Buck Converter | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/DFR0379?qs=5aG0NVq1C4zPqXmLzkhO%252Bg%3D%3D) | 4,56€ <br> 9,12€ | - funktionsfähigkeit bestätigt | [Dateblatt](https://www.mouser.com/pdfDocs/ProductOverview-DFRobot-DFR0379.pdf) | - gleicher wie letztes mal <br> - ggf. 2 Stück | &check; |
| An-Ausschalter + Mossfett     | Wippschalter | [Mouser](https://www.mouser.de/ProductDetail/E-Switch/RA1113112R?qs=QtyuwXswaQh2BdIH9uXjxQ%3D%3D&mgh=1) | 0,62€ + 6,76€ | - klein günstig | [Schalter Datenblatt](https://www.mouser.de/datasheet/2/140/RA1113112R-3457780.pdf) [Mosfet Datenblatt](https://www.mouser.de/datasheet/2/196/Infineon_IPP_I_110N20N3G_IPB107N20N3G_DS_v02_03_en-1731855.pdf) | - Mossfet für Motorcut notwendig [Mouser](https://www.mouser.de/ProductDetail/Infineon-Technologies/IPP110N20N3-G?qs=nTClRYuuQBpD3R4g85pVvA%3D%3D) | &check; |
| Dip Switch              | Dip - Schalter 8 | [Mouser](https://www.mouser.de/ProductDetail/TE-Connectivity-Alcoswitch/GDH08S04?qs=BsFx%2FYdFsHvwInVJQojXdw%3D%3D) | 2,33€ | - 8 Schalter für mehr konfiguration | [Datenblatt](https://www.mouser.de/datasheet/2/418/3/NG_CS_1308111-1_SWITCHES_CORE_PROGRAM_CATALOG_0308-1234738.pdf) | - ggf. bei Platinenkauf auflöten lassen | &check; |
| IMU (Inertiale Messeinheit)   | IMU | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0142?qs=Zcin8yvlhnO0Rr0B1JJGiw%3D%3D) | 9,21€ | - bekannt <br> - beschleunigung + orientiertswerte | [Datenblatt](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) | - einer liegt auf Kamera | &cross; |
| Display                      | RPI OLED 1,3 Joy | [Reichelt](https://www.reichelt.de/raspberry-pi-display-oled-1-3-inkl-joystick-sh1106-rpi-oled-1-3-joy-p242789.html?&trstct=pos_0&nbc=1) | 13,30| - günstig + klein <br> - reicht aus | [Datenblatt](https://www.waveshare.com/wiki/1.3inch_OLED_HAT) | - sollte Lininen anzeigen können <br> - [Mouser Äquivalent](https://www.mouser.de/ProductDetail/SparkFun/LCD-23453?qs=dbcCsuKDzFWY6i0I%252BKeCWA%3D%3D) | &cross; |
| LED-Stribes-Anzeige           | NeoPixel 3094 | [Mouser](https://www.mouser.de/ProductDetail/Adafruit/3094?qs=SV%252B0z0o3NTt%2F2YK7E3w5Rg%3D%3D) | 2,70€ <br> (27,85€) | - auf eigener Platine gut positionierbar | [Datenblatt](https://www.adafruit.com/product/3094) | - par LEDS auf eigenes Board | &cross; |
| WiFi                          | X | X | X | X | X | - auf Kamera vorliegend  | &cross; |

**Gesamtkosten:** 564,25€ | Optional: verkleinert auf 519€ (Sachen "verschlechtern")

### Vorteile:
- Eigene Platine bietet zuverlässigkeit und es liegt in der **eigenen Kontrolle (Veränderungen möglich)**
- Mikrocontroller basiert 
- Programmierung in C, C++ / Mikro Python | Teensy: Matlab Simulink
- Programmierumgebung Teensy: Arduino IDE, Plattform IO, [MCU Expresso](https://de.scribd.com/document/479726952/MCUXpresso-Instructions)
- Programmierumgebung Kamera: OpenMV IDE für CAM
- Eigene Kameraauswertung auf Camerachip selbst möglich (viel einfacher als bei Pixy)
- Leistungsstarkes Chassis + Hardwaregrundlage (Motor...)
- Vollständige Sensorik + optionale Sensorik
- Vergleichbare Leistung wie Single Board Computer - Kamera Chip + Tennsy zusammen!
- Einzelbauteile ersetzbar
- System 1 zu 1 mit vorhandener Pixy kompatibel

### Nachteile:
- hoher Montageaufwand (6h Aufbauphase)
- Vereinzelnte Komponenten müssen verifiziert werden (Optical Flow Sensor, Distanzmesser)
- keine Informationen über die Rad / Motorgeschwindigkeit -> Nur Geschwindigkeit des gesamten Autos in 2 Diemension
- Kamera WiFi Chip ggf. abmontieren
- 1 Bohrung durch Karbonfaser

### Bedingungen / Schritte / Weiteres:
- Absprache mit NXP wegen WiFi Chip auf Kamera
- Keine offizielle Platine - HW-Kit enthällt aber Schaltpläne und Kaufmöglichkeit
- Sensoraustausch vor Bestellung des Kits möglich
- 3D Druck notwendig für Halterung der Kamera (Dateien verfügbar)

<br>
<br>


# Kit 2 - Singel Board Computer
### Unterschiede:
- Prozessor
- Kamera
    - Kamerahalterung
    - WiFi
    

| Komponente | Beschreibung | Bestellung / Link | Preis | Begründung der Auswahl | Details | Notizen | Pflicht |
| :--------: | :----------: | :---------------: | :---: | :--------------------: | :-----: | :-----: |:------: |
| Prozessor - Board             | DEBIX Model A | [Conrad](https://www.conrad.de/de/p/debix-model-a-2-gb-4-x-1-8-ghz-2625844.html) | 69,99€ | - Pi ähnlich <br> - Rächenstärker als typische Mikrocontroller <br> - OS ermöglicht Nutzung von OpenCV | [Technische Daten](https://www.conrad.de/de/p/debix-model-a-2-gb-4-x-1-8-ghz-2625844.html#modal-productTechDataOffCanvasFlyout) | - hat inkludiertes WiFi | &check; |
| Kamera                        | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Kamerahalterung               | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| WiFi                          | X | X | X | X | X | - im SBC integriert | &cross; |


<br>
<br>


# Kit 3 - günstigere Möglichkeiten
### Unterschiede:
- Brushed Motor (Leistungsschwächer)
- Racing Car Kit
- günstigerer Akku
- Teensy 4.0
- keine Optionalen Teile

| Komponente | Beschreibung | Bestellung / Link | Preis | Begründung der Auswahl | Details | Notizen | Pflicht |
| :--------: | :----------: | :---------------: | :---: | :--------------------: | :-----: | :-----: |:------: |
| ToDo | ToDo | ToDo | ToDo | ToDo | ToDo | ToDo | ToDo |



<br>
<br>


# Liste von weiteren möglichen Shops:
- [DERKUM Modellbaum](https://www.derkum-modellbau.com/)
- [F+K MOdellbau](https://www.fundkmodellbau.de/#standort) (Vor Ort könnten ggf. spezifische Fragen gestellt werden)
- [YFROBOT](https://yfrobot.com/en-de/collections/all)