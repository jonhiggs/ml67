void osx_back_word() {
    /* alt-left */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LALT));
    add_key(KC_LEFT);
    send_keyboard_report();
    clear_mods();
    add_mods(mods);
}

void osx_forward_word() {
    /* alt-right */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LALT));
    add_key(KC_RIGHT);
    send_keyboard_report();
    clear_mods();
    add_mods(mods);
}

void osx_back_paragraph() {
    /* option-up, option-up */
    /* emacs is M-S-[ */
}

void osx_forward_paragraph() {
    /* option-down, option-down */
    /* emacs is M-S-] */
}

void osx_forward_delete_letter() {
    /* delete */
    uint8_t mods = get_mods();
    clear_mods();
    add_key(KC_DEL);
    send_keyboard_report();
    add_mods(mods);
}

void osx_forward_delete_word() {
    /* option-shift-right, backspace */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_RALT));
    add_mods(MOD_BIT(KC_LSHIFT));
    add_key(KC_RIGHT);
    send_keyboard_report();
    clear_mods();
    osx_cut();
    send_keyboard_report();
    add_mods(mods);
}

void osx_forward_delete_end_of_line() {
    /* cmd-shift-right, cmd-x */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LSHIFT));
    add_mods(MOD_BIT(KC_LGUI));
    add_key(KC_RIGHT);
    send_keyboard_report();
    clear_mods();
    osx_cut();
    send_keyboard_report();
    add_mods(mods);
}

void osx_delete_letter() {
    /* backspace */
}


void osx_delete_word() {
    /* cmd-shift-left, cmd-x */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LSHIFT));
    add_mods(MOD_BIT(KC_LALT));
    add_key(KC_LEFT);
    send_keyboard_report();
    clear_mods();
    osx_cut();
    send_keyboard_report();
    add_mods(mods);
}

void osx_delete_start_of_line() {
    /* shift-ctrl-left, cmd-x */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LSHIFT));
    add_mods(MOD_BIT(KC_LGUI));
    add_key(KC_LEFT);
    send_keyboard_report();
    clear_mods();
    osx_cut();
    send_keyboard_report();
    add_mods(mods);
}

void osx_cut() {
    /* cmd-x */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LGUI));
    add_key(KC_X);
    send_keyboard_report();
    clear_mods();
    add_mods(mods);
}

void osx_paste() {
    /* shift-ctrl-left, backspace */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_LGUI));
    add_key(KC_V);
    send_keyboard_report();
    clear_mods();
    add_mods(mods);
}
