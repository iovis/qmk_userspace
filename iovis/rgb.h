#pragma once

#include QMK_KEYBOARD_H

#include "iovis/layers.h"

/// RGB Matrix (https://docs.qmk.fm/features/rgb_matrix)
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
        case LAYER_BASE:
            set_layer_color(LAYER_BASE);
            break;
        case LAYER_GAME:
            set_layer_color(LAYER_GAME);
            break;
        case LAYER_SYM:
            set_layer_color(LAYER_SYM);
            break;
        case LAYER_NAV:
            set_layer_color(LAYER_NAV);
            break;
        case LAYER_NUM:
            set_layer_color(LAYER_NUM);
            break;
        case LAYER_NUMSYM:
            set_layer_color(LAYER_NUMSYM);
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
