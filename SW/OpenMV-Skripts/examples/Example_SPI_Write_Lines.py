"""
Example: SPI picture line transfer
Inspired from: Open MV - Board control - spi_control.py Example
"""
import sensor
import time
from machine import Pin, SPI
import struct

cs = Pin("P3", Pin.OUT)

spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)



#line configurations
numberOfLines = 5
lineWidth = 1
# confrigure while choosing resolution (change lines and Pixel amount)
horizontalPixelCount = 320
rowLine1 = 200
rowLine2 = 199
rowLine3 = 198
rowLine4 = 197
rowLine5 = 196


"""
method to create an image out of the choosen lines
@param img: base image to extracte the lines
@return lineImage: an image with onlye the choosen lines
"""
def configureLines(img):
    baseimage = img.copy(roi = (0,rowLine1,horizontalPixelCount,lineWidth*numberOfLines), x_scale = 1.0, y_scale = 1.0, alpha=0)
    line1 = img.copy(roi = (0,rowLine1,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=256)
    line2 = img.copy(roi = (0,rowLine2,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=256)
    line3 = img.copy(roi = (0,rowLine3,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=256)
    line4 = img.copy(roi = (0,rowLine4,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=256)
    line5 = img.copy(roi = (0,rowLine5,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=256)

    lineImage = baseimage; # necessary because transparenty problem when there is no base image
    lineImage.add(image = line1, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = 0, x_scale = 1.0, y_scale = 1.0, alpha=256)
    lineImage.add(image = line2, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*1, x_scale = 1.0, y_scale = 1.0, alpha=256)
    lineImage.add(image = line3, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*2, x_scale = 1.0, y_scale = 1.0, alpha=256)
    lineImage.add(image = line4, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*3, x_scale = 1.0, y_scale = 1.0, alpha=256)
    lineImage.add(image = line5, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*4, x_scale = 1.0, y_scale = 1.0, alpha=256)

    #just to show image in Framebuffer
    #img.clear()
    #img.draw_image(lineImage, 0, 0)

    return lineImage

"""
method to write an image to spi
@param img: the img to tansfer
"""
def writeImageSpi(img):
    cs.low()

    reversed_img = struct.unpack('H' * (img.size() // 2), img)
    reversed_array = struct.pack('>' + 'H' * len(reversed_img), *reversed_img)

    spi.write(reversed_array)

    cs.high()

def debugPixelfalus(img):
    print("pixelvalues")

#setup cam
sensor.reset()                      # Initialize the camera sensor.
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QVGA)   # can also be VGA if needed
sensor.skip_frames(time=2000)       # Let new settings take affect.
clock = time.clock()                # Tracks FPS.

#--------------------------------------------#
# Running - Main loop
#--------------------------------------------#
while True:
    clock.tick()            # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot() # Take a picture and return the image.
    lineImage = configureLines(img)
    writeImageSpi(lineImage)
    time.sleep_ms(100)
    print(clock.fps())
