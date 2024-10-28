"""
Example: WiFi connection and cam control with button in browser
"""

import time
import network
import socket

ssid = 'XX'
password = 'XX'

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

# setup WiFi
wifi = network.WLAN(network.STA_IF)

#restart WiFi Interface
wifi.active(False)
time.sleep(1)
wifi.active(True)
wifi.connect(ssid,password)

#try a 10 times to connect
maxConnectionWait = 10
while maxConnectionWait > 0:
    #connection Error
    if wifi.status() < 0:
        print ("Connection Failed: " + str(wifi.status()))
        break
    elif wifi.status() == 3:
        print ("Connection Sucessfull: " + str(wifi.status()))
        break

    maxConnectionWait -= 1
    print("waiting for connection:" + str(maxConnectionWait))
    time.sleep(1)

#check connection
if wifi.status() != 3:
    #no connection
    raise RuntimeError("network coneection failed; Error: ", wifi.status())
else:
    print("WiFi Connected")
    status = wifi.ifconfig()
    print('network config:', wifi.ifconfig())



#setup socket
addr = (wifi.ifconfig()[0], 80)
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
