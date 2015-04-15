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
#include "osx_shortcuts.c"

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

void action_b(bool pressed) {
    if (pressed) {
        if ( alted() ) {
            osx_backward_word();
        } else {
            add_key(KC_B);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
}

void action_f(bool pressed) {
    if (pressed) {
        if ( alted() ) {
            osx_forward_word();
        } else {
            add_key(KC_F);
        }
        send_keyboard_report();

    } else {
        clear_keyboard_but_mods();
    }
}

void action_d(bool pressed) {
    uint8_t mods = get_mods();

    if (pressed) {
        if ( controlled() ) {
            osx_delete_char();
        } else if ( alted() ) {
            osx_kill_word();
        } else {
            add_key(KC_D);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}

void action_u(bool pressed) {
    uint8_t mods = get_mods();
    if (pressed) {
        if ( controlled() ) {
            osx_delete_start_of_line();
        } else {
            add_key(KC_U);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}

void action_w(bool pressed) {
    uint8_t mods = get_mods();
    /* backwards delete a word */
    if (pressed) {
        if ( controlled() ) {
            osx_kill_region();
        } else {
            add_key(KC_W);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}

void action_k(bool pressed) {
    uint8_t mods = get_mods();
    /* backwards delete a word */
    if (pressed) {
        if ( controlled() ) {
            osx_kill_line();
        } else {
            add_key(KC_K);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}

void action_y(bool pressed) {
    uint8_t mods = get_mods();
    /* backwards delete a word */
    if (pressed) {
        if ( controlled() ) {
            osx_paste();
        } else {
            add_key(KC_Y);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}

void action_h(bool pressed) {
    uint8_t mods = get_mods();
    /* backwards delete a letter */
    if (pressed) {
        if ( controlled() ) {
            clear_mods();
            add_key(KC_BSPC);
            send_keyboard_report();
            add_mods(mods);
        } else {
            add_key(KC_H);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
    add_mods(mods);
}
