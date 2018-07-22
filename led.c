/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"

#include "led.h"
#include "debug.h"

void led_layer_set(uint32_t state) {
    DDRD |= (1<<7);
    dprint("Set LEDs for layer change\n");

    /* Led for Layer 1 */
    if ((1<<1 & state) != 0) {
        dprint("Layer 1: on\n");
        PORTD |= (1<<7);
    } else {
        dprint("Layer 1: off\n");
        PORTD &= ~(1<<7);
    }
}


/* LED pin configuration
 * Caps Lock: Low PD5
 */
void led_set(uint8_t usb_led) {
    // Set as output.
    DDRD |= (1<<6);

    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        PORTD |= (1<<6);
    } else {
        PORTD &= ~(1<<6);
    }
}
