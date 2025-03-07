import sensor
import time
import nxpcup

import image, mjpeg

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

nxpcup.setup(imageWidth, imageHight) # todo: integrate cam offset

video = mjpeg.Mjpeg('driving_video.mjpeg')
startTime = time.ticks_ms()
videoRunning = True

def spiWriteTrackCenters():
    cs.low()
    nxpcup.spiWrite(spi)
    cs.high()

while True:
    clock.tick()  # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot()  # Take a picture and return the image.

    #track_centers = nxpcup.analyseImage(img, img.height(), 200) #ToDo Remove Trackcenters
    img = nxpcup.analyseImage(img, img.height(), 150)

    if videoRunning:
        video.add_frame(img)
    #list_track_centers = list(track_centers)
    #print(list_track_centers[0], list_track_centers[1], list_track_centers[2], list_track_centers[3])
    spiWriteTrackCenters()
    print(clock.fps())  # Note: Your OpenMV Cam runs about half as fast while

    if(videoRunning and time.ticks_diff(time.ticks_ms(), startTime) > 20000):
        print("over")
        video.close()
        videoRunning = False

