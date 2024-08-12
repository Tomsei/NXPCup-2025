# Prozessor - Board
Sammlung aller Relevanten Informationen zum Prozessor - genutzes Board


### Nutzungsfall
- Gesamtsteuerung des Autos

### Funktionale Anforderungen
- Ausreichen Anschlussmöglichkeiten für Sensoren, Displays, Kameras, Motoren
- Rechenstark
- optional: USB-Host fähig


### Boards mit inkludierten Prozessor
| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| DEBIX Model A | NXP-Single Computer | Rechenleistung, Anschlussmöglichkeiten, Ähnlichkeiten zum PI | Support / Unterstützung ist unklar | - bis zu 8 GB Memory <br> - Windows 10 IoT Enterprise <br> - 4 x Arm Cortex-A53 | ? <br> 58,82€ | [DEBIX](https://debix.io/hardware/model-a.html) <br> [Conrad](https://www.conrad.de/de/p/debix-model-a-2-gb-4-x-1-8-ghz-2625844.html)
| FRDM-K64F | NXP Mikrocontroller Board | Board von NXP selbst | geringe Leistung | - ARM Cortex-M4 | 68,90€ | [Conrad](https://www.conrad.de/de/p/nxp-semiconductors-frdm-k64f-evaluation-board-frdm-k64f-kinetis-k-series-1271993.html)


### Compute Module mit zugehörigen IO-Board
| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| Mini Base Board (C-Module 4) | Base Board für Compute Moudle 4 | - Flexibilität des Prozessor (unterschiedliches Compute Module 4 möglich) | - benötigt ein zusätzliches Compute Module! | - CM4 Socket <br> - Eingangsspannung 5V | 35,90€ | [Berrybase](https://www.berrybase.de/mini-base-board-b-fuer-raspberry-pi-compute-module-4)
| Compute Module 4 | Raspberry Pi 4 | - Ohne Wlan möglich <br> - Flexibilität des Prozessor (Austauschbarkeit) | - Kombination mit IO-Board notwendig | -1.5GHz 4 Kerne <br> - ermöglicht OpenGL, Vulkan <br> - Displayanschluss | ca 30€ - 100€ (je naach Ausstattung) | [Reichelt](https://www.reichelt.de/raspberry-pi-compute-modul-4-8gb-ram-32gb-emmc-rpi-cm4-8gb32gb-p290547.html?&trstct=vrt_pdn&nbc=1), [weitere Möglichkeiten](https://www.raspberrypi.com/products/compute-module-4/?variant=raspberry-pi-cm4001000)



Offene / zu prüfende Links: [NXP Board Conrad](https://www.conrad.de/de/p/nxp-semiconductors-frdm-k64f-evaluation-board-frdm-k64f-kinetis-k-series-1271993.html?hk=SEM&WT.mc_id=google_pla&gad_source=1&gclid=CjwKCAjw5Ky1BhAgEiwA5jGujq6W1-mqRV1Uk8HsP6iGdMMh9gRQ3QsY-L6Mo0ezBFutM6CsmqsI3RoCD0QQAvD_BwE&refresh=true)