BOOTLOADER = rp2040
RGB_MATRIX_ENABLE = no
VIA_ENABLE = no

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk
