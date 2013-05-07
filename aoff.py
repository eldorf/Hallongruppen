from time import sleep
import RPi.GPIO as GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.OUT)


outputs = 'llllllllllkkklklklklkkklk'

kort = .00006

GPIO.output(23, GPIO.LOW)       
for i in xrange(4):

    for o in outputs: 
        GPIO.output(23, GPIO.HIGH)
        if o == 'l':
            sleep(kort*5.4)
            GPIO.output(23, GPIO.LOW)
            sleep(kort)
        else:
            sleep(kort)
            GPIO.output(23, GPIO.LOW)
            sleep(kort*5.4)
    sleep(.001)
         



