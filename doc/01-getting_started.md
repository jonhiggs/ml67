# 01. Getting Started

Before you commit to anything, it's paramount that you can at least program your Teensy and it works. Preferably you'll also be able to compile from the source to build your own HEX files.


## Download The Tools

There are a few programs that you will need to install.

- Arduino (v1.5.8)
- Teensy Loader (v1.15)

The [Arduino]() IDE contains the compiler to build your code into a HEX file that can be programmed onto the microcontroller.

The [Teensy Loader](https://www.pjrc.com/teensy/loader.html) is the tool that I use to program the microcontroller with the built HEX file.


## Programming The Teensy

Install the [Teensy Loader](https://www.pjrc.com/teensy/loader.html) for your operating system.

1. Program the `ml67_standard.hex` to your Teensy. (Hint: File -> Open HEX file)

2. Press the green 'Auto' button in the Teensy Loader until it's illuminated.

3. Press the button on the actual Teensy. It should say that it's erasing and programming the new firmware then say that it's rebooting.
4. At this point, shorting `B0` with `F0` should appear as though you are pressing the letter 'Q'.

If that works then well done. Otherwise keep trying and don't proceed until you get this much working.


## Building the Code

**TODO: Write this section.**  
For now, consult the internet. If you can't work it out, you won't be able to customise the firmware.


- get the tmk_keyboard repo.
- git submodule init
- git submodule update
- add the ml67 repo as a submodule in the keyboards directory.
- In the Makefile configure with the path to the Arduino.
- Configure `KEYMAP` in the Makefile.

make clean  
make

Among some others, a file named `ml67_<keymap>.hex` will be generated.

Load `ml67_<keymap>.hex` up in the 'Teensy Loader'.

**[Next](./02-circuit.md)**
