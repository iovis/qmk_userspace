#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "iovis/config.h"
#include "iovis/layers.h"

enum custom_keycodes {
    MY_CODE = SAFE_RANGE,
    MY_COLN,
};

/// Aliases
// clang-format off
#define MY_CSTB S(C(KC_TAB))
#define MY_CTAB C(KC_TAB)
#define MY_MEH  LCAG_T(KC_SPC)

#define FN_ESC  LT(LAYER_NUMFN, KC_ESC)
#define FN_QUOT LT(LAYER_NUMFN, KC_QUOT)
#define HM_RSFT RSFT_T(KC_ENT)
#define HM_UNDS RCTL_T(KC_UNDS)
#define HM_Z    LCTL_T(KC_Z)
#define MO_NUMG MO(LAYER_NUMGM)
#define NG_A    LT(LAYER_NUMGM, KC_A)
#define NG_ESC  LT(LAYER_NUMGI, KC_ESC)
#define NU_D    LT(LAYER_NUM, KC_D)
#define NV_SLSH LT(LAYER_NAV, KC_SLSH)
#define SY_F    LT(LAYER_SYM, KC_F)
#define SY_SCLN LT(LAYER_SYM, KC_SCLN)
#define TG_MOUS TG(LAYER_MOUSE)
// clang-format on

/// Chordal Hold
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow same hand holds
    switch (tap_hold_keycode) {
        case FN_QUOT:
        case NG_ESC:
            return true;
        case HM_RSFT:
            switch (other_keycode) {
                case NV_SLSH:
                    return true;
            }
            break;
        case HM_Z:
            switch (other_keycode) {
                case KC_Y:
                    return false;
            }
            break;
        case NG_A:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case MY_MEH:
                    return true;
                case KC_Y:
                case KC_P:
                case KC_H:
                case KC_L:
                case SY_SCLN:
                case KC_N:
                case NV_SLSH:
                    return false;
            }
            break;
        case NU_D:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LSFT:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_F:
            switch (other_keycode) {
                case KC_E: // allow for chords in different hands, like =>
                case KC_W: // allow for chords in different hands, like ::<
                case KC_BSPC:
                case KC_LALT:
                case KC_LGUI:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_SCLN:
            switch (other_keycode) {
                case KC_Y:
                case KC_U:
                case KC_I:
                case KC_O:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_N:
                case KC_COMM:
                    return true;
            }
            break;
        case NV_SLSH:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case HM_RSFT:
                case MY_MEH:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_L:
                    return true;
            }
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}

/// Combos (https://docs.qmk.fm/features/combo)
const uint16_t PROGMEM combo_caps_word[] = {KC_DOT, NV_SLSH, COMBO_END};
const uint16_t PROGMEM combo_mouse[] = {NV_SLSH, HM_RSFT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_caps_word, CW_TOGG),
    COMBO(combo_mouse, TG(LAYER_MOUSE)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Only trigger combos in the base layers
    return layer_state_is(LAYER_BASE) || layer_state_is(LAYER_LINUX);
}

/// Custom Shift Keys (https://getreuer.info/posts/keyboards/custom-shift-keys)
// clang-format off
#include "custom_shift_keys.h"
const custom_shift_key_t custom_shift_keys[] = {
    // Symbols layer (allow fast rolling)
    {KC_EQL,  KC_EQL},
    // {KC_MINS, KC_MINS},
    {KC_LBRC, KC_LBRC},
    {KC_RBRC, KC_RBRC},
    {KC_SCLN, KC_SCLN},
    {KC_SLSH, KC_SLSH},
};
// clang-format on

/// Leader (https://docs.qmk.fm/features/leader_key)
bool original_swap_lctl_lgui = false;
uint8_t current_base_layer = LAYER_BASE;

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_P)) { // 1Password popup
        tap_code16(G(S(KC_BSLS)));
    } else if (leader_sequence_one_key(KC_DOT)) { // Screenshots
        tap_code16(G(S(KC_3)));
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(G(S(KC_4)));
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(G(S(KC_5)));
    } else if (leader_sequence_one_key(KC_D)) { // Layers
        original_swap_lctl_lgui = keymap_config.swap_lctl_lgui;
        layer_move(LAYER_GAME);
        keymap_config.swap_lctl_lgui = false;
    } else if (leader_sequence_one_key(KC_F)) {
        layer_move(current_base_layer);
        keymap_config.swap_lctl_lgui = original_swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_B)) {
        layer_move(current_base_layer);
        keymap_config.swap_lctl_lgui = original_swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_Z)) { // Keyboard settings
        keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
    } else if (leader_sequence_one_key(KC_QUOT)) { // QK_BOOT
        reset_keyboard();
    }
}

/// OS Detection (https://docs.qmk.fm/features/os_detection#os-detection)
#ifdef OS_DETECTION_ENABLE
uint32_t custom_os_settings(uint32_t trigger_name, void *cb_arg) {
    switch (detected_host_os()) {
        case OS_WINDOWS:
        case OS_LINUX:
            current_base_layer = LAYER_LINUX;
            layer_move(LAYER_LINUX);
            return 0;
        case OS_MACOS:
        case OS_IOS:
            return 0;
        default:
            return 200;
    }
}
#endif

/// User macro callbacks (https://docs.qmk.fm/feature_macros)
void keyboard_post_init_user(void) {
#ifdef OS_DETECTION_ENABLE
    defer_exec(100, custom_os_settings, NULL);
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    switch (keycode) {
        case HM_UNDS:
            if (record->tap.count && record->event.pressed) {
                // Can't have complicated keys on Mod Tap
                // See [[Mod Tap#Caveats]] section
                tap_code16(KC_UNDS); // Send KC_UNDS on tap
                return false;
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
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_MEH:
        case NG_ESC:
            return 75;
        case HM_Z:
            return 130;
        case NV_SLSH:
        case SY_SCLN:
            return 140;
        case HM_RSFT:
        case NU_D:
        case SY_F:
            return 175;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_ESC:
        case FN_QUOT:
        case HM_RSFT:
        case MY_MEH:
        case NG_A:
        case NG_ESC:
        case SY_SCLN:
            return true;
        case HM_UNDS:
            tap_code16(KC_UNDS);
            return false;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SY_F:
            // Allow to register holds when double tapping
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
