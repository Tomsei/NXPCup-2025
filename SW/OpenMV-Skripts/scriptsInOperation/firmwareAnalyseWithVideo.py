"""
running firmware analysis - script like the normal one
added video recording to an SD-Card

to record the calculate sobel image this script needs the firmware version
where nxpcup.analyse() return the image

@author Tom Seiffert
"""
import sensor
import time
import nxpcup
import image, mjpeg

#configurations
camOffset = 25 #new cam module
lowestLine = 215
sobelThreshold = 90

finishLineScanOffset = 25
finishLineScanStart = 155
finishLineScanLength = 60

minEdgeWidth = 2
macCrossCount = 4
crossMinHeight = 25

vidoeDuration = 30000

# define spi connection
from machine import Pin, SPI
cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(16000000), polarity=0, phase=0)

# setup sensor
sensor.reset()  # Initialize the camera sensor.
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
                minEdgeWidth,
                macCrossCount,
                crossMinHeight)

#create the video file and needed configurations
video = mjpeg.Mjpeg('driving_video.mjpeg')
startTime = time.ticks_ms()
videoRunning = True

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

    #img = nxpcup.analyseImage(img, img.height(), 50)
    img = nxpcup.analyseImage(img, lowestLine, sobelThreshold)
    img = nxpcup.visualizeSteeringLines(img, lowestLine, 70, 80, 120)

    #add Famre to video
    if videoRunning:
        video.add_frame(img)

    spiWriteTrackCenters()
    print(clock.fps())  # Note: Your OpenMV Cam runs about half as fast while

    #save the video after the vidoeDuration
    if(videoRunning and time.ticks_diff(time.ticks_ms(), startTime) > vidoeDuration):
        print("over")
        video.close()
        videoRunning = False
