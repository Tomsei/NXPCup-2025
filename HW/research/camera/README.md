# Kamera
Sammlung aller Relevanten Informationen zur Kamera

### Nutzungsfall
- Kontinuierliche Lieferung von Bildern während allen Situationen

### Funktionale Anforderungen - Orientierungswerte
- Auflösung: mind. Full HD (1920 X 1080)
- mind. Monokromatisches Bild (Graustufe), aber Farbe wäre schön :)
- Frames: mind. 60 Fps (wenn möglich bei kleinrer Auflösung schneller)
- Scharfstellung!





| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| **OpenMV Camera** | **Kamera mit integrierter Prozessor (Pixy ähnlich)** | **- Programmierung auf Kamera möglich  <br> - [Prozessor ist von NXP](https://cdn.shopify.com/s/files/1/0803/9211/files/IMXRT1060IEC.pdf?v=1681075136)<br> - 3D Druck Dateien zum anbringen vorliegend** | **- Kamera Programmierung in Python <br> - WLAN Module (abklären) <br> - Orientierungswerte nicht erreicht** | **- [Kamera Datenblatt](https://pdf1.alldatasheet.com/datasheet-pdf/view/587044/OMNIVISION/OV5640.html) <br> Werte nicht erfüllt: <br> - 1080 pixel (30FPS) <br> - 720 pixel (60FPS) <br> - JPEG compression** | **120$ <br> 133,46€** | **[OpenMV](https://openmv.io/products/openmv-cam-rt) <br>[Robotshop](https://eu.robotshop.com/de/products/openmv-cam-rt1062) <br> <br> [weitere Modelle](https://openmv.io/collections/cameras)** |
| sainsmart | Fish-Eye Camera | - geringe kosten | - Orientierungswerte nicht erreicht <br> - fixierter Fokus | Werte nicht erfüllt: <br> - 1080 pixel (30 FPS) <br> - Rasbian support | 21,99€ | [Amazon](https://www.amazon.de/SainSmart-Fish-Eye-Camera-Raspberry-Arduino/dp/B00N1YJKFS/ref=sr_1_1) |
| ArduCam B0399 | Für Pi konzipierte Kamera | - gute Auflösungsmöglichkeiten! | - teurere Möglichkeit <br> - Nutzung ohne Pi muss verifiziert werden | Werte erfüllt: <br> - 1080 Pixel (60 FPS) <br> - 720 (120 FPS) | 71,50€ | [botland](https://botland.de/kameras-fur-raspberry-pi/21686-64-mp-kamera-mit-autofokus-fur-raspberry-pi-arducam-b0399-5904422384524.html) |
| Raspberry Pi Kamera V2 | 8MP Standard Kamera  | - geringe Kosten | -ggf. Schwierigkeiten bei der Linse | Werte erfüllt: [Quelle](https://wonderfulengineering.com/10-best-cameras-for-raspberry-pi-2/) <br> - 1080 Pixel (60 FPS) <br> - 720 Pixel (180 FPS) <br> - fixed focus Linse | 15€ | [Amazon](https://www.amazon.de/Raspberry-Pi-V2-1-1080P-Kamera-Modul/dp/B01ER2SKFS/ref=sr_1_3) | 
| Raspberry Pi Camera 3 NoIR | Pi Kamera Modul | - Integration zu Pi sollte einfach sein | - Orientierungswerte knapp nicht erreicht | Werte knapp nicht erfüllt: <br> - 1080 Pixel (50 FPS) <br>- 720 Pixel (100 FPS) | 28,50€ | [Reichelt](https://www.reichelt.de/raspberry-pi-kamera-12mp-76-noir-v3-rasp-cam-3-n-p339259.html) |
| Haljia Kamera | Raspberry Pi Mini Kamera Modul | - geringe Kosten | - Orientierungswerte nicht erreicht | Werte nicht erfüllt: <br> - 1080 pixel (30 FPS) <br> - Unterstütztung von Rasbian (Rasperry Pi beorzugt) | 9,99€ | [Amazon](https://www.amazon.de/Megapixel-Sensor-ov5647-Mini-Kamera-Raspberry/dp/B01DM8NAI0/ref=sr_1_1) |

# Weitereführende Informationen

### Open MV Camera Details
- **Display:** kompatibles Display vorhanden [Open MV Display](https://openmv.io/collections/openmv-cam-shields/products/lcd-shield?variant=16525320513)  
- **IDE:** eigene Entwicklungsumgebung der Open MV Cam (Plug and Programm)
- **Grundprogramme:** große Reihe an grundlegenden Beispielen + Möglichkeiten wie die Integration von Tenserflow
- **Machine Learning:** bereits Beispielhafte Machine Learning Prozesse umgesetzt [Beispiel Demo](https://www.youtube.com/watch?v=PdWi_fvY9Og)
- **Tutorial + Support:** viele Tutorials + Support Forum | [FAQ](https://openmv.io/pages/faq)
- **Programmiersprache:** Mikro Python - C Programmierung durch veränderung der Firmware möglich! [Forum Beitrag](https://forums.openmv.io/t/is-it-possible-to-code-the-camera-intelligente-openmv-cam-h7-in-c/9172/2)
- **Firmware Änderungen:** Änderungen sind deutlich einfacher möglich als bei Pixy [Firmware](https://github.com/openmv/openmv), [Forum Beitrag](https://forums.openmv.io/t/custom-firmware-on-openmv-h7/2081/1), [Build Anweisung](https://github.com/openmv/openmv/tree/master/src)
- **Praxisbeispiele:** [Getting Startet](https://www.youtube.com/watch?v=6xr5K1NalBQ), [simple object tracking](https://www.youtube.com/watch?v=3c-LGLlfMd4), [eigenes Training der Cam](https://sites.hslu.ch/werkstatt/train-your-camera/)