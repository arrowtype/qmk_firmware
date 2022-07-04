/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_keycodes {
    MULTIMACRO = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MULTIMACRO:
        if (record->event.pressed) {
            // when keycode MULTIMACRO is pressed
            SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LGUI)"m"SS_UP(X_LSFT)SS_UP(X_LGUI));
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LALT)"S"SS_UP(X_LGUI)SS_UP(X_LALT));
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)"m"SS_UP(X_LGUI)SS_UP(X_LCTL));
        } else {
            // when keycode MULTIMACRO is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Run MULTIMACRO key | Cmd + 2 | Cmd + 0             |
        | Up                 | Cmd + s | Cmd + Opt + Ctl + 0 |
        | Down               | Cmd + f | Hold: Layer 2       |
     */
    [0] = LAYOUT(
        MULTIMACRO,LGUI(KC_2), LGUI(KC_0),
        KC_UP, LGUI(KC_S), LGUI(LALT(LCTL(KC_0))),
        KC_DOWN, LGUI(KC_F), MO(1)
    ),
    /*
        | QK_BOOT          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        QK_BOOT  , BL_STEP, KC_STOP,
        KC_MNXT, KC_HOME, RGB_MOD,
        KC_MPRV, KC_END , _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code16(LSFT(KC_RIGHT));
        } else {
            tap_code16(LSFT(KC_LEFT));
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code16(LALT(KC_RIGHT));
        } else {
            tap_code16(LALT(KC_LEFT));
        }
    }
    return false;
}
