# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = lite   # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes    # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
NKRO_ENABLE = yes       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = no   # Enable keyboard underlight functionality
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
MIDI_ENABLE = no        # MIDI controls
AUDIO_ENABLE = no
UNICODE_ENABLE = no     # Unicode
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID
COMBO_ENABLE = yes      # Enable combos
TAP_DANCE_ENABLE = no  # Enable tap dance

LAYOUTS = 60_ansi 60_iso 60_ansi_split_bs_rshift
