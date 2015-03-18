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
 *   bit 0      ||||+- Left_Control
 *   bit 1      |||+-- Left_Shift
 *   bit 2      ||+--- Left_Alt
 *   bit 3      |+---- Left_Gui
 *   bit 4      ||||+- Right_Control
 *   bit 5      |||+-- Right_Shift
 *   bit 6      ||+--- Right_Alt
 *   bit 7      |+---- Right_Gui
 */

bool controlled() {
    return ((get_mods() & (1 << 0)) != 0) || ((get_mods() & (1 << 4)) != 0);
}

bool shifted() {
    return ((get_mods() & (1 << 1)) != 0) || ((get_mods() & (1 << 5)) != 0);
}

bool alted() {
    return ((get_mods() & (1 << 2)) != 0) || ((get_mods() & (1 << 6)) != 0);
}

bool guied() {
    return ((get_mods() & (1 << 3)) != 0) || ((get_mods() & (1 << 7)) != 0);
}

void ctrl_h_is_backspace(bool pressed) {
    uint8_t mods = get_mods();
    if (pressed) {
        // press the keys
        if ( controlled() ) {
            clear_mods();
            add_key(KC_BSPC);
            send_keyboard_report();
            add_mods(mods);
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
            add_mods(mods);
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
    }
}

void special_esc(bool pressed) {
    if (pressed) {
        if (shifted() || guied()) {
            add_key(KC_GRV);
        } else {
            add_key(KC_ESC);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
}

void special_backspaces(bool pressed) {
    uint8_t mods = get_mods();

    if (pressed) {
        if ( shifted() && alted() ) {
            /* forward delete word. */
            /* ESC, D */
            clear_mods();
            add_key(KC_ESC);
            send_keyboard_report();
            add_key(KC_D);
            send_keyboard_report();
            add_mods(mods);
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
            add_mods(mods);
        } else if ( controlled() ) {
            /* forward delete. */
            /* DELETE */
            clear_mods();
            add_key(KC_DELETE);
            send_keyboard_report();
            add_mods(mods);
        } else {
            /* backwards delete */
            /* BSPC */
            add_key(KC_BSPC);
            send_keyboard_report();
        }
    } else {
        clear_keyboard_but_mods();
    }
}
