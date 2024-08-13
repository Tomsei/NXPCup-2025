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
| DEBIX Model A | NXP-Single Computer | Rechenleistung, Anschlussmöglichkeiten, Ähnlichkeiten zum PI | Support / Unterstützung ist unklar | - bis zu 8 GB Memory <br> - Windows 10 IoT Enterprise <br> - 4 x Arm Cortex-A53 | ? <br> 58,82€ | [DEBIX](https://debix.io/hardware/model-a.html) <br> [Conrad](https://www.conrad.de/de/p/debix-model-a-2-gb-4-x-1-8-ghz-2625844.html) <br> [Okdo](https://www.okdo.com/de/p/debix-model-a-single-board-computer/) <br> [digitalo](https://www.digitalo.de/products/1595561/DEBIX-Model-A-2GB-4-x-1.8GHz.html)|
| FRDM-K64F | NXP Mikrocontroller Board | Board von NXP selbst | geringe Leistung | - ARM Cortex-M4 | 68,90€ | [Conrad](https://www.conrad.de/de/p/nxp-semiconductors-frdm-k64f-evaluation-board-frdm-k64f-kinetis-k-series-1271993.html) |


### Compute Module mit zugehörigen IO-Board
| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| Mini Base Board (C-Module 4) | Base Board für Compute Moudle 4 | - Flexibilität des Prozessor (unterschiedliches Compute Module 4 möglich) | - benötigt ein zusätzliches Compute Module! | - CM4 Socket <br> - Eingangsspannung 5V | 35,90€ | [Berrybase](https://www.berrybase.de/mini-base-board-b-fuer-raspberry-pi-compute-module-4)
| Compute Module 4 | Raspberry Pi 4 | - Ohne Wlan möglich <br> - Flexibilität des Prozessor (Austauschbarkeit) | - Kombination mit IO-Board notwendig | -1.5GHz 4 Kerne <br> - ermöglicht OpenGL, Vulkan <br> - Displayanschluss | ca 30€ - 100€ (je naach Ausstattung) | [Reichelt](https://www.reichelt.de/raspberry-pi-compute-modul-4-8gb-ram-32gb-emmc-rpi-cm4-8gb32gb-p290547.html?&trstct=vrt_pdn&nbc=1), [weitere Möglichkeiten](https://www.raspberrypi.com/products/compute-module-4/?variant=raspberry-pi-cm4001000)
| - | - | - | - | - | - | - |
| NXP i.MX8M Single Board Computer | Board für Single Board Computer von NXP selbst | - NXP Board (Regelkonform) | - Support / Anwendung des Boards unklar <br> - inkludiert Wifi | - abhängig vom genutzten Prozessor <br> - Kameraanbindung an bestimmtes Kamera Modul <br> - teuer| 180€ (mehr möglich) | [Compulab](https://www.compulab.com/de/products/sbcs/sbc-imx8-nxp-i-mx8m-single-board-computer/#ordering)
| CL-SOM-iMX8 | Prozessor für Single Board Computer von NXP selbst | - NXP Board (Regelkonform) <br> - WiFi kann entfernt werden! | Support / Anwendung ggf. schwer <br> - teuer | - i.MX8M Dual/Quad <br> - bis zu 4 GB Ram <br> - no Wifi möglich | Anfang bei 240€ (Paket: 420€) | [compulab](https://www.compulab.com/products/computer-on-modules/cl-som-imx8-nxp-i-mx-8-system-on-module-computer/#ordering)


Weitere Möglichkeiten: 
- [Coral SoM](https://buyzero.de/products/google-coral-system-on-module-som-1gb?variant=39578150961332), 
- [phyBOARD - Pollux Image Kit](https://www.phytec.de/produkte/development-kits/phyboard-pollux-imaging-kit/#technische-details/)
- [Phytec (teilweise mit NXP Chips)](https://www.phytec.de/produkte/single-board-computer)
- [NXP](https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=16980&offeringId=31141)
- Suchen nach DEBIX "Compute Module" Äquivalent