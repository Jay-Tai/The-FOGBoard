// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycodes { DEPLOY = SAFE_RANGE, LOGIN, ENTER };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case LOGIN:
            SEND_STRING("fog");
            tap_code(KC_DOWN);
            SEND_STRING("password");
            tap_code(KC_ENTER);
            break;
        case DEPLOY:
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_ENTER);
            break;
        case ENTER:
            tap_code(KC_ENTER);
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(DEPLOY, LOGIN, ENTER)};