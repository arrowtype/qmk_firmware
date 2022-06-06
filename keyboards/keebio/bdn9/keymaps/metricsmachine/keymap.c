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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        LSFT(LGUI(KC_M)), LGUI(KC_2), LGUI(KC_0),
        KC_UP, LGUI(KC_S), LGUI(LALT(KC_S)),
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
