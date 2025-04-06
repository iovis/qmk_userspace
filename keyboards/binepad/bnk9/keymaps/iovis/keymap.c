// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,
        KC_7   , KC_8    , KC_9    ,
        KC_4   , KC_5    , KC_6    ,
        KC_1   , KC_2    , LT(1, KC_3)
    ),
    [1] = LAYOUT(
        RM_TOGG,
        RM_HUEU,  RM_SATU,  RM_SPDU,
        RM_HUED,  RM_SATD,  RM_SPDD,
        RM_PREV,  RM_NEXT,  _______
    )
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
};
