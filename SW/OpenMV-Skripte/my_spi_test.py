# Untitled - By: tomse - Mon Sep 30 2024


import sensor, image, time

from machine import Pin, SPI

import rpc


spi = SPI(1, baudrate=int(1000), polarity=0, phase=0)
cs = Pin("P3", Pin.OUT)



sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)

#hi = rpc.rpc_i2c_slave(0x50, 1)


clock = time.clock()

def write_data_byte(c, d):
    cs.low()
    #spi.write_readinto(c, d)
    #spi.write(c)
    #print(spi.read(1))
    #print(spi.read(2))
    print(spi.read(2))
    cs.high()
    #print(d)
    time.sleep_ms(500)

"""def spiWriteTest(c):
    cs.low()
    spi.write(bytes([c]))
    cs.high()
    time.sleep_ms(2000)
"""
while(True):
    clock.tick()
    img = sensor.snapshot()
    #print(clock.fps())
    a = bytes([15])
    b = bytearray(1)
    write_data_byte(a, b)
    #print(b)
    write_data_byte(bytes([22]), b)
    #print(b)
    #print(a)
    #print("SPI Write")
