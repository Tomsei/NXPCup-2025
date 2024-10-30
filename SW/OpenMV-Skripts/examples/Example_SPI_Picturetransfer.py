"""
Example: SPI picture transfer
Inspired from: Open MV - Board control - spi_control.py Example
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

    reversed_img = struct.unpack('H' * (img.size() // 2), img)
    reversed_array = struct.pack('>' + 'H' * len(reversed_img), *reversed_img)

    spi.write(reversed_array)

    #example for sending individual bytes
    #spi.write(bytes([86, 89, 25, 23]))

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
