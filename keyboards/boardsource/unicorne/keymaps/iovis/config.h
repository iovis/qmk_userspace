#pragma once

#define CAPS_WORD_TOGGLE_KEY
#define COMBO_TERM 25
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 200 // Messes up TAPPING_TOGGLE for some reason
#define TAPPING_TOGGLE 2

// VIA
#define DYNAMIC_KEYMAP_LAYER_COUNT 7

// UEFI was not detecting some of my boards
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_MAX_CONNECTION_ERRORS 30
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1000
#define SPLIT_USB_TIMEOUT_POLL 20
#define SPLIT_WATCHDOG_TIMEOUT 5000
