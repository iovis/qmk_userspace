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

#include "features/achordion.h"
#include "features/layer_lock.h"

/// Layers
enum layer_number {
    _BA = 0,
    _GA, // Gaming
    _SY, // Symbols
    _NV, // Navigation
    _NU, // Number Pad
    // _ME, // Media
};

/// Complex key definitions
// clang-format off
#define MY_CSTB S(C(KC_TAB))
#define MY_CTAB C(KC_TAB)
#define MY_EURO S(RALT(KC_2))
#define MY_MEH  LCA(KC_LCMD)
#define M_DASH  S(RALT(KC_MINS))

#define HM_RSFT RSFT_T(KC_ENT)
#define NU_F    LT(_NU, KC_F)
#define NV_SLSH LT(_NV, KC_SLSH)
#define SY_SCLN LT(_SY, KC_SCLN)
#define SY_A    LT(_SY, KC_A)
// clang-format on

/// Combos
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
};

/// Key Overrides
// Make shift+= return = to prevent issues when rolling
const key_override_t equals_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);

const key_override_t* key_overrides[] = {
    &equals_key_override,
};

/// Macros
enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    HM_Z,
    SMTD_KEYCODES_END,
    MY_LLCK,
};

/// Tap Dance
enum {
    TD_1P,
    TD_WIN,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_1P]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, G(S(KC_BSLS))),
    [TD_WIN] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, _GA),
};

/// SMTD
// There's a bug in v0.4 that requires to put it here
#include "features/sm_td.h"
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) { SMTD_MT(HM_Z, KC_Z, KC_LCTL) }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    // Freeze STMD timeout
    if (timeout == SMTD_TIMEOUT_RELEASE) {
        switch (keycode) {
            case HM_Z:
                return 50;
        }
    }

    return get_smtd_timeout_default(timeout);
}

/// Achordion
void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Allow same hand holds
    switch (tap_hold_keycode) {
        case NU_F:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LGUI:
                case KC_LSFT:
                case KC_Z:
                case MY_MEH:
                    return true;
            }

            break;
        case NV_SLSH:
            switch (other_keycode) {
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_L:
                case KC_SPC:
                case KC_BSPC:
                    return true;
            }

            break;
        case SY_A:
            switch (other_keycode) {
                // case KC_C:
                // case KC_X:
                // case KC_Z:
                case MY_MEH:
                    return true;
            }

            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

// How long to leave a key press till achordion ignores it and
// does a hold (default 1000ms)
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    // Bypass Achordion for these keys.
    // switch (tap_hold_keycode) {
    //   case HM_Z:
    //     return 0;
    // }

    return TAPPING_TERM * 2;
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // Disable achordion streak for some keys
    switch (tap_hold_keycode) {
        case HM_RSFT:
        case NU_F:
            return 0;
    }

    return 100;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    if (!process_achordion(keycode, record)) return false;
    if (!process_layer_lock(keycode, record, MY_LLCK)) return false;
    if (!process_smtd(keycode, record)) return false;

    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BA] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, SY_A   , KC_S   , KC_D   , NU_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , SY_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                TD(TD_1P), KC_LALT, MY_MEH ,     KC_SPC , KC_UNDS, TD(TD_WIN)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_GA] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_LALT, KC_SPC , TT(_NU),     KC_SPC , KC_ESC , TO(0)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_SY] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_GRV , KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_COLN,     KC_COLN, KC_LBRC, KC_LCBR, KC_LPRN, KC_SCLN, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, MY_EURO, KC_LABK, KC_RABK, KC_QUES, M_DASH ,     KC_TILD, KC_RPRN, KC_RBRC, KC_RCBR, KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, KC_SPC ,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_ESC , KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAD, RGB_TOG,     EE_CLR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MY_LLCK,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_MUTE, KC_VOLD, KC_VOLU, DM_REC1, DM_REC2,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, MY_CSTB, MY_CTAB, DM_PLY1, DM_PLY2,     KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, QK_BOOT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_CAPS, _______, _______,     _______, _______, XXXXXXX
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NU] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     KC_SLSH, KC_7   , KC_8   , KC_9   , KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_COMM, KC_1   , KC_2   , KC_3   , KC_DOT , KC_PERC,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, MY_LLCK,     KC_0   , KC_SPC , KC_TILD
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    // [_ME] = LAYOUT_split_3x6_3(
    // //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
    //    XXXXXXX, DM_REC1, DM_PLY1, XXXXXXX, XXXXXXX, QK_BOOT,     RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, XXXXXXX,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD,CK_TOGG, XXXXXXX,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    // //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
    //                               _______, _______, _______,     _______, _______, _______
    // //                          `+--------+--------+--------'   `--------+--------+--------+'
    // ),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

