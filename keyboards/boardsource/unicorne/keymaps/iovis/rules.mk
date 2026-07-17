BOOTLOADER = rp2040

ENCODER_ENABLE = no
RGB_MATRIX_ENABLE = no
VIA_ENABLE = no

# The keyboard rules add this source even when OLED support is disabled.
OLED_ENABLE = no
UNICORNE_SRC := $(filter-out lib/oled.c,$(SRC))
SRC = $(UNICORNE_SRC)

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk
