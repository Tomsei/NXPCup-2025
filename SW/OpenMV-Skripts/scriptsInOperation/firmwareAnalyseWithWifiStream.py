"""
running firmware analysis - script like the normal one
added wifi streaming of the calculatet image with acces point

to stream the calculate sobel image this script needs the firmware version
where nxpcup.analyse() return the image

the wifi code was taken from the OpenMV-example: "mjpeg_streamer_ap_1"
@author Tom Seiffert
"""
import sensor
import time
import nxpcup
import network
import socket

#configurations
camOffset = 0

#settings of AP-Point
SSID = "NXP-Cup 2025"  # Network SSID
KEY = "1234567890"  # Network key (must be 10 chars)
HOST = ""  # Use first available interface
PORT = 8080  # Arbitrary non-privileged port

# init wlan module in AP mode.
wlan = network.WLAN(network.AP_IF)
wlan.config(ssid=SSID, key=KEY, channel=2)
wlan.active(True)

print("AP mode started. SSID: {} IP: {}".format(SSID, wlan.ifconfig()[0]))


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

nxpcup.setup(imageWidth, imageHight, camOffset)


"""
run the prepared spi transfer for the nxpcup data
"""
def spiWriteTrackCenters():
    cs.low()
    nxpcup.spiWrite(spi)
    cs.high()

"""
start the image streaming and runs the new endless loop
calculate the new picture and transfer the results with
spi and stream the calculatet image over the accespoint
@param client: client to stream the image Data
"""
def startStreaming(client):
    # Read request from client
    data = client.recv(1024)
    # Should parse client request here

    # Send multipart header
    client.send(
        "HTTP/1.1 200 OK\r\n"
        "Server: OpenMV\r\n"
        "Content-Type: multipart/x-mixed-replace;boundary=openmv\r\n"
        "Cache-Control: no-cache\r\n"
        "Pragma: no-cache\r\n\r\n"
    )

    # FPS clock
    clock = time.clock()

    # Start streaming images
    # NOTE: Disable IDE preview to increase streaming FPS.
    # new endless loop to run the logic (img stream and trackcenter calculation)
    while True:
        clock.tick()  # Track elapsed milliseconds between snapshots().
        img = sensor.snapshot()  # Take a picture and return the image.
        img = nxpcup.analyseImage(img, img.height(), 150)
        spiWriteTrackCenters()
        cframe = img.to_jpeg(quality=35, copy=True)
        header = (
            "\r\n--openmv\r\n"
            "Content-Type: image/jpeg\r\n"
            "Content-Length:" + str(cframe.size()) + "\r\n\r\n"
        )
        client.sendall(header)
        client.sendall(cframe)
        print(clock.fps())


server = None

#creating serve and wait for client to connect. Start streaming when a client connects
while True:
    if server is None:
        # Create server socket
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
        # Bind and listen
        server.bind([HOST, PORT])
        server.listen(5)
        # Set server socket to blocking
        server.setblocking(True)

    try:
        print("Waiting for connections..")
        client, addr = server.accept()
    except OSError as e:
        server.close()
        server = None
        print("server socket error:", e)
        continue

    try:
        # set client socket timeout to 2s
        client.settimeout(5.0)
        print("Connected to " + addr[0] + ":" + str(addr[1]))
        startStreaming(client)
    except OSError as e:
        client.close()
        print("client socket error:", e)
        # sys.print_exception(e)
