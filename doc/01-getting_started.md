# Getting Started

Before you commit to anything, it's paramount that you can at least program your Teensy and it works. Preferably you'll also be able to compile the source as well.


## Getting the Code

TODO

- get the tmk_keyboard repo.
- git submodule init
- git submodule update
- add the ml67 repo as a submodule in the keyboards.


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

make clean
make <keyboard_type>

Among, some others, a file named `ml67_<keyboard_type>.hex` will be generated.

Load `ml67_<keyboard_type>.hex` up in the [Teensy Loader]().

