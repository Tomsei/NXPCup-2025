# Display
Sammlung aller Relevanten Informationen zum Display

### Nutzungsfall:
- Muss während der finalen Fahrt nichts tun!
- Startkonfigurationen **anzeigen** 
- Debuginformationen nach Fahrt anzeigen 
- Ermöglichen einer Debug Fahrt

### Funktionale Anforderungen:
- 2 Sekunden Refresh Time
- Lesbarkeit bei langsamer Fahrt
- Option einer Grafik anzeige (Geschwindigkeitsbalken...)
- Größe nicht zu groß! (max. 14cm Diagonale)
- optional: aktuelles Kamerabild anzeigen  
- optional: aktuell geplante Fahrlinie anzeigen



| Name | Beschreibung | Vorteile | Nachteile | Technische Details |  Kosten | Link | weitere Infos |
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: | :-----------: |
| **RPI OLED 1,3 Joy** | **- Einfaches Display für Text** | **- Einfache anbindung <br> - Kapazität schonend <br> - geringer Stromverbrauch <br> - Integration von Buttons** | **- eingeschränkt in der Ausgabe** | **- [Datenblatt](https://www.waveshare.com/wiki/1.3inch_OLED_HAT) <br>- Schnittstelle: I2C** | **13,30€** | **[Reichelt](https://www.reichelt.de/raspberry-pi-display-oled-1-3-inkl-joystick-sh1106-rpi-oled-1-3-joy-p242789.html?&trstct=pos_0&nbc=1)** | X |
| OLED I2C Display | - Einfaches Display für Text | - Einfache anbindung <br> - Kapazität schonend <br> - geringer Stromverbrauch | - eingeschränkt in der Ausgabe | - Schnittstelle: I2C | 8,49€ | [Az-Delivery](https://www.az-delivery.de/products/1-3zoll-i2c-oled-display) | [Tutorial](https://maker.pro/raspberry-pi/projects/raspberry-pi-monitoring-system-via-oled-display-module) |
| LCD-23453 | Einfaches Display | - Einfache anbindung <br> - Kapazität schonend <br> - geringer Stromverbrauch | - Lange Lieferzeit | - Schnittstelle: I2C | 13,90€ | [Mouser](https://www.mouser.de/ProductDetail/SparkFun/LCD-23453?qs=dbcCsuKDzFWY6i0I%252BKeCWA%3D%3D) | X |
| Elecrom für Raspberry Pi | 5 Zoll Touchscreen Display | - größerer Bildschirm (besser zu betrachten) | - ggf. Gewicht | - Auflösung: 800 x 480 <br> - 5 Zoll | 39,99€ | [Amazon](https://www.amazon.de/Elecrow-Aufl%C3%B6sung-Touchscreen-Monitor-Raspberry/dp/B013JECYF2/) | X |
| LCD Touch Screen Display | kleines USB HDMI Display | - klein (Gewicht) | X | Auflösung: 1920 x 1080 <br> - 3,5 Zoll | 19,99€ | [Ebay](https://www.ebay.de/itm/202772035667) | X |
| *MOD-OLED-128x64* | - Einfaches Display für Text | - einfache Anbidnung <br> - Kapazität schonen <br> - geringer Stromverbrauch | - eingeschränkt in der Ausgabe <br> - kein I2C -> nicht Kompatibel! | - Schnittstelle: I2C <br> - Auflösung 128 x 64 | 6,98€ | [Mouser](https://www.mouser.de/ProductDetail/Olimex-Ltd/MOD-OLED-128x64?qs=Rp5uXu7WBW9sJeOZSKRzUw%3D%3D) | X |

### Weitere Informationen:
- Ein Überblick über [Raspberry Pi Display](https://www.raspberrypi.com/news/the-eagerly-awaited-raspberry-pi-display)
