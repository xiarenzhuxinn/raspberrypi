#!/usr/bin/python3
#------------------------------------------------------
#
#       This is a program for PCF8591 Module. 
#
#       Warnng! The Analog input MUST NOT be over 3.3V!
#    
#       In this script, we use a poteniometer for analog
#   input, and a LED on AO for analog output. 
#
#       you can import this script to another by:
#   import PCF8591 as ADC
#   
#   ADC.Setup(Address)  # Check it by sudo i2cdetect -y -1
#   ADC.read(channal)   # Channal range from 0 to 3
#   ADC.write(Value)    # Value range from 0 to 255     
#
#------------------------------------------------------
import smbus 
import time

# for RPI version 1, use "bus = smbus.SMBus(1)"
bus = smbus.SMBus(1) 

def setup(Addr):
	global address
	address = Addr

def read(chn): #channel
	if chn == 0:
		bus.write_byte(address,0x40)
	if chn == 1:
		bus.write_byte(address,0x41)
	if chn == 2:
		bus.write_byte(address,0x42)
	if chn == 3:
		bus.write_byte(address,0x43)
	bus.read_byte(address) 
	return bus.read_byte(address)

def write(val):
	temp = val
	temp = int(temp) 
	# print temp to see on terminal else comment out
	bus.write_byte_data(address, 0x40, temp) 

def loop():
	while True:
		print ('ecl_level AIN0 = ', read(0))
		print ('light_dz  AIN1 = ', read(1))
		print ('tmp_dz    AIN1 = ', read(2))
		tmp = read(0)
		tmp = tmp*(255-125)/255+125 
		write(tmp)
		time.sleep(2)

def exit():
    return 0
if __name__ == "__main__":
    try:
        setup(0x48) 
        loop()
    except KeyboardInterrupt:
        exit()
