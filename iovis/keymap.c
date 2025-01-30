#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"
#include "features/socd_cleaner.h"
#include "iovis/config.h"
#include "iovis/layers.h"

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

#define HM_NSPC RSFT_T(KC_SPC)
#define HM_RSFT RSFT_T(KC_ENT)
#define HM_SPC  LGUI_T(KC_SPC)
#define HM_Z    LCTL_T(KC_Z)
#define NS_TAB  LT(LAYER_NUMSYM, KC_TAB)
#define NU_A    LT(LAYER_NUM, KC_A)
#define NV_SLSH LT(LAYER_NAV, KC_SLSH)
#define SY_F    LT(LAYER_SYM, KC_F)
#define SY_SCLN LT(LAYER_SYM, KC_SCLN)
#define TT_NUM  TT(LAYER_NUM)

#define MOON_LED_LEVEL LED_LEVEL
#define TG_LCLR TOGGLE_LAYER_COLOR
#define RGB_FWD RGB_MODE_FORWARD
// clang-format on

/// Chordal Hold
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow same hand holds
    switch (tap_hold_keycode) {
        case HM_NSPC:
        case HM_Z:
            return true;
        case NU_A:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case KC_SPC:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_F:
            switch (other_keycode) {
                case KC_LALT:
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

    return get_chordal_hold_default(tap_hold_record, other_record);
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
    {KC_0, KC_UNDS},
    {KC_1, KC_0   },
    {KC_2, KC_COMM},
    {KC_3, KC_DOT },
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
    } else if (leader_sequence_one_key(KC_DOT)) { // Screenshots
        tap_code16(G(S(KC_3)));
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(G(S(KC_4)));
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
        keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_S)) {
        socd_cleaner_enabled = !socd_cleaner_enabled;
    } else if (leader_sequence_one_key(KC_ENT)) { // QK_BOOT
        reset_keyboard();
    }
}

/// OS Detection
uint32_t custom_os_settings(uint32_t trigger_name, void *cb_arg) {
    switch (detected_host_os()) {
        case OS_WINDOWS:
        case OS_LINUX:
            // Swap LCTRL and LGUI
            keymap_config.swap_lctl_lgui = true;
            return 0;
        case OS_MACOS:
        case OS_IOS:
            return 0;
        default:
            return 500;
    }
}

/// SOCD Cleaner (https://getreuer.info/posts/keyboards/socd-cleaner)
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

layer_state_t layer_state_set_user(layer_state_t state) {
    socd_cleaner_enabled = IS_LAYER_ON_STATE(state, LAYER_GAME);
    return state;
}

/// User macro callbacks (https://docs.qmk.fm/feature_macros)
void keyboard_post_init_user(void) {
    defer_exec(100, custom_os_settings, NULL);

#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    if (!process_socd_cleaner(keycode, record, &socd_h)) return false;

    if (layer_state_is(LAYER_SYM) || layer_state_is(LAYER_NUM) || layer_state_is(LAYER_NUMSYM)) {
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
        case HM_NSPC:
        case HM_Z:
            return 125;
        case SY_F:
        case SY_SCLN:
        case NV_SLSH:
            return 140;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_NSPC:
        case HM_Z:
        case SY_F:
            return true;
        default:
            return false;
    }
}
