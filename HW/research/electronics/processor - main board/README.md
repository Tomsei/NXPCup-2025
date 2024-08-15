# Prozessor - Board
Sammlung aller Relevanten Informationen zum Prozessor - Mikrocontroller Board


### Nutzungsfall
- Gesamtsteuerung des Autos

### Funktionale Anforderungen
- Ausreichen Anschlussmöglichkeiten für Sensoren, Displays, Kameras, Motoren
- Rechenstark
- optional: USB-Host fähig


## Mikrocontroller Board
| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | weitere Infos |
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: | :-----------: |
| FRDM-K64F | NXP Mikrocontroller Board | - NXP Board <br> - viele IO Pins <br> - für Mikrocontroller gute Performance <br> - integrierte IMU | - kein NXP-Chip (prüfen!) | - Prozessor: MK64FX512VLL12 <br>- 120 MHz ARM Cortex-M4 core | 81,99€ | [Conrad](https://www.conrad.de/de/p/nxp-semiconductors-frdm-k64f-evaluation-board-frdm-k64f-kinetis-k-series-1271993.html) | X |
| FRDM-K66F | NXP Mikrocontroller Board | - NXP Board <br> - starke Leistung <br> - viele IO Pins | X | - Prozessor: MK66FN2M0VMD18 <br> - 180 MHz ARM Cortex M4 | 78,59€ | [Mouser](https://www.mouser.de/ProductDetail/NXP-Semiconductors/FRDM-K66F?qs=URJt9NAcxHU9wqRc2Vi51Q%3D%3D&mgh=1) | X |
| FRDM-KL25Z | NXP Mikrocontroller Board | - sehr viele IO Pins <br> - Arduino Kompatibel <br> - günstig | - geringere Leistung | - Prozessor: L25Z128VLK4 <br> -48 MHz 32-bit ARM Cortex-M0 | 36,99€ | [Conrad](https://www.conrad.de/de/p/nxp-semiconductors-frdm-kl25z-entwicklungsboard-frdm-kl25z-kinetis-l-series-443897.html) | [Standard Libs](https://github.com/evandro-teixeira/Library-FRDM-KL25Z/tree/master) |

<br>
<br>

## Single Board Computer (SBC)
| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link |
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| DEBIX Model A | SBC mit NXP Chip | - starke Rechenleistung <br> - Anschlussmöglichkeiten (Display, Kamera...) <br> - PI Ähnlichkeit <br> - Unterschiedliche Modelle <br>| - Support / Unterstützung ist unklar <br> - WiFi Modul (abklären) | - bis zu 8 GB Memory <br> - WiFi <br> - OS: Win 10 IoT  <br> - OS: Ubuntu 22.04 <br> - Prozessor: NXP i.MX 8M Plus -| <br> 69,99€ (Memory Abhängig)| [DEBIX](https://debix.io/hardware/model-a.html) <br> [Conrad](https://www.conrad.de/de/p/debix-model-a-2-gb-4-x-1-8-ghz-2625844.html) <br> [digitalo](https://www.digitalo.de/products/1595561/DEBIX-Model-A-2GB-4-x-1.8GHz.html) |
| DEBIX Model A light | SBC mit NXP Chip | - gute Rechenleistung <br> - Anschlussmöglichkeiten (Display, Kamera...) <br> - PI Ähnlichkeit <br> - ggf. WiFi Antenne abschraubbar | - Support / Unterstützung ist unklar <br> - WiFi Modul (abklären) | - 4GB Memory <br> - WiFi <br> - 32 GB eMMc <br> -Prozessor: NXP i.MX 8M Plus Quad Lite | 87,46€ | [rsonline](https://de.rs-online.com/web/p/single-board-computer/2824027) |
| Debix Model B | SBC mit NXP Chip | - hohe Rechenleistung <br> - PI Ähnlichkeit <br> - NPU (neurale Verarbeitungseinheit) | - Support / Unterstützung ist unklar <br>- WiFi Modul (abklären) | - Prozessor: NXP i.MX 8M Plus (Standard) <br> - integrierte NPU- WiFi <br> - 4GB Memory | 170,11€ | [rsonline](https://de.rs-online.com/web/p/entwicklungstools-microcontroller/2619844)

**Übersicht über weitere SBC Möglichkeiten:** [rsonline](https://at.rs-online.com/web/c/?searchTerm=Polyhex+Single+Board+Computer) <br>
**Konfigurierbare NXP SBC Möglichkeiten:** [Toradex](https://www.toradex.com/de/single-board-computers)

<br>
<br>


## Single Board Computer (SBC) - Compute module + IO-Board
| Kit Name | Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | Gesamtkosten |
| :------: | :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: | :----------: |
| DEBIX SOM Kombination | Polyhex DEBIX SOM A| NXP Prozessor für SBC | - kein WiFi Modul | Support / Anwedung ggf. schwer <br> - Anzahl GPIO Pins | CPU: NXP i.MX 8M Plus | 98,77€ | [rsonline](https://de.rs-online.com/web/p/entwicklungstools-microcontroller/2619845) | 177,90€ |
| DEBIX SOM Kombination | DEBIX SOM A I/O Board | IO Board | X | WiFi Modul <br> - Anzahl GPIO Pins |  X | 177,90 (Kombi Paket) | [rsonline](https://de.rs-online.com/web/p/entwicklungstools-microcontroller/2664269) | 177,90€
| - | - | - | - | - | - | - | - | - |
| Teure NXP Kombination | CL-SOM-iMX8 | NXP Prozessor für SBC | - NXP Board (Regelkonform) <br> - WiFi kann entfernt werden! | Support / Anwendung ggf. schwer <br> - teuer! | - i.MX8M Dual/Quad <br> - bis zu 4 GB Ram <br> - no Wifi möglich | 240€ +  | [compulab](https://www.compulab.com/products/computer-on-modules/cl-som-imx8-nxp-i-mx-8-system-on-module-computer/#ordering) | 420€ + |
| Teure NXP Kombination | NXP i.MX8M SBC | IO Board | - NXP Board (Regelkonform) <br> - Anschlussmöglichkeiten | -  Support / Anwendung ggf. schwer <br> - WiFi <br> - teuer! | - abhängig vom Prozessor <br> - Kameramodul + Verbindung | 180€ + | [Compulab](https://www.compulab.com/de/products/sbcs/sbc-imx8-nxp-i-mx8m-single-board-computer/#ordering) | 420€ + |
| - | - | - | - | - | - | - | - | - |
| *Raspberry Pi Kit* | *Compute Module 4* | *Raspberry Pi 4* | *- Ohne Wlan möglich <br> - Flexibilität des Prozessor (Austauschbarkeit)* | *- kein NXP Chip <br> - nicht nutzbar!* | *- BCM2711 Quad-Core-Cortex-A72 (kein NXP Chip!) <br> - ermöglicht OpenGL <br> - Displayanschluss* | *ca 30€ - 100€ (je naach Ausstattung)* | *[Reichelt](https://www.reichelt.de/raspberry-pi-compute-modul-4-8gb-ram-32gb-emmc-rpi-cm4-8gb32gb-p290547.html?&trstct=vrt_pdn&nbc=1), [weitere Möglichkeiten](https://www.raspberrypi.com/products/compute-module-4/?variant=raspberry-pi-cm4001000)* | *70€ - 140€* |
| *Raspberry Pi Kit* | *Mini Base Board (C-Module 4)* | *Base Board für Compute Moudle 4* | *- Flexibilität des Prozessor (unterschiedliches Compute Module 4 möglich)* | *- kein NXP Chip <br> - nicht nutzbar!* | *- CM4 Socket <br> - Eingangsspannung 5V <br> - 40 Pin GPIO Anschluss* | *35,90€* | *[Berrybase](https://www.berrybase.de/mini-base-board-b-fuer-raspberry-pi-compute-module-4)* | 70€ - 140€ |
| - | - | - | - | - | - | - | - | - |
| *PI-Compute Moudle (NXP)* | *PI CM4 (NXP)* | *Compute Module mit NXP Chip* | *- Wäre Regelkonform* | *- Prototyp <br> - nicht kaufbar* | *X* | *X* | *[pcbway](https://www.pcbway.com/project/shareproject/Pi_MX8M_Plus_SoM_e3fe3cd9.html)* | *X* |

### Konfigurationsmöglichkeiten i.MX 8 - Teurer aber Ohne WiFi
- Angaben müssen noch verifiziert werden! <br>

**Konfigurierbare NXP i.MX 8 Prozessor für SBC**: [Toradex](https://www.toradex.com/de/computer-on-modules/apalis-arm-family/nxp-imx-8#buynow); [Toradex -große Übersicht](https://www.toradex.com/de/single-board-computers/configurator?sbc=) <br>
**Mögliches IO Board:** [Toradex - Board 1](https://www.toradex.com/de/products/carrier-board/mallow-carrier-board) [Toradex - Board 2](https://www.toradex.com/de/products/carrier-board/ixora-carrier-board)

### Konfigurationsmöglichkeiten i.MX 7 - Günstiger aber Ohne WiFi
- Angaben müssen noch verifiziert werden! <br>

**Konfigurierbare NXP i.MX 7 Prozessor für SBC**: [Toradex](https://www.toradex.com/de/computer-on-modules/colibri-arm-family/nxp-freescale-imx7) <br>
**Passends IO Board (Carrier Board)**: https://www.toradex.com/de/products/carrier-board/aster-carrier-board

<br>

## Weitere mögliche / offene Recherchen:  
- [Coral SoM](https://buyzero.de/products/google-coral-system-on-module-som-1gb?variant=39578150961332), 
- [phyBOARD - Pollux Image Kit](https://www.phytec.de/produkte/development-kits/phyboard-pollux-imaging-kit/#technische-details/)
- [Phytec (teilweise mit NXP Chips)](https://www.phytec.de/produkte/single-board-computer)
- [NXP](https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=16980&offeringId=31141)