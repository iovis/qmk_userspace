#include QMK_KEYBOARD_H

#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layer_number {
    _BA = 0, // Base
    _SY,     // Symbols
    _NV,     // Navigation
    _GA,     // Gaming
    _NU,     // Number Pad
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    SMTD_KEYCODES_BEGIN,
    HM_RSFT,
    HM_Z,
    NV_SLSH,
    SMTD_KEYCODES_END,
};

// There's a bug in v0.4 that requires to put it here
#include "features/sm_td.h"
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(HM_RSFT, KC_ENT, KC_RSFT)
        SMTD_MT(HM_Z, KC_Z, KC_LCTL)

        SMTD_LT(NV_SLSH, KC_SLSH, _NV)
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    // Reduce the SMTD timeouts for easier rolling (TAPPING_TERM / 2 by default)
    // if (timeout == SMTD_TIMEOUT_RELEASE) {
    //     if (keycode == SY_M) return 5;
    //     if (keycode == SY_V) return 5;
    // }

    return get_smtd_timeout_default(timeout);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) return false;

    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }

            return false;
    }

    return true;
}

/// Complex key definitions
#define MY_CSTB S(C(KC_TAB))
#define MY_CTAB C(KC_TAB)
#define MY_EURO S(RALT(KC_2))
#define MY_MEH LCA(KC_LCMD)
#define M_DASH S(RALT(KC_MINS))

#define NU_F LT(_NU, KC_F)
#define SY_M LT(_SY, KC_M)
#define SY_V LT(_SY, KC_V)

#define TG_LCLR TOGGLE_LAYER_COLOR
#define RGB_FWD RGB_MODE_FORWARD

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BA] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , TO(_GA),
    KC_LGUI, KC_A   , KC_S   , KC_D   , NU_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, HM_Z   , KC_X   , KC_C   , SY_V   , KC_B   ,                       KC_N   , SY_M   , KC_COMM, KC_DOT , NV_SLSH, HM_RSFT,
                                                 KC_LALT, MY_MEH ,     KC_UNDS, KC_SPC
  ),

  [_SY] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_BSPC,
    _______, XXXXXXX, KC_LABK, KC_RABK, KC_DLR , KC_AT  ,                       KC_CIRC, KC_AMPR, KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_PERC,                       KC_GRV , KC_ASTR, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO,
    _______, KC_LCTL, MY_CSTB, MY_CTAB, M_DASH , MY_EURO,                       KC_TILD, KC_HASH, KC_LCBR, KC_RCBR, KC_SLSH, KC_ENT ,
                                                 _______, KC_SPC ,     _______, _______
  ),

  [_NV] = LAYOUT_voyager(
    _______, TG_LCLR, RGB_FWD, RGB_SLD, XXXXXXX, RGB_TOG,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, RGB_VAI,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, RGB_VAD,                       KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, QK_BOOT,
                                                 _______, _______,     QK_LLCK, CW_TOGG // layer lock seems to not work with sm_td
  ),

  [_GA] = LAYOUT_voyager(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , TO(_BA),
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_ENT ,
                                                 KC_SPC , KC_LALT,     KC_LGUI, KC_SPC
  ),

  [_NU] = LAYOUT_voyager(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    _______, _______, _______, _______, _______, _______,                       KC_ASTR, KC_7   , KC_8   , KC_9   , KC_PLUS, KC_SLSH,
    _______, _______, _______, _______, _______, _______,                       KC_COLN, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
    _______, _______, _______, _______, _______, _______,                       KC_COMM, KC_1   , KC_2   , KC_3   , KC_DOT , KC_PERC,
                                                 _______, QK_LLCK,     KC_SPC , KC_0
  ),
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

    [_SY] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , BLACK, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , BLUE , BLUE , BLUE , ORANG, ORANG,
                                    MAGNT, CYAN ,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, BLUE ,
        MAGNT, CYAN ,
    },

    [_NV] = {
        // Left
        BLUE , RED  , RED  , RED  , BLACK, RED  ,
        BLUE , WHITE, WHITE, WHITE, BLACK, BLACK,
        BLUE , WHITE, WHITE, WHITE, BLACK, RED  ,
        BLUE , BLUE , BLUE , BLUE , BLACK, RED  ,
                                    MAGNT, YELLW,

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLUE ,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        GREEN, GREEN, GREEN, GREEN, BLACK, BLACK,
        YELLW, YELLW, YELLW, YELLW, YELLW, RED  ,
        ORANG, MAGNT,
    },

    [_GA] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , MAGNT, CYAN , CYAN , CYAN ,
        BLUE , MAGNT, MAGNT, MAGNT, CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
                                    CYAN , MAGNT,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , WHITE,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BLUE , CYAN ,
    },

    [_NU] = {
        // Left
        BLUE , MAGNT, MAGNT, MAGNT, MAGNT, MAGNT,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
                                    ORANG, YELLW,

        // Right
        MAGNT, MAGNT, MAGNT, MAGNT, MAGNT, BLUE ,
        CYAN , GREEN, GREEN, GREEN, CYAN , CYAN ,
        CYAN , GREEN, GREEN, GREEN, CYAN , CYAN ,
        CYAN , GREEN, GREEN, GREEN, CYAN , CYAN ,
        CYAN , GREEN,
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
    if (rawhid_state.rgb_control) return false;
    if (keyboard_config.disable_layer_led) return false;

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

    return true;
}
