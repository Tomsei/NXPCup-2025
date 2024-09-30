# Untitled - By: tomse - Mon Sep 30 2024

import sensor, image, time
from machine import Pin, SPI

spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)


sensor.reset()  # Initialize the camera sensor.
sensor.set_pixformat(sensor.RGB565)  # must be this
sensor.set_framesize(sensor.QQVGA2)  # must be this
sensor.skip_frames(time=2000)  # Let new settings take affect.
clock = time.clock()  # Tracks FPS.


while(True):
    print("SPI Communiation");
