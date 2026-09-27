// Copyright 2026 David Marchante
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// The RP2040 board config defines this after keymap config.h is included.
#if defined(KEYBOARD_beekeeb_piantor_pro) || defined(KEYBOARD_boardsource_unicorne)
#    undef RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#endif
