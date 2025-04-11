"""
Example: async control of an accespoint connection and cam control with more advanced options
- the accespoint provide a html site to control a value (buttonState) with a button on this hmtl site
- handles the incoming requests an updates the buttonState
- parallel there are running other task (increase some counters), to make sure other task could run,
  while waiting for incoming reqeusts

Inspired of OpenMV examples codes, some help of the OpenMV Forum posts and this video tutorial series: https://www.youtube.com/watch?v=eym8NpHr9Xw
@author Tom Seiffert
"""

import time
import network
import uasyncio

ssid = 'NXP-Cup 2025'
password = '1234567890'

currentButtonState = False
globalCounter = 0


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
            <button name="exampleButton" value='buttonOn' type='submit'>  Button ON </button>
            <p></p>
            <button name="exampleButton" value='buttonOff' type='submit'> Button OFF </button>
        </form>
        <p> The Button is ''' + str(currentButtonState) + ''' </p>
        <p> The Current Counter is ''' + str(globalCounter) + '''
    </body>
    </html>
    '''
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
        print("Reqeust: ", requestDecoded)

        #split request to get requestUrl
        requestParts = request.split()
        if requestParts:
            requestUrl = requestParts[1]
            print("Request URL: ", requestUrl)

            #analyze reuqestUrl to get value
            if requestUrl.find("/?exampleButton=buttonOn") != -1:
                currentButtonState = True
            elif requestUrl.find("/?exampleButton=buttonOff") != -1:
                currentButtonState = False
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
async test method to increase a value
just increase a counter value and print it every 15000 times
"""
async def runValues():
    counter = 0
    while True:
        counter += 1
        if counter % 15000 == 0:
            print("Value Counter: " + str(counter))
        await uasyncio.sleep(0) #give other tasks the option to run

"""
async main method
the async server and the async run Value Methode is started
also run a counter value that is also shown in the HTTP Response
the value is printed every 10000 times
"""
async def main():
    #acces to global Variable
    global currentButtonState
    global globalCounter

    #setting up async tasks
    print("Setup Server")
    server = uasyncio.start_server(handleRequest, "0.0.0.0", 80)
    uasyncio.create_task(server)
    uasyncio.create_task(runValues())

    while True:
        globalCounter +=1
        if globalCounter % 10000 == 0:
            print("Main Counter: " + str(globalCounter))
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
