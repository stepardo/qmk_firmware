#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define TAPPING_TERM 200

enum Layer
{
  BASE = 0,
  MOUSE,
  SYMB,
  NUMBERS,
};

enum macro_id
{
  ALT_TAB = 0,
  UML,
	ALT_F2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP(  // layer 0 : default
    // left hand
    KC_EQL,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,  M(ALT_F2),
    KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,  KC_WWW_BACK,
    KC_CAPS,  KC_A,    KC_S,    KC_D,     KC_FN0,   KC_G,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,  TD(UKEY),
    TG(SYMB), KC_GRV,  M(UML),  LT(NUMBERS, KC_LEFT),KC_RIGHT,
    CTL_T(KC_ESC), KC_LALT,
    KC_HOME,
    CTL_T(KC_BSPC), ALT_T(KC_DEL), KC_END,
    // right hand
    M(ALT_TAB),       KC_6, KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
    KC_WWW_FORWARD,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_BSLS,
    KC_H,     KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
    KC_ESC,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,
    KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,  KC_NO,
    KC_RALT,  CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,  RALT_T(KC_ENT), CTL_T(KC_SPC)
    ),
// Symbols layer, almost unused...
[SYMB] = KEYMAP(
       // left hand
       KC_PSCR,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_SLCK,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_PAUS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_INS ,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_0,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
//{KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
[NUMBERS] = KEYMAP(
       // left hand
       KC_TRNS, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
       KC_EQL,  KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_TRNS,
       KC_PLUS, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
       KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS, KC_TRNS,KC_INS ,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN,KC_MINS,
                KC_6,    KC_7,   KC_8,    KC_9,    KC_0,   KC_UNDS,
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10, KC_TRNS,
                KC_LEFT,KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[MOUSE] = KEYMAP(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_NO,   KC_NO,   KC_NO,
    // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO,
                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_NO,   KC_NO,
                         KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_BTN3, KC_BTN2, KC_BTN1
),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_KEY(MOUSE, KC_F), // momentarily switch to layer if
                                           // pressed long
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (!record) // prevent zero pointer accesses
    return MACRO_NONE;

  if (record->event.pressed)
    {
      switch(id)
        {
        case UML: // prefix key, needs to be followed by u, a or o
          return MACRO(T(CAPS), D(LSFT), T(QUOT), U(LSFT), END);
        case ALT_TAB:
          return MACRO(D(LCTL), T(T), U(LCTL), T(N), END); //MACRO(D(RALT), T(TAB), U(RALT), END);
        case ALT_F2:
          return MACRO(D(LCTL), T(T), U(LCTL), T(C), END); //MACRO(D(RALT), T(F2), U(RALT), END);
        default:
	  break;
	}
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer)
      {
      case BASE:
        break;
      case MOUSE:
        ergodox_right_led_1_on();
        break;
      default:
        // none
        break;
      }

};
