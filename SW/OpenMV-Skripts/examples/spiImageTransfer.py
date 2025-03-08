"""
Example: SPI transfer of the image and individual bytes
- just take an image an write it over spi like the Open-MV exmaple
  minimized to what is necessary for transmission

Inspired from: Open MV board control exmaple: spi_control_1.py
@author Tom Seiffert
"""

import sensor
import time
from machine import Pin, SPI
import struct

cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)


"""
method to write an image to spi
@param img: the img to tansfer
"""
def write_image(img):
    cs.low()

    #write image over spi
    reversed_img = struct.unpack('H' * (img.size() // 2), img)
    reversed_array = struct.pack('>' + 'H' * len(reversed_img), *reversed_img)
    spi.write(reversed_array)

    #example for sending individual bytes
    #spi.write(bytes([40, 89, 25, 23]))

    cs.high()

#setup cam
sensor.reset()                      # Initialize the camera sensor.
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA2)
sensor.skip_frames(time=2000)       # Let new settings take affect.
clock = time.clock()                # Tracks FPS.

#--------------------------------------------#
# Running - Main loop
#--------------------------------------------#
while True:
    clock.tick()            # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot() # Take a picture and return the image.
    write_image(img)
    print(clock.fps())
