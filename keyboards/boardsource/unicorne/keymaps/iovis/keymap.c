#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _SY, // Symbols
    _NV, // Navigation
    _NU, // Number Row
    _NP, // Number Pad
    _ME, // Media
    _GA, // Gaming
};

/// Combos
const uint16_t PROGMEM combo_esc[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_enter, KC_ENT),
};

/// Macros
enum custom_keycodes {
    MY_THIN = SAFE_RANGE,
    MY_FATA,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_THIN:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case MY_FATA:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
    }

    return true;
}

/// Complex key definitions
#define MY_MEH LCA(KC_LCMD)
#define SP_SYM LT(_SY, KC_SPC)
#define HM_ENT LT(_NU, KC_ENT)

#define MY_EURO S(A(KC_2))

// Next/Previous
#define MY_CTAB C(KC_TAB)
#define MY_CSTB S(C(KC_TAB))

// Home Row Mods
#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCMD_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_M RSFT_T(KC_M)
#define HM_COMM RCMD_T(KC_COMM)
#define HM_DOT LALT_T(KC_DOT)
#define HM_SLSH RCTL_T(KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, HM_A   , HM_S   , HM_D   , HM_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , HM_M   , HM_COMM, HM_DOT , HM_SLSH, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  TT(_NP), MO(_SY), HM_ENT ,     TT(_NV), SP_SYM , MO(_ME)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_SY] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_1   , KC_LABK, KC_RABK, KC_BSLS, KC_AT  ,     KC_AMPR, KC_GRV , KC_LBRC, KC_RBRC, KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,     KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_COLN, KC_PERC, KC_ASTR, KC_CIRC, MY_THIN,     KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NV] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, XXXXXXX, MY_CSTB, MY_CTAB, XXXXXXX, XXXXXXX,     XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NU] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_NP] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_DLR , MY_EURO, XXXXXXX, XXXXXXX, XXXXXXX,     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_PERC, XXXXXXX,     KC_DOT , KC_4   , KC_5   , KC_6   , KC_MINS, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_COMM, KC_1   , KC_2   , KC_3   , KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,     KC_0   , _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    [_ME] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT,     RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, EE_CLR ,     RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD,CK_TOGG, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  TT(_GA), _______, _______,     _______, _______, _______
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),

    // TODO: I can't seem to access the other layers when this is active?
    [_GA] = LAYOUT_split_3x6_3(
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                                  TT(3)  , KC_SPC , MY_MEH ,     TT(_NV), KC_SPC , MO(4)
    //                          `+--------+--------+--------'   `--------+--------+--------+'
    ),
};
// clang-format on
