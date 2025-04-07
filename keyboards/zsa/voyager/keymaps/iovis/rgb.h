// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "iovis/rgb.h"

const int left_shift_index = 18;

// TODO: for WHITE use a bit more blue

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, YELLW,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , ORANG,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        WHITE, CYAN ,
    },

    [LAYER_LINUX] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, BLUE ,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , ORANG,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        WHITE, CYAN ,
    },

    [LAYER_GAME] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        CYAN , BLUE , CYAN , MAGNT, CYAN , CYAN ,
        CYAN , BLUE , MAGNT, MAGNT, MAGNT, CYAN ,
        CYAN , BLUE , CYAN , CYAN , CYAN , CYAN ,
        CYAN , MAGNT,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , GREEN,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        WHITE, CYAN ,
    },

    [LAYER_SYM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        MAGNT, GREEN,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, BLUE ,
        ORANG, CYAN ,
    },

    [LAYER_NAV] = {
        // Left
        BLUE , MAGNT, MAGNT, MAGNT, MAGNT, MAGNT,
        BLUE , WHITE, WHITE, WHITE, RED  , RED  ,
        BLUE , WHITE, WHITE, WHITE, CYAN , BLACK,
        BLUE , BLUE , BLUE , BLUE , WHITE, BLACK,
        MAGNT, YELLW,

        // Right
        MAGNT, MAGNT, MAGNT, MAGNT, MAGNT, BLUE ,
        BLACK, BLACK, YELLW, BLACK, BLACK, BLACK,
        GREEN, GREEN, GREEN, GREEN, BLACK, BLACK,
        YELLW, YELLW, YELLW, YELLW, WHITE, BLUE ,
        BLUE , WHITE,
    },

    [LAYER_NUM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, GREEN,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, GREEN, GREEN, GREEN, ORANG, WHITE,
        ORANG, GREEN, GREEN, GREEN, ORANG, ORANG,
        ORANG, GREEN, GREEN, GREEN, ORANG, ORANG,
        CYAN , CYAN ,
    },

    [LAYER_NUMFN] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, YELLW,

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        RED  , MAGNT, MAGNT, MAGNT, MAGNT, BLACK,
        RED  , MAGNT, MAGNT, MAGNT, MAGNT, BLACK,
        BLACK, MAGNT, MAGNT, MAGNT, MAGNT, BLACK,
        BLACK, BLACK,
    },

    [LAYER_MOUSE] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, YELLW,

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        ORANG, ORANG, GREEN, ORANG, ORANG, BLACK,
        MAGNT, GREEN, GREEN, GREEN, MAGNT, BLACK,
        WHITE, MAGNT,
        BLACK, MAGNT, MAGNT, MAGNT, BLACK, WHITE,
    },
};
// clang-format on
