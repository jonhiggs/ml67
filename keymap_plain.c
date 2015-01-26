#include "keymap_common.h"

/* KEYMAP
    K00,K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,    \
    K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,       \
    K30,     K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,\
    K40, K41, K42, K43,           K44,          K45, K46, K47, K48, K49, K4A \

      ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,      \
      ESC,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      LCTL, LGUI, LALT, FN1,              SPC,              FN1,  RALT, RGUI, LEFT, DOWN, RGHT \

      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
*/

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,      \
      CAPS, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      LCTL, LGUI, LALT, FN1,              SPC,              FN1,  RALT, RGUI, LEFT, DOWN, RGHT \
    ),
    KEYMAP(   // LAYER 1: Function1
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS \
    ),
};

/* id for user defined functions */
enum function_id {
    BACKSPACE,
    ESC,
    HOME,
    SPACE,
    SPOTLIGHT,
    TMUX,
    DEL_WORD,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to layer 1
    [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2
    [10] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [11] = ACTION_FUNCTION(SPACE),            // Special Space Key.
    [13] = ACTION_FUNCTION(BACKSPACE),        // Ctrl-H sends backspace.
    [14] = ACTION_FUNCTION(HOME),             // Ctrl-A sends home.
    [15] = ACTION_FUNCTION(TMUX),             // tmux bind prefix
    [16] = ACTION_FUNCTION(DEL_WORD),         // Alt-Backspace deletes a word.
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;

  switch (id) {
    case BACKSPACE:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_BSPC);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
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
      break;

    case ESC:
      if (event.pressed) {
        // press the keys
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
      break;

    case HOME:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_HOME);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
        } else {
          add_key(KC_A);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_HOME);
        del_key(KC_A);
        send_keyboard_report();
      }
      break;

    case SPACE:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_SPC);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
         } else {
          add_key(KC_SPC);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_SPC);
        send_keyboard_report();
      }
      break;

    case TMUX:
      if (event.pressed) {
        add_mods(MOD_BIT(KC_LALT));
        add_key(KC_COMMA);
        send_keyboard_report();
        del_key(KC_COMMA);
        send_keyboard_report();
        del_mods(MOD_BIT(KC_LALT));
        send_keyboard_report();
      }
      break;

    case DEL_WORD:
      if (event.pressed) {
        if (get_mods() & MOD_LALT) {
          del_mods(MOD_BIT(KC_LALT));
          add_key(KC_ESC);
          send_keyboard_report();
          del_key(KC_ESC);
          send_keyboard_report();
          if (get_mods() & MOD_LSFT) {
            // with shift, forward delete word
            del_mods(MOD_BIT(KC_LSFT));
            add_key(KC_D);
            send_keyboard_report();
            add_mods(MOD_BIT(KC_LSFT));
            send_keyboard_report();
          } else {
            // without shift, backwards delete word
            add_key(KC_BSPC);
            send_keyboard_report();
          }
          add_mods(MOD_BIT(KC_LALT));
          send_keyboard_report();
        } else if (get_mods() & MOD_LSFT) {
          del_mods(MOD_BIT(KC_LSHIFT));
          add_key(KC_DELETE);
          add_mods(MOD_BIT(KC_LSHIFT));
          send_keyboard_report();
        } else {
          add_key(KC_BSPC);
          send_keyboard_report();
        }
      } else {
        del_key(KC_BSPC);
        del_key(KC_D);
        del_key(KC_DELETE);
        send_keyboard_report();
      }
      break;
  }

}
