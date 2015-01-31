# 00. Introduction

This document is how to take a standard [Filco Minila]() and hack in the [TMK firmware]().

Externally it will look exactly the same as the original except the USB port can only be used for charging and the DIP switches at the bottom will no longer be functional

I've hacked a Minila before with the ML62 project. The difference between this and that is I customised the ML62 to be very specific to my own needs. I removed keys I thought I didn't need, then merged the matrix down. Doing that made it impossible for someone to use my project without making the same drastic customisations.

I discovered that my drastic customisations backfired making it impossible for me to add keys back in. In this project I'm not going to remove any keys from the keymap. It will use more pins on the Teensy but that's a better compromise.

I retrospectively tried to document the ML62 project long after most of the work was done. Hence, the documentation was never as good as I wanted it to be. This time I'll be documenting the process as I go. It should be much more accurate but if you find any mistakes, please let me know.

## Tools and Stuff

- Filco Minila (I'm using Matrix Ver1.0 2012/10/17. I can't guarantee that anything else will work).
- Teensy 2
- Wire. Red, black and four other colours of your choice.
- Mini USB cable
- Soldering Iron
- Multimeter
- Wire Cutters
- Screwdrivers

To give you an idea on how long it should take I would expect that you should get it done in a weekend pretty easily. Just in case, I wouldn't count on it working on Monday morning. Have a spare keyboard.

Good luck in your own ML67 build.

**[Next](./01-getting_started.md)**
