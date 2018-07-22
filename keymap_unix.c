#include "keymap_common.h"
#include "keymap_unix_functions.c"
#include "command.h"
#include "bootloader.h"
#include "action_layer.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      FN13, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSLS, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSPC,      \
      LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   NO , \
      F4,   NO,   FN2,  LGUI,             SPC,              RALT, FN3,  NO,   LEFT, DOWN, RGHT,\
      FN4,  FN4                                                                                \
    ),
    KEYMAP(   // LAYER 1: OSX READLINE
      TRNS, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    TRNS, TRNS, TRNS, TRNS,\
      TRNS, Q,    FN25, E,    R,    T,    FN26, FN24, I,    O,    P,    TRNS, TRNS, TRNS,      \
      TRNS, A,    S,    FN23, FN21, G,    FN19, J,    FN27, L,    TRNS, TRNS,       TRNS,      \
      TRNS, Z,    X,    C,    V,    FN20, N,    M,    TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS                                                                               \
    ),
    KEYMAP(   // LAYER 2
      TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,SYSREQ, NO, \
      TRNS, NO,   NO,   END,  NO,   NO,   NO,   PGUP, NO,   NO,   NO,   NO,   NO,   DEL,      \
      TRNS, HOME, NO,   PGDN, NO,   NO,   LEFT, DOWN, UP,   RGHT, NO,   NO,         NO,       \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         TRNS, NO,   NO, \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   NO,   NO,   NO, \
      TRNS, TRNS                                                                              \
    ),
    KEYMAP(   // LAYER 3
      FN15, F14,  F15,  NO,   NO,   NO,   NO,   MPRV, MPLY, MNXT, MUTE, VOLD, VOLU, NO,   EJCT, \
      TRNS, NO,   NO,   UP,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         \
      TRNS, NO,   NO,   NO,   FN17, NO,   NO,   INS,  HOME, PGUP, BSPC, NO,         NO,         \
      CAPS, NO,   NO,   NO,   NO,   NO,   NO,   DEL,  END,  PGDN, NO,         TRNS, NO,   NO,   \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   NO,   NO,   NO,   \
      TRNS, TRNS                                                                                \
    ),
};

// id for user defined functions
enum function_id {
    ESC,
    PROGRAMMING,
    TMUX,
    ACTION_KEY_B,
    ACTION_KEY_D,
    ACTION_KEY_F,
    ACTION_KEY_H,
    ACTION_KEY_K,
    ACTION_KEY_U,
    ACTION_KEY_W,
    ACTION_KEY_Y
};

// Fn action definition
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TOGGLE(1),             // FN1 switch to Emacs layer
    [2] = ACTION_LAYER_TAP_TOGGLE(2),         // FN2 switch to layer 2
    [3] = ACTION_LAYER_MOMENTARY(3),          // FN3 switch to layer 3
    [4] = ACTION_LAYER_MOMENTARY(1),          // FN1 footswitch to Emacs layer
    [13] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [14] = ACTION_FUNCTION(TMUX),             // tmux bind prefix
    [15] = ACTION_FUNCTION(PROGRAMMING),      // Program the Teensy.
    [19] = ACTION_FUNCTION(ACTION_KEY_H),     // H Key on OSX.
    [20] = ACTION_FUNCTION(ACTION_KEY_B),     // B Key on OSX.
    [21] = ACTION_FUNCTION(ACTION_KEY_F),     // F Key on OSX.
    [23] = ACTION_FUNCTION(ACTION_KEY_D),     // D Key on OSX.
    [24] = ACTION_FUNCTION(ACTION_KEY_U),     // U Key on OSX.
    [25] = ACTION_FUNCTION(ACTION_KEY_W),     // W Key on OSX.
    [26] = ACTION_FUNCTION(ACTION_KEY_Y),     // Y Key on OSX.
    [27] = ACTION_FUNCTION(ACTION_KEY_K),     // K Key on OSX.
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case ESC:
            special_esc(event.pressed);
            break;

        case TMUX:
            tmux(event.pressed);
            break;

        case PROGRAMMING:
            clear_keyboard();
            dprint("Jump to bootloader... ");
            _delay_ms(50);
            bootloader_jump(); // not return
            dprint("not supported.\n");
            break;

        case ACTION_KEY_B:
            action_b(event.pressed);
            break;

        case ACTION_KEY_D:
            action_d(event.pressed);
            break;

        case ACTION_KEY_F:
            action_f(event.pressed);
            break;

        case ACTION_KEY_H:
            action_h(event.pressed);
            break;

        case ACTION_KEY_K:
            action_k(event.pressed);
            break;

        case ACTION_KEY_U:
            action_u(event.pressed);
            break;

        case ACTION_KEY_W:
            action_w(event.pressed);
            break;

        case ACTION_KEY_Y:
            action_y(event.pressed);
            break;
    }
}
