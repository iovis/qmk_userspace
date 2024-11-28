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

#include "version.h"
#include "iovis/keymap.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , QK_LEAD,
    KC_LGUI, NU_A   , KC_S   , KC_D   , SY_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_LALT, MY_MEH ,     KC_MINS, KC_SPC
  ),

  [LAYER_GAME] = LAYOUT_voyager(
    KC_5   , KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   ,                       KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
    KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                       KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , QK_LEAD,
    KC_G   , KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   ,                       KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT,
    KC_B   , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT, NV_SLSH, KC_ENT ,
                                                 KC_SPC , KC_LALT,      TT_NUM, KC_SPC
  ),

  [LAYER_SYM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_BSPC,
    _______, KC_GRV , KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, XXXXXXX,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_COLN,                       KC_QUES, KC_LCBR, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO,
    _______, KC_COLN, KC_LABK, KC_RABK, MY_COLN, MY_CODE,                       MY_ARRW, KC_RCBR, KC_LBRC, KC_RBRC, KC_SLSH, KC_ENT ,
                                                 _______, MY_FARW,     KC_TILD, _______
  ),

  [LAYER_NAV] = LAYOUT_voyager(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LLCK,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, DM_REC1, DM_REC2,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_LCTL, MY_CSTB, MY_CTAB, DM_PLY1, DM_PLY2,                       KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, QK_BOOT,
                                                 _______, _______,     _______, KC_CAPS
  ),

  [LAYER_NUM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       MY_EURO, KC_DLR , KC_ASTR, KC_HASH, KC_TILD, _______,
    _______, _______, _______, _______, _______, _______,                       KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, KC_TAB ,
    _______, _______, _______, _______, _______, _______,                       KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    _______, _______, _______, _______, _______, _______,                       KC_TILD, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_PERC,
                                                 _______, _______,     QK_LLCK, KC_0
  ),
};
// clang-format on

/// RGB
// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
                                    MAGNT, YELLW,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , WHITE,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        CYAN , CYAN ,
    },

    [LAYER_GAME] = {
        // Left
        GREEN, BLUE , GREEN, GREEN, GREEN, GREEN,
        CYAN , BLUE , CYAN , MAGNT, CYAN , CYAN ,
        CYAN , BLUE , MAGNT, MAGNT, MAGNT, CYAN ,
        CYAN , BLUE , CYAN , CYAN , CYAN , CYAN ,
                                    CYAN , MAGNT,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , WHITE,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BLUE , CYAN ,
    },

    [LAYER_SYM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
                                    MAGNT, ORANG,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, ORANG, ORANG, ORANG, ORANG, BLACK,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, BLUE ,
        ORANG, CYAN ,
    },

    [LAYER_NAV] = {
        // Left
        BLUE , MAGNT, MAGNT, MAGNT, MAGNT, MAGNT,
        BLUE , WHITE, WHITE, WHITE, RED  , RED  ,
        BLUE , WHITE, WHITE, WHITE, ORANG, ORANG,
        BLUE , BLUE , BLUE , BLUE , GREEN, GREEN,
                                    MAGNT, YELLW,

        // Right
        MAGNT, MAGNT, MAGNT, MAGNT, MAGNT, BLUE ,
        BLACK, BLACK, BLACK, BLACK, BLACK, WHITE,
        GREEN, GREEN, GREEN, GREEN, BLACK, BLACK,
        YELLW, YELLW, YELLW, YELLW, YELLW, RED  ,
        CYAN , WHITE,
    },

    [LAYER_NUM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
                                    ORANG, YELLW,

        // Right
        ORANG, ORANG, ORANG, ORANG, ORANG, BLUE ,
        ORANG, GREEN, GREEN, GREEN, ORANG, BLUE ,
        ORANG, GREEN, GREEN, GREEN, ORANG, ORANG,
        ORANG, GREEN, GREEN, GREEN, ORANG, ORANG,
        WHITE, GREEN,
    },

};
// clang-format on
