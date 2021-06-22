#!/usr/bin/env python
import RPi.GPIO as GPIO
import time
colors = [0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF, 0x00FFFF]
R = 40
G = 36
B = 38

def setup(Rpin, Gpin, Bpin):
	global pins 
	global p_R, p_G, p_B
	pins = {'pin_R': Rpin, 'pin_G': Gpin, 'pin_B': Bpin}
	GPIO.setmode(GPIO.BOARD)
	for i in pins:
		GPIO.setup(pins[i], GPIO.OUT)
		GPIO.output(pins[i], GPIO.LOW) # Set pins to low(0 V) to off led

	p_R = GPIO.PWM(pins['pin_R'], 2000) # set Frequece to 2KHz
	p_G = GPIO.PWM(pins['pin_G'], 1999)
	p_B = GPIO.PWM(pins['pin_B'], 5000)

	p_R.start(0) # Initial duty Cycle = 0(leds off)
	p_G.start(0)
	p_B.start(0)

def map(x, in_min, in_max, out_min, out_max):
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
def off():
	for i in pins:
		GPIO.output(pins[i], GPIO.LOW) # Turn off all leds

def setColor(col): # For example : col = 0x112233
	R_val = (col & 0xff0000) >> 16
	G_val = (col & 0x00ff00) >> 8
	B_val = (col & 0x0000ff) >> 0

	R_val = map(R_val, 0, 255, 0, 100)
	G_val = map(G_val, 0, 255, 0, 100)
	B_val = map(B_val, 0, 255, 0, 100)

	p_R.ChangeDutyCycle(R_val)
	p_G.ChangeDutyCycle(G_val)
	p_B.ChangeDutyCycle(B_val)

def loop():
	while True:
		for col in colors:
			setColor(col)
			time.sleep(1)

def destroy():
	p_R.stop() #Turn off PWM
	p_G.stop()
	p_B.stop()
	off() # Turn off all leds
	GPIO.cleanup()

if __name__ == "__main__":
	try:
		setup(R, G, B)
		loop()
	except KeyboardInterrupt:
		destroy()
