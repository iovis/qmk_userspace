// The MIT License (MIT)
//
// Copyright (c) 2025 David Marchante
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "iovis/rgb.h"

const int left_shift_index = 18;

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
        BLACK, CYAN ,
    },

    [LAYER_NAV] = {
        // Left
        BLUE , MAGNT, MAGNT, MAGNT, MAGNT, MAGNT,
        BLUE , WHITE, WHITE, WHITE, RED  , RED  ,
        BLUE , WHITE, WHITE, WHITE, ORANG, ORANG,
        BLUE , BLUE , BLUE , BLUE , GREEN, GREEN,
        MAGNT, YELLW,

        // Right
        MAGNT, MAGNT, MAGNT, MAGNT, MAGNT, BLUE ,
        RED  , MAGNT, BLACK, BLACK, BLACK, BLACK,
        GREEN, GREEN, GREEN, GREEN, BLACK, WHITE,
        YELLW, YELLW, YELLW, YELLW, YELLW, RED  ,
        BLUE , CYAN ,
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

    [LAYER_NUMSYM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, GREEN,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, CYAN , ORANG, ORANG, ORANG, CYAN ,
        ORANG, CYAN , ORANG, ORANG, ORANG, ORANG,
        GREEN, GREEN, ORANG, ORANG, ORANG, BLUE ,
        CYAN , CYAN ,
    },
};
// clang-format on
