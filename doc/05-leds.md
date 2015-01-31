# 05. LEDs

The original Filco LED circuit looks like this:

![Filco Led Circuit](../images/filco_led_circuit.png)

Because the original circuit has the switch on the ground, we need make some changes.

1. Break the trace so that we can power each LED individually.
2. Ground the cathode legs that did go off to the switch (`D1` and `D2` on the original header).

The new circuit looks like this:

![Modified Led Circuit](../images/modified_led_circuit.png)

You can see where I have broken a trace. Either side of that break is where you can tap into each of the LEDs.

![Breaking The Trace](../images/break_trace.png)

![LED Circuit](../images/led_circuit.png)

You need to connect the Caps Lock LED to `D5` of the Teensy. I've connected Scroll Lock to `VCC`, effectively turning it into a Power LED. To be honest, I'm not even sure how I was able to turn on Scroll Lock in the original configuration.

![LED On Teensy](../images/led_teensy.png)


## Reference

This is an update table with the Caps Lock LED included.

| Filco    | Teensy |
|----------|--------|
| C1/C12   | B0     |
| C2/C14   | B1     |
| C3/C0    | B2     |
| C4       | B3     |
| C5       | E6     |
| C6       | B7     |
| C7/C13   | D0     |
| C8       | D1     |
| C9       | D2     |
| C10      | D3     |
| C11      | C6     |
| C15      | C7     |
| R0       | F0     |
| R1       | F1     |
| R2       | F4     |
| R3       | F5     |
| R4       | F6     |
| R5       | F7     |
| R6       | B6     |
| R7       | B5     |
| D1 (Caps)| D5     |
| SPARE    | D4     |
| SPARE    | B4     |
| SPARE    | D7     |
| SPARE    | D6     |


**[Next](./06-usb_connector.md)**
