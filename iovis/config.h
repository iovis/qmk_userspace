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

// Mouse
#define MK_3_SPEED          // Constant speed
#define MK_C_OFFSET_0 4     // Cursor offset per movement
#define MK_C_OFFSET_1 8     // Cursor offset per movement
#define MK_C_OFFSET_2 16    // Cursor offset per movement
#define MK_C_INTERVAL_0 16  // Time between cursor movements
#define MK_C_INTERVAL_1 16  // Time between cursor movements
#define MK_C_INTERVAL_2 16  // Time between cursor movements
#define MK_W_OFFSET_0 1     // Scroll steps per scroll action
#define MK_W_OFFSET_1 1     // Scroll steps per scroll action
#define MK_W_OFFSET_2 1     // Scroll steps per scroll action
#define MK_W_INTERVAL_0 360 // Time between scroll steps
#define MK_W_INTERVAL_1 80  // Time between scroll steps
#define MK_W_INTERVAL_2 60  // Time between scroll steps

// RGB
#define RGB_MATRIX_TIMEOUT 300000
// #define RGB_MATRIX_DEFAULT_VAL 15 // Initial brightness

// Taps
#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 2
#endif
#define QUICK_TAP_TERM_PER_KEY
// #define QUICK_TAP_TERM 200 // Affects TT()
