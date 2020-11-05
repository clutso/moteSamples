from network import LoRa
import socket
import time
import ubinascii
import pycom

s = socket.socket(socket.AF_LORA, socket.SOCK_RAW)

# set the LoRaWAN data rate
#s.setsockopt(socket.SOL_LORA, socket.SO_DR, 5)

# make the socket blocking
# (waits for the data to be sent and for the 2 receive windows to expire)

while True:
    pycom.rgbled(0x000f0f)
    s.setblocking(True)
    # send some data
    s.send(bytes([0x01, 0x02, 0x03]))
    pycom.rgbled(0x000000)
    # make the socket non-blocking
    # (because if there's no data received it will block forever...)
    # get any data received (if any...)
    s.setblocking(False)
    data = s.recv(64)
    print(data)
    time.sleep(150)