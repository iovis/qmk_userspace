# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
AUDIO_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DEFERRED_EXEC_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = yes
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
POINTING_DEVICE_ENABLE = no
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
SRC += features/achordion.c
SRC += features/custom_shift_keys.c
SRC += features/layer_lock.c
SRC += features/socd_cleaner.c
TAP_DANCE_ENABLE = no

# Disable ZSA's layer lock in favor of mine
LAYER_LOCK_ENABLE = no
