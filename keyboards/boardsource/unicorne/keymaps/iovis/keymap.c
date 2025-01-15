// The MIT License (MIT)
//
// Copyright (c) 2024 David Marchante
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include QMK_KEYBOARD_H

#include "iovis/keymap.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, NU_A   , KC_S   , KC_D   , SY_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  HM_SPC , KC_LALT, MY_MEH ,     KC_SPC , KC_MINS, QK_LEAD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_GAME] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_G   , KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_B   , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_T   , KC_LALT, KC_SPC ,     KC_SPC , TT_NUM , QK_LEAD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_SYM] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_GRV , KC_AT  , KC_COLN, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, MY_ARRW, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_BSLS,     KC_DQUO, KC_LCBR, KC_LPRN, KC_RPRN, KC_SCLN, MY_FARW,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_SLSH, KC_LABK, KC_RABK, MY_COLN, MY_MEMO,     KC_QUES, KC_RCBR, KC_LBRC, KC_RBRC, KC_HASH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, KC_TILD,     _______, KC_UNDS, MY_EURO
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NAV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,     EE_CLR , XXXXXXX, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_MUTE, KC_VOLD, KC_VOLU, DM_REC1, DM_REC2,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, QK_LLCK,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, MY_CSTB, MY_CTAB, DM_PLY1, DM_PLY2,     KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, KC_CAPS
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [LAYER_NUM] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_TILD, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_PERC,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     HM_NSPC, KC_0   , QK_LLCK
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),
};
// clang-format on

/// RGB
#ifdef RGB_MATRIX_ENABLE
const int left_shift_index = 26;

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        YELLW,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        CYAN , WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [LAYER_GAME] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        CYAN , CYAN , CYAN , // BGT
        CYAN , MAGNT, CYAN , // RFV
        MAGNT, CYAN ,
        CYAN , MAGNT, MAGNT, // CDE
        CYAN , MAGNT, CYAN , // WSX
        BLUE , BLUE , BLUE , // ZAQ
        BLUE , CYAN , CYAN , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        GREEN, WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [LAYER_SYM] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        ORANG,
        ORANG, ORANG, ORANG,  // BGT
        ORANG, ORANG, ORANG,  // RFV
        MAGNT, BLUE ,
        ORANG, ORANG, ORANG,  // CDE
        ORANG, ORANG, ORANG,  // WSX
        ORANG, ORANG, ORANG,  // ZAQ
        RED  , BLUE , BLUE ,  // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        ORANG, ORANG, ORANG, // NHY
        ORANG, ORANG, ORANG, // UJM
        ORANG, WHITE,
        ORANG, ORANG, ORANG, // ,KI
        ORANG, ORANG, ORANG, // OL.
        ORANG, ORANG, ORANG, // /;P
        BLUE , ORANG, BLUE , // DEL, ', SFT
    },

    [LAYER_NAV] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        YELLW,
        GREEN, ORANG, RED  , // BGT
        RED  , ORANG, GREEN, // RFV
        MAGNT, BLUE ,
        BLUE , WHITE, WHITE, // CDE
        WHITE, WHITE, BLUE , // WSX
        BLUE , WHITE, WHITE, // ZAQ
        RED  , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        WHITE,
        YELLW, GREEN, RED  , // NHY
        BLACK, GREEN, YELLW, // UJM
        WHITE, WHITE,
        YELLW, GREEN, MAGNT, // ,KI
        BLACK, GREEN, YELLW, // OL.
        BLACK, BLACK, BLACK, // /;P
        WHITE, BLACK, RED  , // DEL, ', SFT
    },

    [LAYER_NUM] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        YELLW,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        GREEN,
        ORANG, ORANG, ORANG, // NHY
        GREEN, GREEN, GREEN, // UJM
        ORANG, WHITE,
        GREEN, GREEN, GREEN, // ,KI
        GREEN, GREEN, GREEN, // OL.
        ORANG, ORANG, ORANG, // /;P
        BLUE , ORANG, ORANG, // DEL, ', SFT
    },

};
#endif
// clang-format on
