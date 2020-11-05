from network import LoRa
import socket
import time
import ubinascii
import pycom

pycom.heartbeat(False)
pycom.rgbled(0x000f00)
# Initialise LoRa in LORAWAN mode.
# Please pick the region that matches where you are using the device:
# Asia = LoRa.AS923
# Australia = LoRa.AU915
# Europe = LoRa.EU868
# United States = LoRa.US915

#lora = LoRa(mode=LoRa.LORAWAN, region=LoRa.US915,bandwidth=LoRa.BW_125KHZ, sf=7, coding_rate=LoRa.CODING_4_5, adr=True, public=True, tx_retries=2, device_class=LoRa.CLASS_A)
#lora = LoRa(mode=LoRa.LORAWAN, region=LoRa.US915,bandwidth=LoRa.BW_125KHZ, sf=7, coding_rate=LoRa.CODING_4_5,  device_class=LoRa.CLASS_A)
lora = LoRa(mode=LoRa.LORAWAN, region=LoRa.US915,bandwidth=LoRa.BW_125KHZ, sf=7, coding_rate=LoRa.CODING_4_5,  device_class=LoRa.CLASS_A)
"""
lora.add_channel(index=0, frequency= 903900000, dr_min= 3, dr_max= 3)
lora.add_channel(index=1, frequency= 904100000, dr_min= 3, dr_max= 3)
lora.add_channel(index=2, frequency= 904300000, dr_min= 3, dr_max= 3)
lora.add_channel(index=3, frequency= 904500000, dr_min= 3, dr_max= 3)
lora.add_channel(index=4, frequency= 904700000, dr_min= 3, dr_max= 3)
lora.add_channel(index=5, frequency= 904900000, dr_min= 3, dr_max= 3)
lora.add_channel(index=6, frequency= 905100000, dr_min= 3, dr_max= 3)
lora.add_channel(index=7, frequency= 905300000, dr_min= 3, dr_max= 3)
"""
#lora.add_channel(index=1, frequency= 903900000, dr_min= 4, dr_max= 4)
#lora.add_channel(index=1, frequency= 904100000, dr_min= 4, dr_max= 4)
"""
lora.add_channel(index=0, frequency= 903000000, dr_min= 4, dr_max= 4)
lora.add_channel(index=1, frequency= 903200000, dr_min= 4, dr_max= 4)
lora.add_channel(index=2, frequency= 903400000, dr_min= 4, dr_max= 4)
lora.add_channel(index=3, frequency= 903600000, dr_min= 4, dr_max= 4)
lora.add_channel(index=4, frequency= 903800000, dr_min= 4, dr_max= 4)
lora.add_channel(index=5, frequency= 904000000, dr_min= 4, dr_max= 4)
lora.add_channel(index=6, frequency= 904200000, dr_min= 4, dr_max= 4)
lora.add_channel(index=7, frequency= 904400000, dr_min= 4, dr_max= 4)
"""
lora.add_channel(index=8, frequency= 904600000, dr_min= 3, dr_max= 3)


#lora.init(mode, [region=LoRa.US915, frequency, tx_power, bandwidth=LoRa.BW_125KHZ, sf=7, preamble=8, coding_rate=LoRa.CODING_4_5, power_mode=LoRa.ALWAYS_ON, tx_iq=False, rx_iq=False, adr=False, public=True, tx_retries=2, device_class=LoRa.CLASS_A])
# create an OTAA authentication parameters, change them to the provided credentials
app_eui = ubinascii.unhexlify('70B3D57ED00364C6')
app_key = ubinascii.unhexlify('1F93D7158251630C1D0C784BF57D4B7B')
#uncomment to use LoRaWAN application provided dev_eui
dev_eui = ubinascii.unhexlify('70B3D5499C46BF34')
#pycom.rgbled(0x000000)
# join a network using OTAA (Over the Air Activation)
#uncomment below to use LoRaWAN application provided dev_eui
#lora.join(activation=LoRa.OTAA, auth=(app_eui, app_key), timeout=0)
for i in range (3000) :
    time.sleep_ms(1)

lora.join(activation=LoRa.OTAA, auth=(dev_eui,app_eui, app_key))
#lora.join(activation=LoRa.OTAA, auth=(dev_eui, app_eui, app_key))
# wait until the module has joined the network
#for i in range(5):
"""
count=0
while not lora.has_joined():
    pycom.rgbled(0x0f000f)
    #time.sleep_ms(10)
    if count < 20000: 
        count=count+1
        #time.sleep_ms(10)
        #time.sleep_ms(1)
    else :
        #pycom.rgbled(0x0f000f)
        print('New join request')
        lora.join(activation=LoRa.OTAA, auth=(dev_eui, app_eui, app_key), timeout=0)
        count=0
    #pycom.rgbled(0x000000)

while not lora.has_joined():
    time.sleep(5)
    print('Not yet joined...')
 """
pycom.rgbled(0x000f00)
print('Joined')

# create a LoRa socket
