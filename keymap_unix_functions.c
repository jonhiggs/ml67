/*
Copyright 2015 Jon Higgs <jhiggs@eml.cc>

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

#include "action_util.h"
#include "debug.h"

 /*
 *   bit 0      ||||+- Control
 *   bit 1      |||+-- Shift
 *   bit 2      ||+--- Alt
 *   bit 3      |+---- Gui
 *   bit 4      +----- LR flag(Left:0, Right:1)
 */

bool controlled() {
    return ( get_mods() & (1 << 0) != 0 );
}

bool shifted() {
    return ( get_mods() & (1 << 1) != 0 );
}

bool alted() {
    return ( get_mods() & (1 << 2) != 0 );
}

bool guied() {
    return ( get_mods() & (1 << 3) != 0 );
}

bool shift_alted() {
    return shifted() && alted();
}

void reset_mod_bits(mods) {
    debug("The Mod Bits are ");
    debug_bin(get_mods());
    debug("\nThe Mod Bits should be ");
    debug_bin(mods);
    debug("\n");

    /* Maybe this can be done in a loop */

    if (mods & MOD_LSFT ) {
        debugln("Turning LSFT back on.");
        add_mods(MOD_BIT(KC_LSFT));
    }

    if (mods & MOD_RSFT ) {
        debugln("Turning RSFT back on.");
        add_mods(MOD_BIT(KC_RSFT));
    }

    if (mods & MOD_LCTL ) {
        debugln("Turning LCTL back on.");
        add_mods(MOD_BIT(KC_LCTL));
    }

    if (mods & MOD_RCTL ) {
        debugln("Turning RCTL back on.");
        add_mods(MOD_BIT(KC_RCTL));
    }

    if (mods & MOD_LALT ) {
        debugln("Turning LALT back on.");
        add_mods(MOD_BIT(KC_LALT));
    }

    if (mods & MOD_RALT ) {
        debugln("Turning RALT back on.");
        add_mods(MOD_BIT(KC_RALT));
    }
}

void shift_esc_is_tilde(bool pressed) {
    if (pressed) {
        if ( shifted() ) {
            add_key(KC_GRV);
            send_keyboard_report();
        } else {
            add_key(KC_ESC);
            send_keyboard_report();
        }
    } else {
        clear_keyboard_but_mods();
    }
}

void ctrl_h_is_backspace(bool pressed) {
    uint8_t mods = get_mods();
    if (pressed) {
        // press the keys
        if ( controlled() ) {
            clear_mods();
            add_key(KC_BSPC);
            send_keyboard_report();
            reset_mod_bits(mods);
        } else {
            add_key(KC_H);
            send_keyboard_report();
        }
    } else {
        clear_keyboard_but_mods();
    }
}

void ctrl_a_is_home(bool pressed) {
    uint8_t mods = get_mods();
    if (pressed) {
        if ( controlled() ) {
            del_mods(MOD_BIT(KC_LCTRL));
            clear_mods();
            add_key(KC_HOME);
            send_keyboard_report();
            reset_mod_bits(mods);
        } else {
            add_key(KC_A);
            send_keyboard_report();
        }
    } else {
        clear_keyboard_but_mods();
    }
}

void tmux(bool pressed) {
    if (pressed) {
        add_mods(MOD_BIT(KC_LALT));
        add_key(KC_COMMA);
        send_keyboard_report();
        clear_keyboard();
        send_keyboard_report();
    }
}

void special_backspaces(bool pressed) {
    uint8_t mods = get_mods();

    if (pressed) {
        if ( shift_alted() ) {
            /* forward delete word. */
            /* ESC, D */
            clear_mods();
            add_mods(MOD_BIT(KC_LALT));
            add_key(KC_ESC);
            send_keyboard_report();
            add_key(KC_D);
            send_keyboard_report();
            reset_mod_bits(mods);
        } else if ( alted() ) {
            /* backwards delete word. */
            /* ESC, BSPC */
            del_mods(MOD_BIT(KC_LALT));
            add_key(KC_ESC);
            send_keyboard_report();
            del_key(KC_ESC);
            send_keyboard_report();
            add_key(KC_BSPC);
            send_keyboard_report();
            reset_mod_bits(mods);
        } else if ( shifted() ) {
            /* forward delete. */
            /* DELETE */
            clear_mods();
            add_key(KC_DELETE);
            send_keyboard_report();
            reset_mod_bits(mods);
        } else {
            // backwards delete
            add_key(KC_BSPC);
            send_keyboard_report();
        }
    } else {
        clear_keyboard_but_mods();
    }
}
