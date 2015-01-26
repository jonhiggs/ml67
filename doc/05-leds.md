# LEDs

The original Filco LED circuit looks like this:

![Filco Led Circuit](../images/filco_led_circuit.png)

Because the original circuit has the switch on the ground, we need make some changes. 

1. Break the trace so that we can power each LED individually.
2. Ground the cathode legs that did go off to the switch (`D1` and `D2` on the original header).

The new circuit looks like this:

![Modified Led Circuit](../images/modified_led_circuit.png)

You can see where I have broken a trace. Either side of that break is where you can tap into each of the LEDs.

![Breaking Trace](../images/break_trace.png)

![LED Circuit](../images/led_circuit.png)

![LED On Teensy](../images/led_teensy.png)
