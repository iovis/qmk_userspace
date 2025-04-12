// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "iovis/keymap.c"

#ifdef RGB_MATRIX_ENABLE
#    include "./rgb.h" // IWYU pragma: keep
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, NU_A   , KC_S   , NU_D   , SY_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  HM_ESC , KC_LALT, MY_MEH ,     KC_SPC , HM_UNDS, QK_LEAD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_LINUX] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, NU_A   , KC_S   , NU_D   , SY_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_ESC , KC_LALT, KC_LGUI,     KC_SPC , HM_UNDS, QK_LEAD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_GAME] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_G   , KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   ,     KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, FN_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_B   , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_T   , KC_LALT, KC_SPC ,     KC_SPC , TT_NUM , QK_LEAD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_SYM] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_GRV , KC_LABK, KC_RABK, KC_DLR , M_DASH ,     KC_PERC, KC_AMPR, KC_ASTR, KC_PIPE, KC_EQL , KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_TILD,     KC_DQUO, KC_LCBR, KC_LPRN, KC_RPRN, KC_SCLN, KC_COLN,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_SLSH, KC_BSLS, KC_AT  , MY_COLN, KC_CIRC,     KC_QUES, KC_RCBR, KC_LBRC, KC_RBRC, KC_HASH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, KC_0   ,     _______, KC_UNDS, MY_CODE
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NAV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,     XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_F   , XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, MY_CSTB, MY_CTAB, KC_CAPS, XXXXXXX,     KC_END , KC_HOME, KC_PGUP, KC_PGDN, QK_LLCK, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, KC_RCTL, QK_LLCK
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NUM] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_EQL , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_SLSH, KC_4   , KC_5   , KC_6   , KC_PLUS, KC_COLN,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_COMM, KC_1   , KC_2   , KC_3   , KC_MINS, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, KC_0   ,     KC_SPC , KC_DOT , QK_LLCK
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NUMSYM] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     KC_LCBR, KC_J   , KC_LPRN, KC_RPRN, KC_EQL , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_0   , KC_I   , KC_LBRC, KC_RBRC, KC_SCLN, KC_PLUS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_BSLS, KC_1   , KC_LABK, KC_RABK, KC_MINS, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     KC_SPC , KC_RCBR, XXXXXXX
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NUMFN] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     EE_CLR , KC_F7  , KC_F8  , KC_F9  , KC_F12 , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     DB_TOGG, KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F10 , XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     XXXXXXX, XXXXXXX, XXXXXXX
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_MOUSE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     MS_WHLL, MS_WHLD, MS_UP  , MS_WHLU, MS_WHLR, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     MS_BTN4, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN5, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX, TG_MOUS,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     MS_BTN1, XXXXXXX, TG_MOUS
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),
};

/// Chordal Hold Layout
const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_split_3x6_3(
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', '*', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',  '*', '*', '*'
);
// clang-format on
