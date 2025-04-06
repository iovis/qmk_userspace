// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE = 0,
    LAYER_NUM,
};

// #define FN_QUOT LT(LAYER_NUMFN, KC_QUOT)

/// Layout
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_MUTE,
        KC_F   , KC_UP  , KC_ESC ,
        KC_LEFT, KC_DOWN, KC_RGHT,
        KC_M   , MS_BTN4, MS_BTN5
    ),
    [LAYER_NUM] = LAYOUT(
        TG(LAYER_NUM),
        KC_7   , KC_8   , KC_9   ,
        KC_4   , KC_5   , KC_6   ,
        KC_1   , KC_2   , KC_3
    )
};
// clang-format on

/// Encoder
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NUM] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
};

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_num[] = {MS_BTN4, MS_BTN5, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_num, TG(LAYER_NUM)),
};
