// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "iovis/config.h"

// VIA
// #define DYNAMIC_KEYMAP_LAYER_COUNT 5

// UEFI was not detecting some of my boards
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_MAX_CONNECTION_ERRORS 30
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1000
#define SPLIT_USB_TIMEOUT_POLL 20
#define SPLIT_WATCHDOG_TIMEOUT 5000
