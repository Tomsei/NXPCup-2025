# Untitled - By: tomse - Mon Sep 30 2024


import sensor, image, time


from machine import Pin, SPI
spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)
cs = Pin("P3", Pin.OUT)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)



clock = time.clock()

def spiWriteTest():
    cs.low()
    spi.write(b"12345678")
    cs.high()

while(True):
    clock.tick()
    img = sensor.snapshot()
    print(clock.fps())
    spiWriteTest()
    print("SPI Write")
