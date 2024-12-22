#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/socd_cleaner.h"
#include "iovis/config.h"

enum layers {
    LAYER_BASE = 0,
    LAYER_GAME,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_NUM,
};

enum custom_keycodes {
    MY_ARRW = SAFE_RANGE,
    MY_FARW,
    MY_MEMO,
    MY_COLN,
    MY_CODE,
    MY_NWLN,
    RGB_SLD,
};

/// Aliases
// clang-format off
#define MY_CSTB S(C(KC_TAB))
#define MY_CTAB C(KC_TAB)
#define MY_EURO S(RALT(KC_2))
#define MY_MEH  LCA(KC_LCMD)
#define M_DASH  S(RALT(KC_MINS))

#define HM_RSFT RSFT_T(KC_ENT)
#define HM_SPC  LGUI_T(KC_SPC)
#define HM_Z    LCTL_T(KC_Z)
#define NU_A    LT(LAYER_NUM, KC_A)
#define NV_SLSH LT(LAYER_NAV, KC_SLSH)
#define SY_F    LT(LAYER_SYM, KC_F)
#define SY_SCLN LT(LAYER_SYM, KC_SCLN)
#define TT_NUM  TT(LAYER_NUM)

#define MOON_LED_LEVEL LED_LEVEL
#define TG_LCLR TOGGLE_LAYER_COLOR
#define RGB_FWD RGB_MODE_FORWARD
// clang-format on

/// Achordion (https://getreuer.info/posts/keyboards/achordion)
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow same hand holds
    switch (tap_hold_keycode) {
        case HM_Z:
            return true;
        case NU_A:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_F:
            switch (other_keycode) {
                case KC_LGUI:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_SCLN:
            switch (other_keycode) {
                case KC_U:
                case KC_I:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_N:
                case KC_M:
                case KC_COMM:
                case KC_MINS:
                    return true;
            }
            break;
        case NV_SLSH:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case MY_MEH:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_L:
                case KC_QUOT:
                    return true;
            }
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

// How long to leave a key press till achordion ignores it and
// does a hold (default 1000ms)
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case HM_SPC:
            // Bypass Achordion for these keys and let QMK handle it
            return 0;
    }

    return TAPPING_TERM * 2;
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    switch (tap_hold_keycode) {
        case HM_RSFT:
        case NV_SLSH:
        case SY_SCLN:
            // Disable achordion streak
            return 0;
        case SY_F:
            return 40;
        case HM_Z:
            return 120;
    }

    return 100;
}

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_caps_word[] = {KC_DOT, NV_SLSH, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_caps_word, CW_TOGG),
    COMBO(combo_esc, KC_ESC),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Only trigger combos in the base layer
    return layer_state_is(LAYER_BASE);
}

/// Custom Shift Keys (https://getreuer.info/posts/keyboards/custom-shift-keys)
// clang-format off
const custom_shift_key_t custom_shift_keys[] = {
    // Symbols layer (allow fast rolling)
    {KC_EQL,  KC_EQL},
    {KC_MINS, KC_MINS},
    {KC_LBRC, KC_LBRC},
    {KC_RBRC, KC_RBRC},
    {KC_SCLN, KC_SCLN},
    {KC_SLSH, KC_SLSH},

    // Number layer
    {KC_0, KC_SPC},
    {KC_1, KC_UNDS},
    {KC_2, KC_COMM},
    {KC_3, KC_HASH},
    {KC_5, KC_LBRC},
    {KC_6, KC_RBRC},
    {KC_7, MY_EURO},
    {KC_8, KC_LPRN},
    {KC_9, KC_RPRN},
};
// clang-format on

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/// Key Overrides (https://docs.qmk.fm/features/key_overrides)
#ifdef KEY_OVERRIDE_ENABLE
const key_override_t equals_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);

const key_override_t *key_overrides[] = {
    &equals_key_override,
};
#endif

/// Leader (https://docs.qmk.fm/features/leader_key)
bool original_swap_lctl_lgui = false;

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_P)) { // 1Password popup
        tap_code16(G(S(KC_BSLS)));
    } else if (leader_sequence_one_key(KC_J)) { // Screenshots
        tap_code16(G(S(KC_4)));
    } else if (leader_sequence_one_key(KC_DOT)) {
        tap_code16(G(S(KC_3)));
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(G(S(KC_5)));
    } else if (leader_sequence_one_key(KC_G)) { // Layers
        original_swap_lctl_lgui = keymap_config.swap_lctl_lgui;
        layer_move(LAYER_GAME);
        keymap_config.swap_lctl_lgui = false;
    } else if (leader_sequence_one_key(KC_F)) {
        layer_move(LAYER_BASE);
        keymap_config.swap_lctl_lgui = original_swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_W)) { // Keyboard settings
        // Toggle lctl and lgui swap
        keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_ENT)) { // QK_BOOT
        reset_keyboard();
    }
}

/// OS Detection
uint32_t custom_os_settings(uint32_t trigger_name, void *cb_arg) {
    os_variant_t host = detected_host_os();
    uint16_t retry_ms = 500;

    if (host == OS_WINDOWS) {
        keymap_config.swap_lctl_lgui = true;
        retry_ms = 0;
    }

    return retry_ms;
}

/// SOCD Cleaner (https://getreuer.info/posts/keyboards/socd-cleaner)
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

layer_state_t layer_state_set_user(layer_state_t state) {
    socd_cleaner_enabled = IS_LAYER_ON_STATE(state, LAYER_GAME);
    return state;
}

/// RGB Matrix (https://docs.qmk.fm/features/rgb_matrix)
#ifdef RGB_MATRIX_ENABLE
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];
extern rgb_config_t rgb_matrix_config;
extern const int left_shift_index;

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
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
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
        rgb_matrix_set_color(left_shift_index, RGB_WHITE);
    }

    // Leader indicator
    // if (leader_sequence_active()) {
    //     rgb_matrix_set_color(40, RGB_GREEN);
    // }

    return true;
}
#endif

/// User macro callbacks (https://docs.qmk.fm/feature_macros)
void keyboard_post_init_user(void) {
    defer_exec(100, custom_os_settings, NULL);
    rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    if (!process_socd_cleaner(keycode, record, &socd_h)) return false;
    if (!process_achordion(keycode, record)) return false;

    if (layer_state_is(LAYER_SYM) || layer_state_is(LAYER_NUM)) {
        if (!process_custom_shift_keys(keycode, record)) return false;
    }

    switch (keycode) {
        case MY_ARRW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case MY_FARW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case MY_MEMO:
            if (record->event.pressed) {
                SEND_STRING("||=");
            }
            break;
        case MY_COLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            break;
        case MY_CODE:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case MY_NWLN:
            if (record->event.pressed) {
                SEND_STRING("\\n");
            }
            break;
#ifdef RGB_MATRIX_ENABLE
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }

            return false;
#endif
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_Z:
            return 125;
        case NU_A:
            return 250;
        default:
            return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
    achordion_task();
}
