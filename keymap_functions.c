void shift_esc_is_tilde(bool pressed) {
    if (pressed) {
        if (get_mods() & MOD_LSFT) {
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
