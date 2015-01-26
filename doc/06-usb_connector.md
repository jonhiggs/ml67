# Using the Original Controller

I believe that it's possible to use the original controller as a USB hub for your Teensy.

There are two main chips on the board. The lager one to the centre is a CY7C63413C microcontroller. The other one is a GL850G four port USB controller.

The USB controller chip has two USB ports unused and I believe you could connect the Teensy to it. Unfortunately I was unable to make a connection to it without shorting things out because it's a crazy small surface-mount thing.If you manage, please let me know how it went.

I was successfully able to disable the microcontroller by disconnecting it's power. The bottom-right corner pin is it's power. I scratched through the etch leading into it. Afterwards, the keyboard was no longer seen and I had a one-port USB hub.
