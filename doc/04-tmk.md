# TMK Firmware

Straight up, I'm going to introduce a curve-ball.

Inside the TMK firmware what is the row and the column is flipped around. The reason is because the circuit doesn't work the other way around. I believe the problem it doesn't is due to the direction of the diodes on the Filco board. I believe they are stopping all current, therefore causing none of the keys to register.

So inside the firmware rows connect to the pins on the Filco beginning with `C` and the columns connect to the pins on the Filco beginning with `R`. From now on, I will clarify which definition I'm meaning by the terms 'firmware row/column' or 'Filco row/column'.

Now with that cleared up, I'll start to go through the firmware.


## Getting the Code

get the tmk_keyboard repo.
git submodule init
git submodule update

add the ml67 repo as a submodule in the keyboards.


## Building the Code

make clean
make <keyboard_type>


## Modifying the Code

TODO
