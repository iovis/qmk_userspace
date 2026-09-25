// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "iovis/config.h"

// Ignore the board's GP17 handedness pin to make the USB half act as left.
// Connecting USB to the physical right half would then swap the hands.
// Flash both halves if you use either USB port
// #undef SPLIT_HAND_PIN

// Use the outer top-right Backspace key for right Bootmagic
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 0
