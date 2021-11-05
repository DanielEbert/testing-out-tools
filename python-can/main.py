#!/usr/bin/env python3

import can

bus1 = can.interface.Bus('test', bustype='virtual')
bus2 = can.interface.Bus('test', bustype='virtual')

msg1 = can.Message(arbitration_id=1, data=[1,2,3])
bus1.send(msg1)
msg2 = bus2.recv()

print(f'{msg1=}\n{msg2=}')
assert msg1.data == msg2.data
