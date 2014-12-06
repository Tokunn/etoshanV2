#!/usr/bin/env python2


import serial


class OpenSerial(object):

    def __init__(self, port):
        self.xbee = serial.Serial(port, 9600)

    def send_serial_cmd(self, cmd):
        self.xbee.write(cmd)


def main():

    port = "/dev/ttyUSB0"
    ard = OpenSerial(port)

    #cmd = raw_input("Please type command :")
    cmd = "$MAJOKO"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)
    cmd = "$NEKO__"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)
    cmd = "$OBAKE_"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)
    cmd = "$KAIDAN"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)
    cmd = "$KING__"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)
    cmd = "$BRUNA_"
    ard.send_serial_cmd(cmd)
    cmd = '\n'
    ard.send_serial_cmd(cmd)


if __name__ == '__main__':
    main()
