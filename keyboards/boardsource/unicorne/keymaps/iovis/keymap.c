#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _NUMPAD,
    _MEDIA,
};

/// Combos
const uint16_t PROGMEM combo_esc[]   = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_SCLN, KC_QUOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_enter, KC_ENT),
};

/// Complex key definitions
#define MY_MEH LCA(KC_LCMD)

// Home Row Mods
#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCMD_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_COMM RCMD_T(KC_COMM)
#define HM_DOT LALT_T(KC_DOT)
#define HM_SLSH RCTL_T(KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
       KC_TAB , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_BSPC,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LCTL, HM_A   , HM_S    , HM_D   , HM_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , HM_COMM, HM_DOT  , HM_SLSH, KC_RSFT,
    //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                                   TT(3)  , MO(1)   , MY_MEH ,     MO(2)  , KC_SPC  , MO(4)
    //                           `+--------+---------+--------'   `--------+---------+--------+'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_NUBS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_PIPE, KC_UNDS, KC_MINS, KC_PLUS, KC_TILD,     KC_GRV , KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, KC_BSLS, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+---------+--------+'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_NUBS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NUMPAD] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,     KC_TILD, KC_7   , KC_8   , KC_9   , KC_ASTR, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,     KC_PLUS, KC_4   , KC_5   , KC_6   , KC_EQL , KC_ENT ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     KC_MINS, KC_1   , KC_2   , KC_3   , KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, KC_0
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, QK_BOOT,     _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,     _______, KC_F4  , KC_F5  , KC_F6  , _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     _______, KC_F1  , KC_F2  , KC_F3  , _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    // [_RAISE] = LAYOUT_split_3x6_3(
    // //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
    //    QK_BOOT, KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, _______,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    EE_CLR , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD,CK_TOGG, _______,
    // //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
    //    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     _______, _______, _______, _______, _______, _______,
    // //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
    //                               _______, _______, _______,     _______, _______, _______
    // //                          `+--------+--------+--------'   `--------+--------+--------+'
    // ),
};
// clang-format on
