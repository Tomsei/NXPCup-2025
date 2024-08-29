# Collection of multiple Components
Im folgenden werden alle Komponenten festgehalten, die verwändet werden, aber keine eigene Recherche Seite benötigen.

## Kamerahalterung
Sammlung aller Relevanten Informationen zur Kamerahalterung
- Wird selbst entwickelt + gebaut
- Befestigung Chassi ungefähr am Autoschwerpunkt 

<br>
<br>

## Voltmeter / Ampermeter
Sammlung aller Relevanten Informationen zu Volt und Ampermeter

### Nutzungsfall
- Spannungsmessungen über einen eingebauten Sensor (Akkuladung...)
- Debugging Unterstützung

### Funktionale Anforderungen
- eingesetzte Spannungen können gelesen werden

<br>
<br>

# An-Ausschalter
Sammlung aller Relevanten Informationen zum An-Ausschalter

| Name | Beschreibung | Vorteile | Nachteile | Kosten | Link | weitere Infos |
| :--: | :----------: | :------: | :-------: | :----: | :--: | :-----------: |
| **On-Off Switch** | **Wippschalter** | **X** | **X** | **0,74€ + 4,29€** | **[Mouser](https://www.mouser.de/ProductDetail/E-Switch/RA1113112R?qs=QtyuwXswaQh2BdIH9uXjxQ%3D%3D&mgh=1)** | **- Relais notwendig [Conrad](https://www.conrad.de/de/p/shr-4141b-shr-12vdc-f-c-5pin-kfz-relais-12-v-dc-80-a-1-wechsler-1433311.html)**
| Not Aus | Not Aus Button für persönliches Modell | persönliche Präferenz | X | 8,49 + 4,29 | [Conrad](https://www.conrad.de/de/p/tru-components-not-aus-schalter-3-a-1-oeffner-ip40-1-st-2304758.html) | - Relais notwendig [Conrad](https://www.conrad.de/de/p/shr-4141b-shr-12vdc-f-c-5pin-kfz-relais-12-v-dc-80-a-1-wechsler-1433311.html) |
| Eigen Vorrat | Eigener Schalter | keine Bestellung notwendig | X | X | X | X |

<br>
<br>

# Spannungswandler
Sammlung aller Relevanten Informationen zum Spannungswandler

### Nutzungsfall
- Betreibung vom Servo
- Betrebiung vom Mainboard
### Funktionale Anforderungen
- Servo: Umwandulung auf 7.2V, 2A (auf Servo anpassen)
- Board: Umwandlung auf 5V, 4A (auf Board anpassen)
- Input 12V
- Energieeffizienz über 80 % (Hitzeentwicklung)

| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| LM2596S DC-DC to 5V | 5V Wandler | X | X | - Gewicht: 22g <br> - Output 5.2V | 29.79$ | [Alexnld](https://alexnld.com/product/5pcs-lm2596s-dc-dc-24v-12v-to-5v-5a-step-down-power-supply-buck-converter-adjustable-usb-step-down-charging-module)| 
| **DFR0379** | **DC-DC Buck Converter** | **- bekannt + funktionsfhäig <br> - Output einstellbar** | **X** | **[Dateblatt](https://www.mouser.com/pdfDocs/ProductOverview-DFRobot-DFR0379.pdf)** | **4,56€** | **[Mouser](https://www.mouser.de/ProductDetail/DFRobot/DFR0379?qs=5aG0NVq1C4zPqXmLzkhO%252Bg%3D%3D)** |