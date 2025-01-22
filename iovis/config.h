#pragma once

// Debugging
// #define DEBUG_MATRIX_SCAN_RATE

// Caps Word
#define CAPS_WORD_TOGGLE_KEY
#define CAPS_WORD_INVERT_ON_SHIFT // don't break caps word on shift
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
// #define CAPS_WORD_IDLE_TIMEOUT 5000

// Chordal Hold
#define CHORDAL_HOLD

// Combos
#define COMBO_TERM 25
#define COMBO_SHOULD_TRIGGER

// Leader
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 250

// RGB
#define RGB_MATRIX_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_VAL 15

// Taps
#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 2
#endif
// #define QUICK_TAP_TERM 200 // Affects TT()
