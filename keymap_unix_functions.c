/*
Copyright 2012,2013 Jon Higgs <jhiggs@eml.cc>

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

bool shifted() {
    return ( get_mods() & MOD_LSFT ) || ( get_mods() & MOD_RSFT );
}

bool controlled() {
    return ( get_mods() & MOD_LCTL ) || ( get_mods() & MOD_RCTL );
}

bool guied() {
    return ( get_mods() & MOD_LGUI ) || ( get_mods() & MOD_RGUI );
}

bool alted() {
    return ( get_mods() & MOD_LALT ) || ( get_mods() & MOD_RALT );
}

bool shift_alted() {
    return (( get_mods() & MOD_LSFT ) || ( get_mods() & MOD_RSFT )) &&
        (( get_mods() & MOD_LALT ) || ( get_mods() & MOD_RALT ));
}

void reset_mod_bits(mods) {
    debug("The Mod Bits are ");
    debug_bin(get_mods());
    debug("\nThe Mod Bits should be");
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
