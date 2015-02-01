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

void reset_mod_bits() {
    debug("Resetting the mod bits.\n");

    if (get_mods() & MOD_LSFT ) {
        debug("Turning LSFT back on.");
        add_mods(MOD_BIT(KC_LSFT));
    }

    if (get_mods() & MOD_LCTL ) {
        debug("Turning LCTL back on.");
        add_mods(MOD_BIT(KC_LCTL));
    }
}

void shift_esc_is_tilde(bool pressed) {
    if (pressed) {
        if (shifted) {
            add_key(KC_GRV);
            send_keyboard_report();
        } else {
            add_key(KC_ESC);
            send_keyboard_report();
        }
    } else {
        // release the keys.
        del_key(KC_GRV);
        del_key(KC_ESC);
        send_keyboard_report();
    }
}

void ctrl_h_is_backspace(bool pressed) {
    if (pressed) {
        // press the keys
        if (controlled) {
            del_mods(MOD_BIT(KC_LCTRL));
            add_key(KC_BSPC);
            send_keyboard_report();
            reset_mod_bits();
        } else {
            add_key(KC_H);
            send_keyboard_report();
        }
    } else {
        // release the keys.
        del_key(KC_BSPC);
        del_key(KC_H);
        send_keyboard_report();
    }
}
