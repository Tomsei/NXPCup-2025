# Geschwindigkeitsmessung
Sammlung aller Relevanten Informationen zur Geschwindigkeitsmessung

### Nutzungsfall
- Immer bei jeden Fahrten wichtig!
- Die Aktuelle Geschwindigkeit des Autos ausgeben! (Vorwärts / Rückwärts)
- ggf. Kalibrierungsmöglichkeiten (fahren wir gerade - Servo) (Motor Drehgeschwindigkeit führt zu ... Geschwindigkeit)
- ggf. Drift-Erfassung möglich

### Funktionale Anforderung
- hohe Präzision / Genauigkeit der Geschwindigkeitswerte
- hohe Update Rate: 60/sekunde neue Geschwindigkeit
- Funktionsfähig auf NXP-Fahrban!



| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| **PIM453** | **Optical Flow Sensor <br> Bewegungserkennung wie ein Muassensor** | **- Geschwindigkeiten in alle Richtungen erkennbar (seitliche Messung möglich)** | **- Funktionsfähigkeit muss zunächst geprüft werden** | **- Betriebsspannung: 3V, 5V <br> - Schnittstelle: SPI** | **22,32€** | **[Mouser](https://www.mouser.de/ProductDetail/Pimoroni/PIM453?qs=PzGy0jfpSMuJnlsymXyulA%3D%3D)** |
| **ARD LINE FINDER2** | **IR-Hindernissensor** | **- Sollte löcher im Zahnrad ohne weiteres identifizieren können <br> - keine Magneten sind notwendig** | **- Funktionsfähigkeit muss geprüft werden** | **- [Datenblatt](https://cdn-reichelt.de/documents/datenblatt/C200/ST1081.pdf)** | **3,20€** | **[reichelt](https://www.reichelt.de/arduino-ir-hindernissensor-2-40-cm-38-khz-ard-line-finder2-p282521.html)** |
| Seed 101020587 | Optical Rotary Encoder | - Durch Lichtschranke könnten Zähne / Löcher getrackt werden | - keine Positionierung am vorhanden Rad möglich <br> - bei Zähnen zu viele Interupts | - [Datenblatt](https://raw.githubusercontent.com/SeeedDocument/Grove-Optical_Rotary_Encoder-TCUT1600X01/master/res/Optical_Sensor.pdf) | 8,93€ | [Mouser](https://www.mouser.de/ProductDetail/Seeed-Studio/101020587?qs=byeeYqUIh0OPLfsrlpqP%252Bw%3D%3D)