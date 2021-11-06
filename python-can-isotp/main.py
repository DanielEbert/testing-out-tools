#!/usr/bin/env python3

import can
import isotp

bus1 = can.interface.Bus('test', bustype='virtual')
bus2 = can.interface.Bus('test', bustype='virtual')

canstack = isotp.CanStack(bus1, address=isotp.Address(txid=0x123, rxid=0x456))
stack.send(b'Hello, this is a long payload sent in small chunks')

while canstack.transmitting():
    # will throw an error because we recv no flow control packet
    canstack.process()
    time.sleep(canstack.sleep_time())
