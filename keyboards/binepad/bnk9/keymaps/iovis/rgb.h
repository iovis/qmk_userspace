// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "iovis/rgb.h"

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        WHITE, WHITE, WHITE,
        WHITE, WHITE, WHITE,
        WHITE, WHITE, WHITE,
    },

    [LAYER_MOUSE] = {
        BLUE, BLUE, BLUE,
        BLUE, BLUE, BLUE,
        BLUE, BLUE, BLUE,
    },

    [LAYER_MPV] = {
        MAGNT, MAGNT, MAGNT,
        MAGNT, MAGNT, MAGNT,
        MAGNT, MAGNT, MAGNT,
    },

    [LAYER_NUM] = {
        CYAN, CYAN, CYAN,
        CYAN, CYAN, CYAN,
        CYAN, CYAN, CYAN,
    },

    [LAYER_CALL] = {
        ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG,
    },
};
// clang-format on
