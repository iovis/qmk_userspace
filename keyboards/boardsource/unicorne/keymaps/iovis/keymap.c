#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
};

// #define KC_G_TAB LGUI_T(KC_TAB)
// #define KC_G_BS LGUI_T(KC_BSPC)
// #define KC_L_SPC LT(_LOWER, KC_SPC)
// #define KC_R_ENT LT(_RAISE, KC_ENT)
// #define KC_S_JA LSFT_T(KC_LNG1)
// #define KC_S_EN LSFT_T(KC_LNG2)
// #define KC_A_DEL ALT_T(KC_DEL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
       KC_TAB , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_BSPC,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LCTL, KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT ,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
    //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                                   KC_LALT, MO(1)   , KC_ENT ,     KC_SPC,  MO(2)   , KC_RGUI
    //                           `+--------+---------+--------'   `--------+---------+--------+'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,     KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LPRN, KC_HASH, KC_DLR , KC_DQT , KC_QUOT, KC_TILD,     KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_GRV , KC_RPRN,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, KC_LCBR, KC_LBRC,     KC_RBRC, KC_RCBR, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, QK_BOOT
    //                          `+--------+--------+--------'   `--------+---------+--------+'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       QK_BOOT, KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       EE_CLR , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD,CK_TOGG, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),
};
// clang-format on
