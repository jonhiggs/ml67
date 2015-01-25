#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device.
#                Please customize your programmer settings(PROGRAM_CMD)
#
# make teensy = Download the hex file to the device, using teensy_loader_cli.
#               (must have teensy_loader_cli installed).
#
# make dfu = Download the hex file to the device, using dfu-programmer (must
#            have dfu-programmer installed).
#
# make flip = Download the hex file to the device, using Atmel FLIP (must
#             have Atmel FLIP installed).
#
# make dfu-ee = Download the eeprom file to the device, using dfu-programmer
#               (must have dfu-programmer installed).
#
# make flip-ee = Download the eeprom file to the device, using Atmel FLIP
#                (must have Atmel FLIP installed).
#
# make debug = Start either simulavr or avarice as specified for debugging, 
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------

# Target file name (without extension).
TARGET = ml62_lufa

# Directory common source files exist
TOP_DIR = ../..
LUFA_PATH = protocol/lufa/LUFA-130901

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC = keymap_common.c \
    matrix.c \
    led.c

ifdef KEYMAP
    SRC := keymap_$(KEYMAP).c $(SRC)
else
    SRC := keymap_plain.c $(SRC)
endif

CONFIG_H = config.h


MCU = atmega32u4
BOARD = TEENSY2
F_CPU = 16000000
F_USB = 16000000
ARCH = AVR8

# Boot Section Size in *bytes*
#   Teensy halfKay   512
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
OPT_DEFS += -DBOOTLOADER_SIZE=512


# Build Options
#   comment out to disable the options.
#
#BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no    # Mouse keys(+5000)
EXTRAKEY_ENABLE = yes   # Audio control and System control(+600)
CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes       # USB Nkey Rollover(+500)
#PS2_MOUSE_ENABLE = yes  # PS/2 mouse(TrackPoint) support

#---------------- Programming Options --------------------------
AVRDUDE = /Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avrdude
# Type: avrdude -c ? to get a full listing.
AVRDUDE_PROGRAMMER = avr109
AVRDUDE_MCU = atmega32u4
AVRDUDE_PORT = /dev/tty.usbmodem411
AVRDUDE_BAUD = 57600
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_CFG = /Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/etc/avrdude.conf
#AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(TARGET).eep

# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
#AVRDUDE_ERASE_COUNTER = -y

# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
#AVRDUDE_NO_VERIFY = -V

# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude> 
# to submit bug reports.
AVRDUDE_VERBOSE = -v -v

AVRDUDE_FLAGS = -C ${AVRDUDE_CFG} -p $(AVRDUDE_MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)
#AVRDUDE_FLAGS = -p $(AVRDUDE_MCU) -c $(AVRDUDE_PROGRAMMER)
AVRDUDE_FLAGS += $(AVRDUDE_NO_VERIFY)
AVRDUDE_FLAGS += $(AVRDUDE_VERBOSE)
AVRDUDE_FLAGS += $(AVRDUDE_ERASE_COUNTER)

PROGRAM_CMD = $(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TOP_DIR)

include $(TOP_DIR)/protocol/lufa.mk
include $(TOP_DIR)/common.mk
include $(TOP_DIR)/rules.mk

plain: OPT_DEFS += -DKEYMAP_PLAIN
plain: all
