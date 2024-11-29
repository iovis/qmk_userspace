#pragma once

// Debugging
#define DEBUG_MATRIX_SCAN_RATE

// Achordion
#define ACHORDION_STREAK

// Caps Word
#define CAPS_WORD_IDLE_TIMEOUT 3000
#define CAPS_WORD_TOGGLE_KEY
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Combos
#define COMBO_TERM 25

// Leader
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 250

// RGB
#define RGB_MATRIX_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_VAL 15

// SMTD
#define MAX_DEFERRED_EXECUTORS 10

// Taps
#define PERMISSIVE_HOLD
#define TAPPING_TERM 175
#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 2
#endif
// #define QUICK_TAP_TERM 200 // Affects TT()
