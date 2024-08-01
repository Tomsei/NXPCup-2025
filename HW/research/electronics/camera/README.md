# Kamera
Sammlung aller Relevanten Informationen zur Kamera

### Nutzungsfall
- Kontinuierliche Lieferung von Bildern während allen Situationen

### Funktionale Anforderungen
- Auflösung: mind. Full HD (1920 X 1080)
- mind. Monokromatisches Bild (Graustufe), aber Farbe wäre schön :)
- Frames: mind. 60 Fps (wenn möglich bei kleinrer Auflösung schneller)
- Scharfstellung!



Weitere Informationen zu den besten Kameras für den PI [Beste Pi Kameras](https://wonderfulengineering.com/10-best-cameras-for-raspberry-pi-2/)

Weitere Informationen zu Kameras: [BERRYBASE](https://www.berrybase.de/raspberry-pi/raspberry-pi-computer/kameras/) 

Weitere Informationen zu kompatibelen Kameras für Compute Modules: [Kompatible Kamers](https://www.pi-shop.ch/blog/kamera-modul-komp)

| Name | Beschreibung | Vorteile | Nachteile | Technische Details | Kosten | Link | 
| :--: | :----------: | :------: | :-------: | :----------------: | :----: | :--: |
| Haljia Kamera | Raspberry Pi Mini Kamera Modul | - geringe Kosten | - eigene Leistungsanforderungen nicht erfüllt | - Anforderungen nicht erfüllt <br> - 1080 pixel (30 FPS) <br> - Unterstütztung von Rasbian (Rasperry Pi beorzugt) | 9,99€ | [Amazon](https://www.amazon.de/Megapixel-Sensor-ov5647-Mini-Kamera-Raspberry/dp/B01DM8NAI0/ref=sr_1_1) |
| sainsmart | Fish-Eye Camera | - geringe kosten | - eigene Leistunfsanfroderungen nicht erfüllt <br> - fixierter Fokus | - Anfordernungen nicht erfüllt <br> - 1080 pixel (30 FPS) <br> - Rasbian support | 21,99€ | [Amazon](https://www.amazon.de/SainSmart-Fish-Eye-Camera-Raspberry-Arduino/dp/B00N1YJKFS/ref=sr_1_1)
| Raspberry Pi Kamera V2 | 8MP Standard Kamera  | - geringe Kosten | -ggf. Schwierigkeiten bei der Linse | - Anforderungen erfüllt: [Quelle](https://wonderfulengineering.com/10-best-cameras-for-raspberry-pi-2/) <br> - 1080 Pixel (60 FPS) <br> - 720 Pixel (180 FPS) <br> - fixed focus Linse | 15€ | [Amazon](https://www.amazon.de/Raspberry-Pi-V2-1-1080P-Kamera-Modul/dp/B01ER2SKFS/ref=sr_1_3) | 
| OpenMV Camera | Kamera mit integrierter Prozessor (Pixy ähnlich) | - soll eine einfache + eigene Programmierung ermöglichen | - ggf. nicht Regelkonform, da kein NXP-Chip verwendet wird <br> - Die Kamera Programmierung in Python | X | 120$ | [OpenMV](https://openmv.io/products/openmv-cam-rt)