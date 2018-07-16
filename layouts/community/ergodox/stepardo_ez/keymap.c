/**
 * Based on kines-ish
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0
#define SYMB 1
#define MDIA 2
#define DIRECTIONS 3
#define MOUSE 4
#define EMPTY 5

#define EXWM_OPEN M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  | Grv  |Insert| Left | Right|                                       |  Up  | Down |   [  |   ]  |  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Alt  |       | LGui | Ctrl |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 |Backsp| Del  |------|       |------| Enter| Space|
 *                                 |ace   |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,  KC_ESC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,  KC_WWW_BACK,
        KC_ESC,   KC_A,    KC_S,    KC_FN1,   KC_FN0,   KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,  EXWM_OPEN,
        KC_ESC,   KC_GRV,  KC_INS,  KC_LEFT,  KC_RGHT,
                                               KC_LCTL,KC_LALT,
                                                       KC_HOME,
                          CTL_T(KC_BSPC),ALT_T(KC_DEL),KC_END,
        // right hand
             KC_ESC,         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_MINS,
             KC_WWW_FORWARD, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_BSLS,
                             KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
             KC_NO,          KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,
                                     KC_DOWN,KC_UP,  KC_LBRC,KC_RBRC,  KC_NO,
             KC_LGUI, KC_RCTL,
             KC_PGUP,
             KC_PGDN, ALGR_T(KC_ENT), CTL_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrScr  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ScrLk  |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Pause  |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_PSCR,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_SLCK,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_PAUS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[DIRECTIONS] = LAYOUT_ergodox(  // directions layer
        // left hand
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
                                                                     KC_TRNS,  KC_TRNS,
                                                                               KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,  KC_TRNS,
        // right hand
        KC_MUTE,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MPRV,   KC_MNXT,     KC_MPLY,
        KC_VOLU,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
                   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_TRNS,     KC_TRNS,
        KC_VOLD,   KC_TRNS,   KC_PGDN,   KC_PGUP,   KC_TRNS,   KC_TRNS,     KC_TRNS,
                              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,
        KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
[MOUSE] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
                                                                     KC_TRNS,  KC_TRNS,
                                                                               KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,  KC_TRNS,
        // right hand
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
                   KC_MS_L,   KC_MS_D,   KC_MS_UP,  KC_MS_R,   KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_WH_L,   KC_WH_D,   KC_WH_U,   KC_WH_R,   KC_TRNS,     KC_TRNS,
                              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,
        KC_TRNS,
        KC_BTN1,   KC_BTN2,   KC_BTN3
    ),
[EMPTY] = LAYOUT_ergodox(  // empty layer
        // left hand
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
                     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
                                       [0] = ACTION_LAYER_TAP_KEY(MOUSE, KC_F),
                                       [1] = ACTION_LAYER_TAP_KEY(DIRECTIONS, KC_D),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    return MACRO(D(LGUI), T(O), U(LGUI), END);
    break;
  default:
    break;
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
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
