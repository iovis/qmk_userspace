// Copyright 2025 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "iovis/config.h"

/// Handedness
///
/// If you go this route, you'll have to flash each half with:
///
///   qmk flash -kb boardsource/unicorne -km iovis -bl uf2-split-left
///   qmk flash -kb boardsource/unicorne -km iovis -bl uf2-split-right
///
/// This will set the handedness in the EEPROM.
/// If you flash through Bootmagic key, it would clean the EEPROM and
/// the handedness will get lost, so you'll have to do it again.

// Keep physical left/right handedness when USB is connected to either half
// #define EE_HANDS

// Use the outer top-right Backspace key for right Bootmagic
// #define BOOTMAGIC_ROW_RIGHT 4
// #define BOOTMAGIC_COLUMN_RIGHT 0
