// The MIT License (MIT)
//
// Copyright (c) 2024 David Marchante
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

#define CAPS_WORD_IDLE_TIMEOUT 3000
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
// #define CAPS_WORD_TOGGLE_KEY

// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 250

#define COMBO_TERM 25
#define PERMISSIVE_HOLD
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2
// #define QUICK_TAP_TERM 200 // Affects TT()

// sm_td
#define MAX_DEFERRED_EXECUTORS 10

// achordion
#define ACHORDION_STREAK

// RGB
#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 300000

// VIA
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// UEFI was not detecting some of my boards
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_MAX_CONNECTION_ERRORS 30
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1000
#define SPLIT_USB_TIMEOUT_POLL 20
#define SPLIT_WATCHDOG_TIMEOUT 5000
