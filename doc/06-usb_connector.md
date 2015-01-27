# USB Connector

There are a few ways you can go about connecting your computer to your Teensy.


## A Patch Lead

This is a short lead that runs from your Teensy to a female chassis mount plug.


## Hard Wire

Plug directly into the Teensy. Drill a hole in you case. Tie a knot in your lead so it doesn't yank anything off and run it straight out.


## Original Controller

I believe that it's possible to use the original controller as a USB hub for your Teensy.

There are two main chips on the board. The lager one to the centre is a CY7C63413C microcontroller. The other one is a GL850G four port USB controller.

The USB controller chip has two USB ports unused and I believe you could connect the Teensy to it. Unfortunately I was unable to make a connection to it without shorting things out because it's a crazy small surface-mount thing.If you manage, please let me know how it went.

I disabled the microcontroller by disconnecting it's power. The bottom-right corner pin is it's power. I scratched through the trace leading into it. Afterwards, the keyboard was no longer seen and I had a one-port USB hub.

![Disconnected Microcontroller](../images/disconnected_microcontroller.png)

It was now looking completely possible to use the original USB connector. I had to tap into the external USB port but that was okay with me.

I needed to remove the 28pin header so that strange things wouldn't happen. It may have been possible to leave it in and maybe break a couple of traces, but I didn't try.

Start by removing the plastic spacer.

![Plastic Spacer](../images/plastic_spacer.png)

![No Plastic Spacer](../images/no_plastic_spacer.png)

Chop off all the pins close to the board.

![No Pins](../images/no_pins.png)


Cover it up to avoid any surprises.

![All Covered Up](../images/all_covered_up.png)


Patched into the USB port. Ideally it would be nice to patch into a new port on the USB controller but that wasn't possible for me to do because it was all too small.

![Patch Into USB](../images/patch_into_usb.png)

Wrap it up in tape so nothing shorts the wrong things out or falls off when jostling it into the case. Then screw it back into place.

![USB Connector In Place](../images/usb_connector_in_place.png)

Put the keyboard in case.

![Keyboard In Case](../images/keyboard_in_case.png)

Drop the LED covers back on and put the shroud back on.

![Reassembled](../images/reassembled.png)

