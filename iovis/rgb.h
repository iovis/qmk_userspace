#pragma once

#include QMK_KEYBOARD_H

#include "iovis/layers.h"

/// RGB Matrix (https://docs.qmk.fm/features/rgb_matrix)
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];
extern rgb_config_t rgb_matrix_config;
extern const int left_shift_index;

// clang-format off
#define BLACK { HSV_BLACK }
#define BHITE { 128, 60, 255 } // Bluer white if white ends up being pink
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
    set_layer_color(biton32(layer_state));

    // Caps indicator
    // uprintf("Caps Lock: %s\n", host_keyboard_led_state().caps_lock ? "on" : "off");
    // uprintf("Caps Word: %s\n", is_caps_word_on() ? "on" : "off");
#ifdef CAPS_WORD_ENABLE
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        rgb_matrix_set_color(left_shift_index, RGB_WHITE);
    }
#endif

    // Leader indicator
    // if (leader_sequence_active()) {
    //     rgb_matrix_set_color(40, RGB_GREEN);
    // }

    return true;
}
