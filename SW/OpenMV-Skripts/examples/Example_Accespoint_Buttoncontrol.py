"""
Example: Accespoint connection and cam control with button in browser
"""

import time
import network
import socket

ssid = 'NXP-Cup 2025'
password = '123456789'

currentButtonState = False

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
    </body>
    </html>
    '''
    return html

#setup accespoint
accesPoint = network.WLAN(network.AP_IF)
accesPoint.active(False)
time.sleep(2)
accesPoint.config(essid=ssid, password=password)
accesPoint.active(True)

# wait until Accespoint is active
while accesPoint.active() == False:
    print("Waiting for active Accespoint")
    time.sleep(0.5)
print("Accespoint mode started. ssid: {} IP: {}".format(ssid, accesPoint.ifconfig()[0]))

#setup socket
addr = (accesPoint.ifconfig()[0], 80)
mySocket = socket.socket()
mySocket.bind(addr)
mySocket.listen(1)
print("listening on", addr)

#main loop - listen to request
while True:

    client, clientAddr = mySocket.accept()

    #read request
    request = client.recv(1024)
    requestDecoded = request.decode("UTF-8")
    request = str(request)
    print("Reqeust: ", requestDecoded)

    #split request to get requestUrl
    requestParts = request.split()
    requestUrl = requestParts[1]
    print("Request URL: ", requestUrl)

    #analyze reuqestUrl to get value
    if requestUrl.find("/?exampleButton=buttonOn") != -1:
        currentButtonState = True
    elif requestUrl.find("/?exampleButton=buttonOff") != -1:
        currentButtonState = False
    else:
        pass

    # send response to client
    client.send(createHtmlString())
    client.close()
    print("Button State: " + str(currentButtonState) + "\n")
