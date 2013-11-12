#!/usr/bin/env python

import serial
import sys
import signal

def shutdown(signum, frame):
    print "Closing down..."
    sys.exit()
signal.signal(signal.SIGINT, shutdown)

       
usbport = '/dev/ttyAMA0'
ser = serial.Serial(usbport, 9600, timeout=1)
ser.readline() # clear the buffer
alcometerIndex = 0
thermoIndex = 3

while True:
    response = ser.readline().strip()
    [index, value ] = response.split(':')
    try:
        index = int(index)
        value = int(value)
    except ValueError:
        print "Unable to convert \"%s\" to int" % index
        sys.exit(1)

    if index == alcometerIndex:
        print "Alcometer: {0}".format(value)
        with open('/home/pi/hallongruppen/homepage/alko_value', 'w') as f:
            f.write(str(value))

    elif index == thermoIndex:
        print "Thermometer: {0}".format(value)
        k = 0.611
        m = -26.111
        temp = k*value + m
        with open('/home/pi/hallongruppen/homepage/thermo_value', 'w') as f:
            f.write(str(temp))
#        print "Thermometer: %d (raw %d)" % (temp, value)
#    else:
#        print "%d : %d " % (index, value)
ser.close()
