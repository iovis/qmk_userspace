// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE = 0,
    LAYER_MOUSE,
    LAYER_NUM,
};

/// Layout
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_MUTE,
        KC_F   , KC_UP  , KC_ESC ,
        KC_LEFT, KC_DOWN, KC_RGHT,
        KC_M   , MS_BTN4, MS_BTN5
    ),
    [LAYER_MOUSE] = LAYOUT(
        TG(LAYER_MOUSE),
        MS_BTN4, MS_UP  , MS_BTN5,
        MS_LEFT, MS_DOWN, MS_RGHT,
        MS_BTN1, MS_BTN3, MS_BTN2
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
    [LAYER_MOUSE] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [LAYER_NUM] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
};

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_boot[] = {KC_M, KC_UP, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_mouse[] = {MS_BTN4, MS_BTN5, COMBO_END};
const uint16_t PROGMEM combo_num[] = {KC_F, KC_UP, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
    COMBO(combo_mouse, TG(LAYER_MOUSE)),
    COMBO(combo_num, TG(LAYER_NUM)),
};
