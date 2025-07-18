// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "version.h"
#include "iovis/keymap.c"
#include "./rgb.h" // IWYU pragma: keep

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
    KC_LGUI, NU_A   , KC_S   , NU_D   , SY_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_LALT, MY_MEH ,     QK_LEAD, KC_SPC
  ),

  [LAYER_LINUX] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
    KC_LCTL, NU_A   , KC_S   , NU_D   , SY_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_LALT, KC_LGUI,     QK_LEAD, KC_SPC
  ),

  [LAYER_GAME] = LAYOUT_voyager(
    KC_ESC , KC_5   , KC_1   , KC_2   , KC_3   , KC_4   ,                       KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
    KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                       KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_MINS,
    KC_G   , KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   ,                       KC_H   , KC_J   , KC_K   , KC_L  , SY_SCLN, KC_QUOT,
    KC_B   , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT, NV_SLSH, KC_ENT ,
                                                 KC_SPC , KC_LALT,     QK_LEAD, KC_SPC
  ),

  [LAYER_DWARF] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_SPC , KC_LALT,     QK_LEAD, KC_SPC
  ),

  [LAYER_SYM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_BSPC,
    _______, KC_GRV , KC_LABK, KC_RABK, KC_DLR , MY_COLN,                       KC_PERC, KC_AMPR, KC_ASTR, KC_PIPE, KC_EQL , KC_UNDS,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_TILD,                       KC_DQUO, KC_LCBR, KC_LPRN, KC_RPRN, KC_SCLN, KC_COLN,
    _______, KC_SLSH, KC_BSLS, KC_AT  , KC_HASH, KC_CIRC,                       KC_QUES, KC_RCBR, KC_LBRC, KC_RBRC, KC_HASH, KC_ENT ,
                                                 _______, KC_0   ,     MY_CODE, _______
  ),

  [LAYER_NAV] = LAYOUT_voyager(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_DEL ,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,                       XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_F   , XXXXXXX,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_LCTL, MY_CSTB, MY_CTAB, KC_CAPS, XXXXXXX,                       KC_END , KC_HOME, KC_PGUP, KC_PGDN, QK_LLCK, KC_RSFT,
                                                 _______, _______,     KC_RCTL, _______
  ),

  [LAYER_NUM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       KC_ASTR, KC_7   , KC_8   , KC_9   , KC_EQL , QK_LLCK,
    _______, _______, _______, _______, _______, _______,                       KC_SLSH, KC_4   , KC_5   , KC_6   , KC_PLUS, KC_COLN,
    _______, _______, _______, _______, _______, _______,                       KC_COMM, KC_1   , KC_2   , KC_3   , KC_MINS, KC_ENT ,
                                                 _______, KC_DOT ,     KC_0   , KC_SPC
  ),

  [LAYER_MOUSE] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______,                       KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, MS_ACL2,
    _______, _______, _______, _______, _______, _______,                       KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, MS_ACL1,
    _______, _______, _______, _______, _______, _______,                       XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, TG_MOUS,
                                                 _______, _______,     MS_ACL0, KC_BTN1
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
