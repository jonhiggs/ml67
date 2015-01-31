# 04. TMK Firmware

As I mentioned in the Important Notes in [Chapter 2](./02-circuit.md), inside the tmk firmware, we need to flip our understanding of rows and columns. The direction of the diodes on the Filco board will prevent any keys to register. Rather than disassemble the entire thing and turn all the diodes around (and force you all to do the same), I'm going to allow this inconsistency and hope that one day in the future I can fix it in software.

So to reiterate, inside the firmware rows connect to the pins on the Filco beginning with `C` and the columns connect to the pins on the Filco beginning with `R`. From now on, I will clarify which definition I'm meaning by the terms 'firmware row/column' or 'Filco row/column'.

Now with that cleared up, I'll start to go through the firmware.


## Modifying the Code

TODO


**[Next](./05-leds.md)**
