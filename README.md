# NXPCup-2025
Software und Hardware für den NXP-Cup 2025
- **Software Ordner:** gesamter erzeugter Quellcode
- **Hardware Ordner:** Dokumentation der gewählten Hardware mitsamt Recherche

# NXP Cup
- ToDo: Beschreibung des NXP Cups...

Der NXP-Cup ist ein Internationaler Wettbewerb, ausgerichtet vom Unternehmen NXP (Link)...

# Styleguides
### Code
- Sprache (Variablen, Funktionen): Englisch
- Kommentare: Englisch
- Schreibweise: 
    - CamelCase
    - Funktionen / Variablen: starten klein
    - Typ-Klasse: starten groß
    - Variablen:
        - Boolen: Präfix is (isValid)
        - constant: konsequent großschreiben von CONSTANT
    - Leerzeichen zwischen Operatoren:  
    ```x + y``` anstatt ```a+y```; ```[x, y]``` anstatt ```[x,y]```
    - Klammerung: Klammer in gleicher Zeile dahinter
        ```
        function () {
            ...
        }
        ```
### GIT
- Commits: Englisch
- Dateien: Englisch
- Verzeichnisse: Englisch
- Wiki: Deutsch
- Issues: Deutsch

<br>
<br>

# Priorisierung der Veränderungen:
Aktuelle Übersicht über die überlegten Veränderungen und die Priorisierung dessen in der Umsetzung.

1. Neue Motoren (Brushless Motoren)
2. Ansteuerungsboard der Motoren (Geschwindigkeitsmessung, Motorkonfiguration)
3. Neue Kamera (Auswertung eines ganzen Bildes, wenn möglich höhere Auflösung
4. Fester Kameramast - Halterung sicherstellen!
5. Neuer Controller (Bevorzug Rasperry PI - Compute Module) → Leistungsstrak
6. Brake Out Board - Darauf kann dann das Compute Module hinterlegt werden
7. WLAN Stick
8. Eine Reihe von Neo LEDS zusammen schalten und nutzen
9. Display Hinzufügen
10. IMU
11. ABS (Durchdrehende Reifen)