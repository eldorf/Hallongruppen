#!/usr/bin/env python

import serial
import sys
import signal
import logging
import traceback
import subprocess

logging.basicConfig(filename='/home/pi/hallongruppen/alcometer/log.log',format='%(asctime)s - %(levelname)s: %(message)s', level=logging.DEBUG)

def shutdown(signum, frame):
    logging.debug("Closing down...")
    sys.exit()
signal.signal(signal.SIGINT, shutdown)

       
usbport = '/dev/ttyAMA0'
ser = serial.Serial(usbport, 9600, timeout=1)
ser.readline() # clear the buffer
alcometerIndex = 0
thermoIndex = 3

lampAon = false
lampBon = false
lampCon = false

logging.debug("STARTING...")
try:
    with open('/home/pi/hallongruppen/alcometer/termovalues.txt', 'w') as flog:
        while True:
            response = ser.readline().strip()
            [index, value ] = response.split(':')
            try:
                index = int(index)
                value = int(value)
            except ValueError:
                logging.debug("Unable to convert \"%s\" to int" % index)
                sys.exit(1)

            if index == alcometerIndex:
                logging.debug("Alcometer: {0}".format(value))
                with open('/home/pi/hallongruppen/homepage/alko_value', 'w') as f:
                    f.write(str(value))
                if (value > 385) :
                    subprocess.call(["/home/pi/hallongruppen/switchRemoteControl/switcher" ,"B", "on"]) 
                else if (value < 383):
                    subprocess.call(["/home/pi/hallongruppen/switchRemoteControl/switcher" ,"B", "off"]) 
                    

            if index == thermoIndex:
    #            prit "Thermometer: {0}".format(value)
                logging.debug("termoValue: {0}".format(value))
                flog.write(str(value) + '\n')
                k = 0.714
                m = -35.86
                temp = k*value + m
                if temp > 23:
                    subprocess.call(["/home/pi/hallongruppen/switchRemoteControl/switcher" ,"A", "on"]) 
                else if temp < 22:
                    subprocess.call(["/home/pi/hallongruppen/switchRemoteControl/switcher" ,"A", "off"]) 
                with open('/home/pi/hallongruppen/homepage/thermo_value', 'w') as f:
                    f.write(str(temp))
                logging.debug("Thermometer: %d (raw %d)" % (temp, value))
        #    else:
        #        print "%d : %d " % (index, value)
    ser.close()
except Exception:
    var = traceback.format_exc()
    logging.error(var)

