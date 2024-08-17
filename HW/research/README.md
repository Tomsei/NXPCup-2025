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
| Bodenplatte                   | ToDo | ToDo | ToDo | ToDo | ToDo | - fertig Bausatz | &check; |
| Räder / Reifen                | ToDo | ToDo | ToDo | ToDo | ToDo | - ggf. Eigenbau | &check; |
| Lenksystem                    | ToDo | ToDo | ToDo | ToDo | ToDo | - fertig Bausatz | &check; |
| Kamerahalterung               | 3D Modelle der Kamera | [Modell 1](https://grabcad.com/library/tripod-1-4-20-1-2mm-styled-board-mount-1) <br> [Modell 2](https://grabcad.com/library/tripod-1-4-20-1-2mm-flat-board-mount-1) <br> [Modell 3](https://grabcad.com/library/gopro-1-2mm-board-mount-1) | X | Mit Kamera mitgegeben | [OpenMV Downloads](https://openmv.io/products/openmv-cam-rt) | X | &check; |
| Prozessor - Board             | kleiner Mikrocontroller | [Teensy 4.1](https://www.reichelt.de/teensy-4-1-usb-ohne-header-teensy-4-1-p283580.html) | 39,90€ | - Rechenstark <br> - viele Pins <br> - gute Programmierung | [Teensy Datenblatt](https://www.pjrc.com/store/teensy41.html) | - Eigene Verkabelungsplatine | &check; |
| Motoren                       | ToDo: Brushles Motor wählen | ToDo | ToDo | ToDo | ToDo | - ggf. fertig Bausatz | &check; |
| Motortreiber - ESC            | ToDo: passend zum Motor! | ToDo | ToDo | ToDo | ToDo | - ggf. fertig Bausatz | &check; |
| Geschwindigkeitsmessung       | Optical Flow Sensor | [Mouser](https://www.mouser.de/ProductDetail/Pimoroni/PIM453?qs=PzGy0jfpSMuJnlsymXyulA%3D%3D) | 22,32€ | - Messbare Fahrzeuggeschwindigkeit <br> - 2 Achsen messbar | [Datenblatt](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/306/PIM453_Web.pdf) | - **Funktionsfähigkeit verfizieren!** <br> - ggf. später alternatives System | &check; |
| Servo                         | ToDo | ToDo | ToDo | ToDo | ToDo | - ggf. fertig Bausat <br> - sonst bestehender  | &check; |
| Kamera                        | Programmierbare Kamera | [OpenMV](https://openmv.io/products/openmv-cam-rt) <br> [Robotshop](https://eu.robotshop.com/de/products/openmv-cam-rt1062)  | 133,46€ | - Rechenstarker NXP Chip <br> - auf Kamera Programmierbar  | [Kamera Datenblatt](https://pdf1.alldatasheet.com/datasheet-pdf/view/587044/OMNIVISION/OV5640.html) <br>[NXP-Prozessor](https://cdn.shopify.com/s/files/1/0803/9211/files/IMXRT1060IEC.pdf?v=1681075136) | - WiFi Chip entfernen / absprechen | &check; |
| Distanzmesser                 | ToF Distanzsensor | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0245?qs=sGAEpiMZZMu3sxpa5v1qrnJwz0aRf2JjCIBsnGk%2FV54%3D) | 12€ | - günstig + präzise | [Datenblatt](https://www.mouser.de/datasheet/2/830/en_DM00279086-2488743.pdf) | - Ansteuerung von mehreren (3) verifizieren | &check; |
| Spannungswandler              | Buck Converter | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/DFR0379?qs=5aG0NVq1C4zPqXmLzkhO%252Bg%3D%3D) | 4,56€ <br> 9,12€ | - funktionsfähigkeit bestätigt | [Dateblatt](https://www.mouser.com/pdfDocs/ProductOverview-DFRobot-DFR0379.pdf) | - gleicher wie letztes mal <br> - ggf. 2 Stück | &check; |
| An-Ausschalter + Mossfett     | Wippschalter | [Mouser](https://www.mouser.de/ProductDetail/E-Switch/RA1113112R?qs=QtyuwXswaQh2BdIH9uXjxQ%3D%3D&mgh=1) | 0,62€ + 6,76€ | - klein günstig | [Schlater Datenblatt](https://www.mouser.de/datasheet/2/140/RA1113112R-3457780.pdf) [Mosfet Datenblatt](https://www.mouser.de/datasheet/2/196/Infineon_IPP_I_110N20N3G_IPB107N20N3G_DS_v02_03_en-1731855.pdf) | - Mossfet für Motorcut notwendig [Mouser](https://www.mouser.de/ProductDetail/Infineon-Technologies/IPP110N20N3-G?qs=nTClRYuuQBpD3R4g85pVvA%3D%3D) | &check; |
| IMU (Inertiale Messeinheit)   | IMU | [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0142?qs=Zcin8yvlhnO0Rr0B1JJGiw%3D%3D) | 9,21€ | - bekannt <br> - beschleunigung + orientiertswerte | [Datenblatt](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) | X | &check; |
| Einstellschalter              | Dip - Schalter 8 | [Mouser](https://www.mouser.de/ProductDetail/TE-Connectivity-Alcoswitch/GDH08S04?qs=BsFx%2FYdFsHvwInVJQojXdw%3D%3D) | 2,33€ | - 8 Schalter für mehr konfiguration | [Datenblatt](https://www.mouser.de/datasheet/2/418/3/NG_CS_1308111-1_SWITCHES_CORE_PROGRAM_CATALOG_0308-1234738.pdf) | X | &check; |
| **Display - nochmal prüfen (Mouser)**                      | 1,3 OLED I2C | [Az-Delivery](https://www.az-delivery.de/products/1-3zoll-i2c-oled-display) | 8,99€ | - günstig + klein <br> - reicht aus | [Datenblatt](https://www.az-delivery.de/products/1-3zoll-i2c-oled-display) | - sollte Lininen anzeigen können | &cross; |
| LED-Stribes-Anzeige           | ToDo | ToDo | ToDo | ToDo | ToDo | - par LEDS auf unser Board  | &cross; |
| WiFi                          | X | X | X | X | X | - auf Kamera vorliegend  | &cross; |

**Gesamtkosten:**

### Vorteile:
- Eigene Platine bietet Flexibilität
### Nachteile:
- Platine eigenbau (muss angefertigt werden) -> KIT enthält aber Schaltpläne!
### Bedingungen / Schritte:
- Absptrache mit NXP wegen WiFi Chip auf Kamera


# Kit 2 - Singel Board Computer
| Komponente | Beschreibung | Bestellung / Link | Preis | Begründung der Auswahl | Details | Notizen | Pflicht |
| :--------: | :----------: | :---------------: | :---: | :--------------------: | :-----: | :-----: |:------: |
| Bodenplatte                   | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Räder / Reifen                | ToDo | ToDo | ToDo | ToDo | ToDo |- ggf. Eigenbauersatz | &check; |
| Lenksystem                    | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Kamerahalterung               | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Prozessor - Board             | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Motoren                       | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Motortreiber - ESC            | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Geschwindigkeitsmessung       | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Servo                         | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Kamera                        | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Distanzmesser                 | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Spannungswandler              | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| An-Ausschalter                | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| IMU (Inertiale Messeinheit)   | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Einstellschalter              | ToDo | ToDo | ToDo | ToDo | ToDo |  | &check; |
| Display                       | ToDo | ToDo | ToDo | ToDo | ToDo |  | &cross; |
| LED-Stribes-Anzeige           | ToDo | ToDo | ToDo | ToDo | ToDo |  | &cross; |
| WiFi                          | ToDo | ToDo | ToDo | ToDo | ToDo |  | &cross; |

**Gesamtkosten:**

### Vorteile:
### Nachteile:
### Bedingungen / Schritte:
- Bsp. Absprachen mit NXP (Wifi)



# Kit 3 - Mikrocontroller (FRDM)




# Liste von weiteren möglichen Shops:
- [DERKUM Modellbaum](https://www.derkum-modellbau.com/)
- [F+K MOdellbau](https://www.fundkmodellbau.de/#standort) (Vor Ort könnten ggf. spezifische Fragen gestellt werden)
- [YFROBOT](https://yfrobot.com/en-de/collections/all)