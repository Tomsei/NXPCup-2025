"""
Example: SPI picture line transfer
Inspired from: Open MV - board control - spi_control.py example

@author Tom Seiffert
"""
import sensor
import time
from machine import Pin, SPI

cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)


#--------------------------------------------#
# variable / configurations
#--------------------------------------------#

#line configurations
numberOfLines = 5
lineWidth = 1

# configure while choosing resolution (change lines and pixel amount)
horizontalPixelCount = 320
rowLine1 = 170
rowLine2 = 160
rowLine3 = 130
rowLine4 = 90
rowLine5 = 60

#--------------------------------------------#
# method declaration
#--------------------------------------------#

"""
method to create an image out of the choosen lines
@param img: base image to extracte the lines
@return lineImage: an image with only the choosen lines
"""
def configureLines(img):
    baseimage = img.copy(roi = (0,rowLine1,horizontalPixelCount,lineWidth*numberOfLines), x_scale = 1.0, y_scale = 1.0, alpha=0)
    #create copy of the choosen lines
    line1 = img.copy(roi = (0,rowLine1,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=255)
    line2 = img.copy(roi = (0,rowLine2,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=255)
    line3 = img.copy(roi = (0,rowLine3,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=255)
    line4 = img.copy(roi = (0,rowLine4,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=255)
    line5 = img.copy(roi = (0,rowLine5,horizontalPixelCount,lineWidth), x_scale = 1.0, y_scale = 1.0, alpha=255)

    #add all lines together in one image
    lineImage = baseimage; # necessary because transparenty problem when there is no base image
    lineImage.add(image = line1, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = 0, x_scale = 1.0, y_scale = 1.0, alpha=255)
    lineImage.add(image = line2, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*1, x_scale = 1.0, y_scale = 1.0, alpha=255)
    lineImage.add(image = line3, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*2, x_scale = 1.0, y_scale = 1.0, alpha=255)
    lineImage.add(image = line4, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*3, x_scale = 1.0, y_scale = 1.0, alpha=255)
    lineImage.add(image = line5, roi = (0,0,horizontalPixelCount,numberOfLines*lineWidth), x = 0, y = lineWidth*4, x_scale = 1.0, y_scale = 1.0, alpha=255)

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
    spi.write(img)
    cs.high()

"""
method to print the values of an image row
@param img: the img to print the values
@param row: the image row to pring
@param start: the start pixel
@param length: the amout of pixel to print after start
"""
def printRowPixel(img, row, start, length):
    pixelString = "Pixels: "
    for i in range(length):
        pixelString = pixelString + str(img.get_pixel(i,row)) + "\t"
    print (pixelString)

#--------------------------------------------#
# Setup
#--------------------------------------------#

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
    print(clock.fps())