/// RGB
// clang-format off
#define BLACK { HSV_BLACK }
#define BLUE  { HSV_BLUE }
#define CYAN  { HSV_CYAN }
#define GREEN { HSV_GREEN }
#define MAGNT { HSV_MAGENTA }
#define ORANG { HSV_ORANGE }
#define RED   { HSV_RED }
#define WHITE { HSV_WHITE }
#define YELLW { HSV_YELLOW }

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BA] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        YELLW,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, CYAN ,
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

    [_SY] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        ORANG, ORANG, ORANG,  // BGT
        ORANG, ORANG, ORANG,  // RFV
        MAGNT, CYAN ,
        BLUE , ORANG, ORANG,  // CDE
        ORANG, ORANG, BLUE ,  // WSX
        BLUE , ORANG, ORANG,  // ZAQ
        BLUE , BLUE , BLUE ,  // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        ORANG, ORANG, ORANG, // NHY
        ORANG, ORANG, ORANG, // UJM
        CYAN , WHITE,
        ORANG, ORANG, ORANG, // ,KI
        ORANG, ORANG, ORANG, // OL.
        ORANG, ORANG, ORANG, // /;P
        BLUE , ORANG, BLUE , // DEL, ', SFT
    },

    [_NV] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        YELLW,
        GREEN, ORANG, RED  , // BGT
        RED  , ORANG, GREEN, // RFV
        MAGNT, WHITE,
        BLUE , WHITE, WHITE, // CDE
        WHITE, WHITE, BLUE , // WSX
        BLUE , WHITE, WHITE, // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        MAGNT,
        YELLW, GREEN, RED  , // NHY
        BLACK, GREEN, YELLW, // UJM
        CYAN , BLACK,
        YELLW, GREEN, BLACK, // ,KI
        BLACK, GREEN, YELLW, // OL.
        BLACK, BLACK, BLACK, // /;P
        WHITE, BLACK, RED  , // DEL, ', SFT
    },

    [_GA] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        GREEN,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        CYAN , MAGNT,
        CYAN , MAGNT, CYAN , // CDE
        MAGNT, MAGNT, CYAN , // WSX
        CYAN , MAGNT, CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        CYAN ,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        BLUE , WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [_NU] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        WHITE,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, CYAN ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        GREEN,
        CYAN , CYAN , CYAN , // NHY
        GREEN, GREEN, GREEN, // UJM
        CYAN , ORANG,
        GREEN, GREEN, GREEN, // ,KI
        GREEN, GREEN, GREEN, // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , CYAN , // DEL, ', SFT
    },

};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };

        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    // if (rawhid_state.rgb_control) return false;
    // if (keyboard_config.disable_layer_led) return false;

    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    // Caps indicator
    // uprintf("Caps Lock: %s\n", host_keyboard_led_state().caps_lock ? "on" : "off");
    // uprintf("Caps Word: %s\n", is_caps_word_on() ? "on" : "off");
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        rgb_matrix_set_color(26, RGB_WHITE);
    }

    return true;
}
