// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
#    include "./rgb.h" // IWYU pragma: keep
#endif

/// Layout
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_MUTE,
        KC_F   , KC_UP  , KC_ESC ,
        KC_LEFT, KC_DOWN, KC_RGHT,
        KC_SPC , MS_BTN4, MS_BTN5
    ),

    [LAYER_MOUSE] = LAYOUT(
        TG(LAYER_MOUSE),
        MS_BTN4, MS_UP  , MS_BTN5,
        MS_LEFT, MS_DOWN, MS_RGHT,
        MS_BTN1, MS_BTN3, MS_BTN2
    ),

    [LAYER_MPV] = LAYOUT(
        TG(LAYER_MPV),
        KC_F   , KC_K   , KC_SCLN,
        KC_H   , KC_J   , KC_L   ,
        KC_SPC , KC_LEFT, KC_RGHT
    ),

    [LAYER_NUM] = LAYOUT(
        TG(LAYER_NUM),
        KC_7   , KC_8   , KC_9   ,
        KC_4   , KC_5   , KC_6   ,
        KC_1   , KC_2   , KC_3
    ),

    [LAYER_CALL] = LAYOUT(
        LCAG(KC_B),
        S(C(KC_K)), LSG(KC_R) , LSG(KC_E) ,
        LAG(KC_4) , LAG(KC_5) , LAG(KC_6) ,
        LCAG(KC_B), LCAG(KC_V), LCAG(KC_A)
    )
};
// clang-format on

/// Encoder
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_MOUSE] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [LAYER_NUM] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [LAYER_MPV] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_CALL] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_boot[] = {KC_SPC, KC_UP, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_mouse[] = {MS_BTN4, MS_BTN5, COMBO_END};
const uint16_t PROGMEM combo_mpv[] = {KC_SPC, MS_BTN4, COMBO_END};
const uint16_t PROGMEM combo_num[] = {KC_F, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_call[] = {KC_UP, KC_ESC, COMBO_END};

// LAYER_MOUSE
const uint16_t PROGMEM combo_mouse_base[] = {MS_BTN3, MS_BTN2, COMBO_END};

// LAYER_MPV
const uint16_t PROGMEM combo_mpv_base[] = {KC_SPC, KC_LEFT, COMBO_END};

// LAYER_NUM
const uint16_t PROGMEM combo_zero[] = {KC_1, KC_2, COMBO_END};

// LAYER_CALL
const uint16_t PROGMEM combo_call_base[] = {LSG(KC_R), LSG(KC_E), COMBO_END};
const uint16_t PROGMEM combo_call_leave[] = {LAG(KC_5), LAG(KC_6), COMBO_END};
const uint16_t PROGMEM combo_call_enter[] = {LCAG(KC_V), LCAG(KC_A), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
    COMBO(combo_mouse, TG(LAYER_MOUSE)),
    COMBO(combo_mouse_base, TG(LAYER_MOUSE)),
    COMBO(combo_mpv, TG(LAYER_MPV)),
    COMBO(combo_mpv_base, TG(LAYER_MPV)),

    COMBO(combo_num, TG(LAYER_NUM)),
    COMBO(combo_zero, KC_0),

    COMBO(combo_call, TG(LAYER_CALL)),
    COMBO(combo_call_base, TG(LAYER_CALL)),
    COMBO(combo_call_leave, G(KC_L)),
    COMBO(combo_call_enter, KC_ENTER),
};
// clang-format on
