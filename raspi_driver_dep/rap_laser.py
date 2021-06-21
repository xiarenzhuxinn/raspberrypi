import RPi.GPIO as GPIO
import time
LedPin = 11 # pin11
def setup():
    GPIO.setmode(GPIO.BOARD) # Numbers GPIOs by physical location
    GPIO.setup(LedPin, GPIO.OUT) # Set LedPin's mode is output
    GPIO.output(LedPin, GPIO.LOW) # Set LedPin LOW(0V) to off led
def loop():
    while True:
        print '...Laser off'
        GPIO.output(LedPin, GPIO.LOW) # led off
        time.sleep(0.5)
        print 'Laser on...'
        GPIO.output(LedPin, GPIO.HIGH) # led on
        time.sleep(0.5)
def destroy():
    GPIO.output(LedPin, GPIO.LOW)) # led off
    GPIO.cleanup() # Release resource
if __name__ == '__main__': # Program start from here
    setup()
    try:
        loop()
    except KeyboardInterrupt: # When 'Ctrl+C' is pressed, the child program destroy()
    destroy()
