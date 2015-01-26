# TMK Firmware

Straight up, I'm going to introduce a curve-ball.

Inside the TMK firmware what is the row and the column is flipped around. The reason is because the circuit doesn't work the other way around. I believe the problem it doesn't is due to the direction of the diodes on the Filco board. I believe they are stopping all current, therefore causing none of the keys to register. Rather than disassemble the entire thing and turn all the diodes around (and force you all to do the same), I'm going to allow this inconsistency.

So inside the firmware rows connect to the pins on the Filco beginning with `C` and the columns connect to the pins on the Filco beginning with `R`. From now on, I will clarify which definition I'm meaning by the terms 'firmware row/column' or 'Filco row/column'.

Now with that cleared up, I'll start to go through the firmware.


## Modifying the Code

TODO
