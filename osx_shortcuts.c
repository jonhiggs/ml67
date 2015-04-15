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

void osx_start_of_word() {
}

void osx_end_of_word() {
    add_mods(MOD_BIT(KC_LALT));
    add_key(KC_LEFT);
}

void osx_select_word() {
    uint8_t mods = get_mods();
    add_mods(MOD_BIT(KC_LSFT));
    osx_start_of_word();
    clear_mods();
    add_mods(mods);
}

/* Readline */
void osx_backward_word() {
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

void osx_delete_char() {
    /* delete */
    uint8_t mods = get_mods();
    clear_mods();
    add_key(KC_DEL);
    send_keyboard_report();
    add_mods(mods);
}

void osx_backward_delete_char() {
    /* backspace */
    uint8_t mods = get_mods();
    clear_mods();
    add_key(KC_BSPC);
    send_keyboard_report();
    add_mods(mods);
}

void osx_kill_word() {
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

void osx_backward_kill_word() {
    /* option-shift-left, backspace */
    uint8_t mods = get_mods();
    clear_mods();
    add_mods(MOD_BIT(KC_RALT));
    add_mods(MOD_BIT(KC_LSHIFT));
    add_key(KC_LEFT);
    send_keyboard_report();
    clear_mods();
    osx_cut();
    send_keyboard_report();
    add_mods(mods);
}

void osx_unix_word_rubout() {
    /* Really, this isn't the same as backward_kill_word. It should treat
     * hyphens the same as a space. I cannot work out how to make OSX do that
     * so I'm just substituting in backward_kill_word.
     */
    osx_backward_kill_word();
}


void osx_kill_line() {
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

void osx_backward_kill_line() {
    /* cmd-shift-left, cmd-x */
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

void osx_kill_region() {
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
 
void osx_upcase_word() {
    /* shift-option-left shift-option-command-u, option-right */
    osx_select_word();
}

void osx_downcase_word() {
    /* shift-option-left option-command-u, option-right */
    osx_select_word();
}

void osx_capitalize_word() {
    /* shift-option-left option-command-u, option-right */
    osx_select_word();
}


/* Emacs */
void osx_back_paragraph() {
    /* option-up, option-up */
    /* emacs is M-S-[ */
}

void osx_forward_paragraph() {
    /* option-down, option-down */
    /* emacs is M-S-] */
}

