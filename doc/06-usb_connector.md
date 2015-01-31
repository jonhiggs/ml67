# 06. USB Connector

There are a few ways you can go about connecting your computer to your Teensy.

The most simple is to plug directly into the Teensy. Drill a hole in you case. Tie a knot in your lead so it doesn't yank anything off and run it straight out to your computer.

I'm going to describe how to repurpose the original controller.

There are two main chips on the board. The lager one to the centre is a CY7C63413C microcontroller. The other one is a GL850G four port USB controller.

The USB controller chip has two USB ports unused and I believe you could connect the Teensy to it. Unfortunately I was unable to solder to it without shorting things out. It's a crazy small surface-mount thing. (If you manage, please let me know how you did it).

I disabled the microcontroller by disconnecting it's power source. The bottom-right corner pin is it's power. After I scratched through the trace the keyboard was no longer seen and I effectively turned it into a single port USB hub.

![Disconnected Microcontroller](../images/disconnected_microcontroller.png)

I removed the 28pin header so that strange things wouldn't happen. It may have been possible to leave it in and perhaps break a couple of traces, but I didn't try.

Start by removing the plastic spacer.

![Plastic Spacer](../images/plastic_spacer.png)

![No Plastic Spacer](../images/no_plastic_spacer.png)

Chop the pins off close to the board.

![No Pins](../images/no_pins.png)

Tape it up to avoid any shorts.

![All Covered Up](../images/all_covered_up.png)

I patched into the USB port.

![Patch Into USB](../images/patch_into_usb.png)

Ideally, you'd remove the data pins from the externally accessible USB port but I didn't do that. I'm not sure if I can without destroying it. If you have success, please let me know how.

Wrap it up in tape so nothing shorts the wrong things out or falls off when jostling it into the case. Then screw it back into place.

![USB Connector In Place](../images/usb_connector_in_place.png)

Put the keyboard in case.

![Keyboard In Case](../images/keyboard_in_case.png)

Drop the LED covers back on then put the shroud on.

![Reassembled](../images/reassembled.png)

Screw it together and you're all done. :)

**[Next](./07-programing_button.md)**
