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

#ifdef RGB_MATRIX_ENABLE
#    include "rgb.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    NS_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
    KC_LGUI, NU_A   , KC_S   , KC_D   , SY_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_LALT, MY_MEH ,     QK_LEAD, KC_SPC
  ),

  [LAYER_GAME] = LAYOUT_voyager(
    KC_ESC , KC_5   , KC_1   , KC_2   , KC_3   , KC_4   ,                       KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
    KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                       KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , TT_NUM ,
    KC_G   , KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   ,                       KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT,
    KC_B   , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT, NV_SLSH, KC_ENT ,
                                                 KC_SPC , KC_LALT,     QK_LEAD, KC_SPC
  ),

  [LAYER_SYM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_BSPC,
    _______, KC_GRV , KC_AT  , KC_COLN, KC_DLR , KC_CIRC,                       KC_PERC, KC_AMPR, KC_ASTR, KC_PIPE, MY_ARRW, KC_UNDS,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_TILD,                       KC_DQUO, KC_LCBR, KC_LPRN, KC_RPRN, KC_SCLN, MY_FARW,
    _______, KC_SLSH, KC_LABK, KC_RABK, MY_COLN, MY_MEMO,                       KC_QUES, KC_RCBR, KC_LBRC, KC_RBRC, KC_HASH, KC_ENT ,
                                                 KC_BSLS, _______,     XXXXXXX, _______
  ),

  [LAYER_NAV] = LAYOUT_voyager(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,                       EE_CLR , DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, QK_LLCK,
    _______, KC_LCTL, MY_CSTB, MY_CTAB, XXXXXXX, XXXXXXX,                       KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, XXXXXXX,
                                                 _______, _______,     KC_CAPS, _______
  ),

  [LAYER_NUM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, QK_LLCK,
    _______, _______, _______, _______, _______, _______,                       KC_EQL , KC_4   , KC_5   , KC_6   , KC_COLN, KC_PERC,
    _______, _______, _______, _______, _______, _______,                       KC_TILD, KC_1   , KC_2   , KC_3   , KC_MINS, KC_SLSH,
                                                 _______, _______,     HM_NSPC, KC_0
  ),

  [LAYER_NUMSYM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       KC_HASH, KC_J   , KC_LPRN, KC_RPRN, KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______,                       KC_EQL , KC_I   , KC_LBRC, KC_RBRC, KC_SCLN, KC_BSLS,
    _______, _______, _______, _______, _______, _______,                       KC_1   , KC_0   , KC_LABK, KC_RABK, KC_MINS, KC_ENT ,
                                                 _______, _______,     HM_NSPC, KC_RCBR
  ),
};

/// Chordal Hold Layout
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_voyager(
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', '*', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                        '*', '*',  '*', '*'
);
// clang-format on
