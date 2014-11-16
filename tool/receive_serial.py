#!/usr/bin/env python2


import serial
import time


def main():

    xbeeport = raw_input("Xbee-Port :")

    xbee = serial.Serial(xbeeport, 9600) 

    while True:
        #mes = xbee.readline()
        mes = xbee.read()
        print(mes)



if __name__ == '__main__':
    main()
