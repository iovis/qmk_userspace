#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _SY, // Symbols
    _NV, // Navigation
    _NU, // Number Pad
    _GA, // Gaming
    // _ME, // Media
};

/// Combos
// const uint16_t PROGMEM combo_enter[] = {KC_L, KC_SCLN, COMBO_END};
// const uint16_t PROGMEM combo_esc[]   = {KC_Q, KC_W, COMBO_END};
//
// combo_t key_combos[] = {
//     COMBO(combo_enter, KC_ENT),
//     COMBO(combo_esc, KC_ESC),
// };

/// Macros
enum custom_keycodes {
    MY_THIN = SAFE_RANGE,
    MY_FATA,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_THIN:
            if (record->event.pressed) SEND_STRING("->");
            break;
        case MY_FATA:
            if (record->event.pressed) SEND_STRING("=>");
            break;
    }

    return true;
}

/// Complex key definitions
#define MY_MEH LCA(KC_LCMD)
#define MY_EURO S(RALT(KC_2))
#define M_DASH S(LALT(KC_MINS))

// Layer taps
#define NU_V LT(_NU, KC_V)
#define NV_SLSH LT(_NV, KC_SLSH)
// #define SYM_SPC LT(_SY, KC_SPC)

// Next/Previous
#define MY_CTAB C(KC_TAB)
#define MY_CSTB S(C(KC_TAB))

// Home Row Mods
// #define HM_A LCTL_T(KC_A)
// #define HM_S LALT_T(KC_S)
// #define HM_D LCMD_T(KC_D)
// #define HM_D LALT_T(KC_D)
// #define HM_F LSFT_T(KC_F)

// #define HM_QUOT RCAG_T(KC_QUOT)
#define HM_Z LCTL_T(KC_Z)
#define HM_LGUI LGUI_T(KC_ESC)

#define HM_RSFT RSFT_T(KC_ENT)
// #define HM_M RSFT_T(KC_M)
// #define HM_COMM RCMD_T(KC_COMM)
// #define HM_DOT LALT_T(KC_DOT)
// #define HM_SLSH RCTL_T(KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, HM_Z   , KC_X   , KC_C   , NU_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_LALT, MO(_SY), MY_MEH ,     KC_ESC , KC_SPC , TT(_GA)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_SY] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_DLR , KC_LCBR, KC_RCBR, KC_HASH, XXXXXXX,     KC_CIRC, KC_AMPR, KC_LBRC, KC_RBRC, KC_PIPE, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_PERC,     KC_GRV , KC_ASTR, KC_LPRN, KC_RPRN, KC_COLN, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_AT  , XXXXXXX, CW_TOGG, XXXXXXX,     M_DASH , KC_TILD, KC_LABK, KC_RABK, KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, KC_UNDS, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LGUI, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,     KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, MY_CSTB,     MY_CTAB, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NU] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, MY_EURO, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_DLR , KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,     KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, _______, XXXXXXX,     KC_HASH, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_TILD, KC_SPC , MY_MEH ,     KC_UNDS, KC_0   , KC_PERC
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_GA] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  KC_LALT, KC_SPC , KC_ESC ,     KC_ESC , KC_SPC , _______
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
