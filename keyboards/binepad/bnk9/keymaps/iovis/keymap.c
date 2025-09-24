// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "./rgb.h" // IWYU pragma: keep

enum custom_keycodes {
    MY_BRWS = SAFE_RANGE,
};

#define MY_SPC LCTL_T(KC_SPC)
#define MY_BTN4 LCTL_T(MS_BTN4)

/// Layout
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_MUTE,
        KC_F   , KC_UP  , KC_ESC ,
        KC_LEFT, KC_DOWN, KC_RGHT,
        KC_SPC , MY_BTN4, MY_BRWS
    ),

    [LAYER_MOUSE] = LAYOUT(
        TG(LAYER_MOUSE),
        MS_BTN4, MS_UP  , MS_BTN5,
        MS_LEFT, MS_DOWN, MS_RGHT,
        MS_BTN1, MS_BTN3, MS_BTN2
    ),

    [LAYER_MPV] = LAYOUT(
        KC_M,
        KC_F   , KC_K   , KC_SCLN,
        KC_H   , KC_J   , KC_L   ,
        MY_SPC , KC_LEFT, KC_RGHT
    ),

    [LAYER_NUM] = LAYOUT(
        TG(LAYER_NUM),
        KC_7   , KC_8   , KC_9   ,
        KC_4   , KC_5   , KC_6   ,
        KC_1   , KC_2   , KC_3
    ),

    [LAYER_CALL] = LAYOUT(
        LCAG(KC_B),
        S(C(KC_K)), LSG(KC_R) , G(KC_L)   ,
        LAG(KC_4) , LAG(KC_5) , LSG(KC_E) ,
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
    [LAYER_MPV] = {ENCODER_CCW_CW(KC_DOWN, KC_UP)},
    [LAYER_CALL] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_boot[] = {KC_SPC, KC_UP, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_mouse[] = {MY_BTN4, MY_BRWS, COMBO_END};
const uint16_t PROGMEM combo_mpv[] = {KC_SPC, MY_BTN4, COMBO_END};
const uint16_t PROGMEM combo_num[] = {KC_F, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_call[] = {KC_UP, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_base_sidebar[] = {KC_SPC, MY_BRWS, COMBO_END};

// LAYER_MOUSE
const uint16_t PROGMEM combo_mouse_base[] = {MS_BTN3, MS_BTN2, COMBO_END};
const uint16_t PROGMEM combo_mouse_slow[] = {MS_BTN1, MS_BTN3, COMBO_END};
const uint16_t PROGMEM combo_mouse_normal[] = {MS_BTN4, MS_UP, COMBO_END};
const uint16_t PROGMEM combo_mouse_fast[] = {MS_UP, MS_BTN5, COMBO_END};

// LAYER_MPV
const uint16_t PROGMEM combo_mpv_base[] = {MY_SPC, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_mpv_quit[] = {KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM combo_mpv_random[] = {KC_K, KC_SCLN, COMBO_END};

// LAYER_NUM
const uint16_t PROGMEM combo_num_base[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_num_zero[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_num_backspace[] = {KC_8, KC_9, COMBO_END};

// LAYER_CALL
const uint16_t PROGMEM combo_call_base[] = {LSG(KC_R), G(KC_L), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
    COMBO(combo_base_sidebar, C(KC_S)),

    COMBO(combo_mouse, TG(LAYER_MOUSE)),
    COMBO(combo_mouse_base, TG(LAYER_MOUSE)),
    COMBO(combo_mouse_slow, MS_ACL0),
    COMBO(combo_mouse_normal, MS_ACL1),
    COMBO(combo_mouse_fast, MS_ACL2),

    COMBO(combo_mpv, TG(LAYER_MPV)),
    COMBO(combo_mpv_base, TG(LAYER_MPV)),
    COMBO(combo_mpv_quit, KC_Q),
    COMBO(combo_mpv_random, KC_SLSH),

    COMBO(combo_num, TG(LAYER_NUM)),
    COMBO(combo_num_base, TG(LAYER_NUM)),
    COMBO(combo_num_zero, KC_0),
    COMBO(combo_num_backspace, KC_BSPC),

    COMBO(combo_call, TG(LAYER_CALL)),
    COMBO(combo_call_base, TG(LAYER_CALL)),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t detected_os = detected_host_os();

    switch (keycode) {
        case MY_BRWS:
            if (record->event.pressed) {
                switch (detected_os) {
                    case OS_MACOS:
                        tap_code16(G(C(A(KC_F))));
                        break;
                    case OS_LINUX:
                        tap_code16(G(KC_F));
                        break;
                    default:
                        break;
                }
            }
            break;
    }

    return true;
}
