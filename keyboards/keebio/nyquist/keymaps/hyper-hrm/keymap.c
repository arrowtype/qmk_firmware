#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 4 // has to be 15 or lower for the layer-tap LT() function to work

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Note: you can use "mod-tap" MT(MOD_HYPR, KC_ESC) for modified keys, or "layer-tap" LT(_ADJUST, KC_ESC) for layer keys ... or both

[_QWERTY] = LAYOUT(
  KC_ESC,      KC_1,       KC_2,                KC_3,                KC_4,                KC_5,              KC_6,    KC_7,               KC_8,                  KC_9,                KC_0,    KC_BSPC,
  KC_GRV,      KC_Q,       KC_W,                KC_E,                KC_R,                KC_T,              KC_Y,    KC_U,               KC_I,                  KC_O,                KC_P,    KC_BSLS,
  KC_TAB,      KC_A,       MT(MOD_LCTL, KC_S),  MT(MOD_LALT, KC_D),  MT(MOD_LGUI, KC_F),  KC_G,              KC_H,    MT(MOD_LGUI, KC_J), MT(MOD_LALT, KC_K),    MT(MOD_LCTL, KC_L),  KC_SCLN, KC_QUOT,
  KC_LSFT,     KC_Z,       KC_X,                KC_C,                KC_V,                KC_B,              KC_N,    KC_M,               KC_COMM,               KC_DOT,              KC_UP,   MT(MOD_RSFT, KC_ENT),
  ADJUST,      KC_LCTL,    KC_LALT,             KC_LGUI,             LT(LOWER, KC_SPC),   LT(LOWER, KC_SPC), LT(RAISE, KC_SPC),  LT(RAISE, KC_SPC),  MT(MOD_RGUI, KC_SLSH), KC_LEFT,             KC_DOWN, KC_RGHT
),

[_LOWER] = LAYOUT(
  KC_TILDE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
  BL_STEP,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_1,    KC_2,    KC_3,    KC_EQL,  _______,
  _______,  _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  _______, _______
),

[_RAISE] = LAYOUT(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TILDE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
  _______,  _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.  .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | Boot |RGB Tg|RGB Md|Hue Dn|Hue Up|  |Sat Dn|Sat Up|Val Dn|Val Up|      |  Del |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |  |      |Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |     |
 * `-----------------------------------------|  |-----------------------------------------'
 */

[_ADJUST] =  LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F17,  KC_F18,  KC_F19
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

enum combos {
  TABA_TAB,
  GRAVEQ_ESC,
  SCQU_ENT,
  PBSLS_BSPC,
  FR_SCREENSHOT,
};

const uint16_t PROGMEM graveq_combo[] = {KC_GRV, KC_Q, COMBO_END};
const uint16_t PROGMEM taba_combo[] = {KC_TAB, KC_A, COMBO_END};
const uint16_t PROGMEM scqu_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM pbsls_combo[] = {KC_P, KC_BSLS, COMBO_END};
const uint16_t PROGMEM screenshot_combo[] = {KC_R, MT(MOD_LGUI, KC_F), COMBO_END};

combo_t key_combos[] = {
  [GRAVEQ_ESC] = COMBO(graveq_combo, KC_ESC),
  [TABA_TAB] = COMBO(taba_combo, KC_TAB),
  [SCQU_ENT] = COMBO(scqu_combo, KC_ENT),
  [PBSLS_BSPC] = COMBO(pbsls_combo, KC_BSPC),
  [FR_SCREENSHOT] = COMBO(screenshot_combo, LGUI(LCTL(LSFT(KC_4)))),
};

