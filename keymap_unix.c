#include "keymap_common.h"
#include "keymap_unix_functions.c"
#include "command.h"
#include "bootloader.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      FN13, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSLS, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, FN10,      \
      LCTL, A,    S,    D,    F,    G,    FN11, J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   NO , \
      FN14, NO,   FN1,  LGUI,             SPC,              RALT,  FN2, NO,   LEFT, DOWN, RGHT,\
      LGUI, LGUI                                                                               \
    ),
    KEYMAP(   // LAYER 1: Function1
      TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,SYSREQ, NO, \
      TRNS, NO,   NO,   END,  NO,   NO,   NO,   PGUP, NO,   NO,   NO,   NO,   NO,   DEL,      \
      TRNS, HOME, NO,   PGDN, NO,   NO,   LEFT, DOWN, UP,   RGHT, NO,   NO,         NO,       \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         TRNS, NO,   NO, \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   NO,   NO,   NO, \
      TRNS, TRNS                                                                              \
    ),
    KEYMAP(   // LAYER 2: Function2
      FN15, F14,  F15,  NO,   NO,   NO,   NO,   MPRV, MPLY, MNXT, MUTE, VOLD, VOLU, NO,   EJCT, \
      TRNS, NO,   NO,   UP,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         \
      TRNS, NO,   NO,   NO,   FN17, NO,   NO,   INS,  HOME, PGUP, BSPC, NO,         NO,         \
      CAPS, NO,   NO,   NO,   NO,   FN16, NO,   DEL,  END,  PGDN, NO,         TRNS, NO,   NO,   \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   NO,   NO,   NO,   \
      TRNS, TRNS                                                                                \
    ),
};

// id for user defined functions
enum function_id {
    BACKSPACE,
    CTRL_A,
    CTRL_H,
    ESC,
    PROGRAMMING,
    TMUX,
    OSX_PREV_WORD,
    OSX_NEXT_WORD,
};

// Fn action definition
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1),          // FN1 switch to layer 1
    [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2
    [10] = ACTION_FUNCTION(BACKSPACE),        // Alt-Backspace deletes a word.
    [11] = ACTION_FUNCTION(CTRL_H),           // Ctrl-H sends backspace.
    [12] = ACTION_FUNCTION(CTRL_A),           // Ctrl-A sends home.
    [13] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [14] = ACTION_FUNCTION(TMUX),             // tmux bind prefix
    [15] = ACTION_FUNCTION(PROGRAMMING),      // Program the Teensy.
    [16] = ACTION_FUNCTION(OSX_PREV_WORD),    // Previous Word in OSX
    [17] = ACTION_FUNCTION(OSX_NEXT_WORD),    // Next Word in OSX.
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case CTRL_H:
            ctrl_h_is_backspace(event.pressed);
            break;

        case ESC:
            special_esc(event.pressed);
            break;

        case CTRL_A:
            ctrl_a_is_home(event.pressed);
            break;

        case TMUX:
            tmux(event.pressed);
            break;

        case BACKSPACE:
            special_backspaces(event.pressed);
            break;

        case PROGRAMMING:
            clear_keyboard();
            debug("\n\nJump to bootloader... ");
            _delay_ms(1000);
            bootloader_jump(); // not return
            debug("not supported.\n");
            break;

        case OSX_PREV_WORD:
            osx_prev_word(event.pressed);
            break;

        case OSX_NEXT_WORD:
            osx_next_word(event.pressed);
            break;
    }
}
