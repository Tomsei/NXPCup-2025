"""
Example: Accespoint connection and cam control with more advanced options
"""

import time
import network
import socket
import uasyncio
from machine import Pin, SPI

ssid = 'NXP-Cup 2025'
password = '123456789'

currentButtonState = False
globalCounter = 0

#setup SPI
cs = Pin("P3", Pin.OUT)
spi = SPI(1, baudrate=int(1000000000 / 66), polarity=0, phase=0)

"""
method to create basic HTML structure
@return basic HTML structure
"""
def createHtmlString():
    html = '''
    <!DOCTYPE html>
    <html>
    <head>
        <title> NXP-Cup 2025 Car Control </title>
    </head>
    <body>
        <h1> NXP-Cup 2025 Car Control </h1>
        <form>
            <p> Click the Button to control the value </p>
            <button name="exampleButton" value='buttonOn' type='submit' style="height: 300px; width: 800px;">  Button ON </button>
            <p></p>
            <button name="exampleButton" value='buttonOff' type='submit' style="height: 300px; width: 800px;"> Button OFF </button>
        </form>
        <p> The Button is ''' + str(currentButtonState) + ''' </p>
        <p> The Current Counter is ''' + str(globalCounter) + '''
    </body>
    </html>'''
    return html

"""
methode to setup the accespoint and to start it.
@param accesPoint accesPoint to start
"""
def setupAccespoint(accesPoint):
    #setup accespoint
    accesPoint.active(False)
    time.sleep(2)
    accesPoint.config(essid=ssid, password=password)
    accesPoint.active(True)

    # wait until Accespoint is active
    while accesPoint.active() == False:
        print("Waiting for active Accespoint")
        time.sleep(0.5)
    print("Accespoint mode started. ssid: {} IP: {}".format(ssid, accesPoint.ifconfig()[0]))


"""
method to transfer the engineState via spi
@param engineState: state the engine should be
"""
def transferEngineState(engineState):
    cs.low()
    spi.write(bytes([engineState]))
    print("SPI Write: " + str(engineState))
    cs.high()

#--------------------------------------------------------------------------------------------------------------------------#
# Async Methods
#--------------------------------------------------------------------------------------------------------------------------#

"""
method to handle the async Request
read the request an analyse and evaluate it.
While waiting for request and for sending response other tasks are able to run
@param reader: reader to read the reuqest
@param writer: writer to send a response to the client
"""
async def handleRequest(reader, writer):
    global currentButtonState

    try:
        #waing for reading request
        request = await reader.read(2048) #wait until request - give other tasks option to run
        requestDecoded = request.decode("UTF-8")
        request = str(request)

        #split request to get requestUrl
        requestParts = request.split()
        if requestParts[1]:
            requestUrl = requestParts[1]
            print("Request URL: ", requestUrl)

            #analyze reuqestUrl to get value
            if requestUrl.find("/?exampleButton=buttonOn") != -1:
                currentButtonState = True
                transferEngineState(currentButtonState)
            elif requestUrl.find("/?exampleButton=buttonOff") != -1:
                currentButtonState = False
                transferEngineState(currentButtonState)
            else:
                pass

        print("Button State: " + str(currentButtonState) + "\n")
        # send response to client
        writer.write(createHtmlString())

        #allow other task to run (data ist being sent)
        await writer.drain()
        await writer.wait_closed()

    except OSError as e:
        print("connection error " + str(e.errno) + " " + str(e))



"""
async main method
the async server and the async run Value Methode is started
also run a counter value that is also shown in the HTTP Response
the value is printed every 10000 times
"""
async def main():

    #setting up async tasks
    print("Setup Server")
    server = uasyncio.start_server(handleRequest, "0.0.0.0", 80)
    uasyncio.create_task(server)

    while True:
        await uasyncio.sleep(0) #give other tasks option to run

#--------------------------------------------------------------------------------------------------------------------------#
# Running Code - Starting Main
#--------------------------------------------------------------------------------------------------------------------------#

# Setup the Accespoint
accesPoint = network.WLAN(network.AP_IF)
setupAccespoint(accesPoint)

# Start the Async Code
try:
    uasyncio.run(main())
finally:
    uasyncio.new_event_loop()
