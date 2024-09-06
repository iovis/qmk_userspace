#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _SY, // Symbols
    _NV, // Navigation
    _NU, // Number Pad
    // _GA, // Gaming
    // _ME, // Media
};

/// Combos
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
};

/// Macros
enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    HM_RSFT,
    HM_Z,
    NU_G,
    NV_SLSH,
    SY_M,
    SY_V,
    SMTD_KEYCODES_END,
};

// There's a bug in v0.4 that requires to put it here
#include "sm_td.h"
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(HM_RSFT, KC_ENT, KC_RSFT)
        SMTD_MT(HM_Z, KC_Z, KC_LCTL)

        SMTD_LT(NU_G, KC_G, _NU)
        SMTD_LT(NV_SLSH, KC_SLSH, _NV)
        SMTD_LT(SY_M, KC_M, _SY)
        SMTD_LT(SY_V, KC_V, _SY)
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    return true;
}

/// Complex key definitions
#define MY_MEH LCA(KC_LCMD)
#define MY_EURO S(RALT(KC_2))
#define M_DASH S(LALT(KC_MINS))

// Next/Previous
#define MY_CTAB C(KC_TAB)
#define MY_CSTB S(C(KC_TAB))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , NU_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , SY_V   , KC_B   ,     KC_N   , SY_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  TT(_NU), KC_LALT, MY_MEH ,     CW_TOGG, KC_SPC , TT(_NV)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_SY] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_DLR , KC_LCBR, KC_RCBR, KC_HASH, KC_AT  ,     KC_CIRC, KC_AMPR, KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_PERC,     KC_GRV , KC_ASTR, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, MY_CSTB, MY_CTAB, M_DASH , XXXXXXX,     KC_TILD, KC_UNDS, KC_LABK, KC_RABK, KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, KC_SPC ,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,     KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, QK_BOOT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NU] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_DLR ,     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PERC,     KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, KC_UNDS, KC_TILD,     KC_HASH, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, KC_SPC , MY_MEH ,     KC_COMM, KC_0   , KC_DOT
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    // [_GA] = LAYOUT_split_3x6_3(
    // //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
    //    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    // //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
    //                               KC_LALT, KC_SPC , KC_ESC ,     KC_ESC , KC_SPC , _______
    // //                          `+--------+--------+--------'   `--------+--------+--------+'
    // ),

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
