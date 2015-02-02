#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,      \
      CAPS, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      LCTL, LALT, LGUI, FN1,              SPC,              FN1,  RGUI, RALT, LEFT, DOWN, RGHT \
    ),
    KEYMAP(   // LAYER 1: Function1
      GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  TRNS, TRNS,\
      TRNS, TRNS, TRNS, UP,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      TRNS, TRNS, LEFT, DOWN, RGHT, TRNS, TRNS, INS,  HOME, PGUP, BSPC, TRNS,       TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, DEL,  END,  PGDN, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS \
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to layer 1
};
