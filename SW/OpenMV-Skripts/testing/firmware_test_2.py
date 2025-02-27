# This work is licensed under the MIT license.
# Copyright (c) 2013-2023 OpenMV LLC. All rights reserved.
# https://github.com/openmv/openmv/blob/master/LICENSE
#
# Edge detection with Canny:
#
# This example demonstrates the Canny edge detector.
import sensor
import time
import nxpcup

from machine import Pin, SPI
cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)


imageHight = 120
imageWidth = 160

track_centers = [i for i in range(1, 121)]

sensor.reset()  # Initialize the camera sensor.
sensor.set_pixformat(sensor.GRAYSCALE)  # or sensor.RGB565
sensor.set_framesize(sensor.QQVGA)  # or sensor.QVGA (or others)
sensor.skip_frames(time=2000)  # Let new settings take affect.
sensor.set_gainceiling(8)

clock = time.clock()  # Tracks FPS.

def write_image(track_centers):
    cs.low()
    #reversed_img = struct.unpack('H' * (img.size() // 2), img)
    #reversed_array = struct.pack('>' + 'H' * len(reversed_img), *reversed_img)
    #spi.write(reversed_array)
    #example for sending individual bytes
    spi.write(bytes(track_centers))
    cs.high()

while True:
    clock.tick()  # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot()  # Take a picture and return the image.
    print(clock.fps())  # Note: Your OpenMV Cam runs about half as fast while
    track_centers = nxpcup.calculate_sobel(img, img.height(), 80) #ToDo Remove Trackcenters
    #track_centers = struct.unpack("<" + "h" * (len(track_centers_bytes) // 2), track_centers_bytes)
    print(list(track_centers))
    #writeSpi(bytes(track_centers))
