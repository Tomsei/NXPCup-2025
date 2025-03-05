import sensor
import time
import nxpcup

# define spi connection
from machine import Pin, SPI
cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(16000000), polarity=0, phase=0)

# setup sensor
sensor.reset()  # Initialize the camera sensor.
sensor.set_pixformat(sensor.GRAYSCALE)  # or sensor.RGB565
sensor.set_framesize(sensor.QQVGA)  # or sensor.QVGA (or others)
sensor.skip_frames(time=2000)  # Let new settings take affect.
sensor.set_gainceiling(8)
img = sensor.snapshot()
clock = time.clock()  # Tracks FPS.

imageHight = img.height()
imageWidth = img.width()

nxpcup.setup(imageWidth, imageHight)



def spiWriteTrackCenters():
    cs.low()
    nxpcup.spiWrite(spi)
    cs.high()

while True:
    clock.tick()  # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot()  # Take a picture and return the image.
    print(clock.fps())  # Note: Your OpenMV Cam runs about half as fast while
    track_centers = nxpcup.analyseImage(img, img.height(), 160) #ToDo Remove Trackcenters
    #list_track_centers = list(track_centers)
    #print(list_track_centers[0], list_track_centers[1], list_track_centers[2], list_track_centers[3])
    spiWriteTrackCenters()
