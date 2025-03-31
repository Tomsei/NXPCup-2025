"""
running firmware analysis
this script controls the new firmware module nxp cup

the firmware module adds specific methods made for the nxp cup to analyse the image
with a sobel filter. It also calculate the trackCenters and transfer the resuls over SPI

@author Tom Seiffert
"""
import sensor
import time
import nxpcup

#configurations
camOffset = 25 #new cam module 25 - check - configure
lowestLine = 215 #avoid bumper shadow
sobelThreshold = 90

finishLineScanOffset = 40
finishLineScanStart = 155
finishLineScanLength = 60

minEdgeWidth = 2

# define spi connection
from machine import Pin, SPI
cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(16000000), polarity=0, phase=0)

# setup sensor
sensor.reset()  # Initialize the camera80 sensor.
sensor.set_pixformat(sensor.GRAYSCALE)  # or sensor.RGB565
sensor.set_framesize(sensor.QVGA)  # or sensor.QVGA (or others)
sensor.skip_frames(time=2000)  # Let new settings take affect.
sensor.set_gainceiling(8)
img = sensor.snapshot()
clock = time.clock()  # Tracks FPS.

imageHight = img.height()
imageWidth = img.width()


nxpcup.setup(   imageWidth,
                imageHight,
                camOffset,
                finishLineScanOffset,
                finishLineScanStart,
                finishLineScanLength,
                minEdgeWidth)

"""
run the prepared spi transfer for the nxpcup data
"""
def spiWriteTrackCenters():
    cs.low()
    nxpcup.spiWrite(spi)
    cs.high()

# while loop to calculate track Centers and transfer them over spi
while True:
    clock.tick()  # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot()  # Take a picture and return the image.

    img = nxpcup.analyseImage(img, lowestLine, sobelThreshold) #If nessesarry change return!
    print(img)
    spiWriteTrackCenters()
    #print(clock.fps())  # Note: Your OpenMV Cam runs about half as fast while
