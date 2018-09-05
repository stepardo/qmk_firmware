/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <quantum.h>
#include "action_layer.h"

extern keymap_config_t keymap_config;
enum planck_layers {
  _QWERTY,
  _MOUSE,
  _DIRECTIONS,
  _BRACKETS,
  _EMACS,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum macros {
  M_EMACS_LEFT  = 3,
  M_EMACS_RIGHT = 4,
  M_EMACS_OTHER = 5,
};

#define M_XO M(0) // emacs switch window
#define M_XB M(1) // emacs switch buffer
#define M_AT M(2) // alt-tab
#define M_E_L M(M_EMACS_LEFT)
#define M_E_R M(M_EMACS_RIGHT)
#define M_E_O M(M_EMACS_OTHER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
#define O_LSFT  OSM(MOD_LSFT)
#define O_RSFT  OSM(MOD_RSFT)
#define O_RALT  OSM(MOD_RALT)
//#define AT_BSPC ALT_T(KC_BSPC)
//#define CT_SPC  CTL_T(KC_SPC)
#define AT_BSPC KC_BSPC
#define CT_SPC  KC_SPC

[_QWERTY] =
{
  {CTL_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,    KC_U,       KC_I,     KC_O,    KC_P, CTL_T(KC_MINS)},
  {ALT_T(KC_ESC),  KC_A,    KC_FN3,  KC_FN1,  KC_FN0,     KC_G,     KC_H,    KC_FN2,     KC_K,     KC_L,    KC_SCLN, ALT_T(KC_QUOT)},
  {O_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,     KC_N,    KC_M,       KC_COMM,  KC_DOT,  KC_SLSH, O_RSFT },
  {KC_LALT, KC_LCTL, KC_LALT, KC_LGUI, OSL(_LOWER),AT_BSPC,  CT_SPC, OSL(_RAISE), O_RALT,   KC_DOWN, M_XB,    KC_LCTL}
},

[_MOUSE] = {
  {_______, _______, _______, _______, _______,     _______, KC_WH_L, KC_WH_D,        KC_WH_U, KC_WH_R,  _______, _______},
  {_______, _______, _______, _______, _______,     _______, KC_MS_L, KC_MS_D,        KC_MS_U, KC_MS_R,  _______, _______},
  {_______, _______, _______, _______, _______,     _______, _______, _______,        _______, _______,  _______, _______},
  {_______, _______, _______, _______, KC_WWW_BACK, KC_BTN1, KC_BTN2, KC_WWW_FORWARD, _______, _______,  _______, _______}
},

[_DIRECTIONS] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY},
  {_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MUTE},
  {_______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, KC_VOLU},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD}
},

[_BRACKETS] = {
  {_______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY},
  {_______, _______, _______, KC_DEL,  KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, KC_MUTE},
  {_______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_VOLU},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD}
},

[_EMACS] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY},
  {_______, _______, _______, _______, _______, _______, M_E_L,   M_E_O,   M_E_O,   M_E_R,   _______, KC_MUTE},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PLUS,    KC_EQL,     KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_HOME, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_ENT,  S(KC_NUHS), S(KC_NUBS), _______, _______, KC_END},
  {_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGDN, KC_PGUP, _______},
  {_______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_KEY(_MOUSE, KC_F),      // momentarily switch to layer if
  [1] = ACTION_LAYER_TAP_KEY(_DIRECTIONS, KC_D), // pressed long pressed long
  [2] = ACTION_LAYER_TAP_KEY(_BRACKETS, KC_J),
  [3] = ACTION_LAYER_TAP_KEY(_EMACS, KC_S),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
    case 0:
      return MACRO(D(LCTL), T(X), U(LCTL), T(O), END);
    case 1:
      return MACRO(D(LCTL), T(X), U(LCTL), T(B), END);
    case 2:
      return MACRO(D(LALT), T(TAB), U(LALT), END);
    case M_EMACS_LEFT:
      return MACRO(D(LCTL), T(X), U(LCTL), T(LEFT), END);
    case M_EMACS_RIGHT:
      return MACRO(D(LCTL), T(X), U(LCTL), T(RIGHT), END);
    case M_EMACS_OTHER:
      return MACRO(D(LCTL), T(X), U(LCTL), T(O), END);
    }
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        set_oneshot_layer(_LOWER, ONESHOT_START); // layer_on
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        set_oneshot_layer(_LOWER, ONESHOT_PRESSED); // layer_off
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        set_oneshot_layer(_RAISE, ONESHOT_START);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        set_oneshot_layer(_RAISE, ONESHOT_PRESSED);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
