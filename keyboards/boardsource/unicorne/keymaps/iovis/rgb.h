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

const int left_shift_index = 26;

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        CYAN , WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [LAYER_LINUX] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, RED  ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        CYAN , WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [LAYER_GAME] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , MAGNT, CYAN , // RFV
        MAGNT, CYAN ,
        CYAN , MAGNT, MAGNT, // CDE
        CYAN , MAGNT, CYAN , // WSX
        BLUE , BLUE , BLUE , // ZAQ
        RED  , CYAN , CYAN , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // NHY
        CYAN , CYAN , CYAN , // UJM
        GREEN, WHITE,
        CYAN , CYAN , CYAN , // ,KI
        CYAN , CYAN , CYAN , // OL.
        CYAN , CYAN , CYAN , // /;P
        BLUE , CYAN , BLUE , // DEL, ', SFT
    },

    [LAYER_SYM] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        ORANG, ORANG, ORANG,  // BGT
        ORANG, ORANG, ORANG,  // RFV
        MAGNT, BLUE ,
        ORANG, ORANG, ORANG,  // CDE
        ORANG, ORANG, ORANG,  // WSX
        ORANG, ORANG, ORANG,  // ZAQ
        RED  , BLUE , BLUE ,  // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        ORANG, ORANG, ORANG, // NHY
        ORANG, ORANG, ORANG, // UJM
        CYAN , ORANG,
        ORANG, ORANG, ORANG, // ,KI
        ORANG, ORANG, ORANG, // OL.
        ORANG, ORANG, ORANG, // /;P
        ORANG, ORANG, BLUE , // DEL, ', SFT
    },

    [LAYER_NAV] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        BLACK, BLACK, RED  , // BGT
        RED  , CYAN , WHITE, // RFV
        MAGNT, BLUE ,
        BLUE , WHITE, WHITE, // CDE
        WHITE, WHITE, BLUE , // WSX
        BLUE , WHITE, WHITE, // ZAQ
        RED  , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        YELLW, GREEN, BLACK, // NHY
        BLACK, GREEN, YELLW, // UJM
        BLUE , WHITE,
        YELLW, GREEN, BLACK, // ,KI
        BLACK, GREEN, YELLW, // OL.
        WHITE, BLACK, BLACK, // /;P
        BLACK, BLACK, BLUE , // DEL, ', SFT
    },

    [LAYER_NUM] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        ORANG, ORANG, ORANG, // NHY
        GREEN, GREEN, GREEN, // UJM
        CYAN , WHITE,
        GREEN, GREEN, GREEN, // ,KI
        GREEN, GREEN, GREEN, // OL.
        ORANG, ORANG, ORANG, // /;P
        BLUE , ORANG, ORANG, // DEL, ', SFT
    },

    [LAYER_NUMSYM] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        BLACK, BLACK,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        ORANG, GREEN, ORANG, // NHY
        CYAN , CYAN , GREEN, // UJM
        BLACK, BLACK,
        ORANG, ORANG, ORANG, // ,KI
        ORANG, ORANG, ORANG, // OL.
        ORANG, ORANG, ORANG, // /;P
        BLUE , ORANG, BLUE , // DEL, ', SFT
    },

    [LAYER_NUMFN] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        BLACK, RED  , RED  , // NHY
        MAGNT, MAGNT, MAGNT, // UJM
        BLACK, WHITE,
        MAGNT, MAGNT, MAGNT, // ,KI
        MAGNT, MAGNT, MAGNT, // OL.
        MAGNT, MAGNT, MAGNT, // /;P
        BLACK, BLACK, BLACK, // DEL, ', SFT
    },

    [LAYER_MOUSE] = {
        // Left
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        CYAN , CYAN , CYAN , // BGT
        CYAN , CYAN , CYAN , // RFV
        MAGNT, BLUE ,
        CYAN , CYAN , CYAN , // CDE
        CYAN , CYAN , CYAN , // WSX
        CYAN , CYAN , CYAN , // ZAQ
        BLUE , BLUE , BLUE , // TAB, CMD, SFT

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK,
        BLACK, MAGNT, ORANG, // NHY
        ORANG, GREEN, MAGNT, // UJM
        BLACK, WHITE,
        MAGNT, GREEN, GREEN, // ,KI
        ORANG, GREEN, MAGNT, // OL.
        BLACK, MAGNT, ORANG, // /;P
        BLACK, BLACK, WHITE, // DEL, ', SFT
    },
};
