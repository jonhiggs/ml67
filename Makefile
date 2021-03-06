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

# Path to Arduino.app
ARDUINO_PATH = /Applications/Arduino.app
export PATH := ${ARDUINO_PATH}/Contents/Java/hardware/tools/avr/bin:$(PATH)

# Target file name (without extension).
KEYMAP ?= unix
TARGET = ml67_${KEYMAP}

# tested on tmk_core dc0e46eaa4367d4e218f8816e3c117895820f07c
TMK_DIR = ../tmk_core

# Directory common source files exist
TOP_DIR = ../..
#LUFA_PATH = protocol/lufa/LUFA-git

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC = keymap_$(KEYMAP).c \
      keymap_common.c \
      matrix.c \
      led.c \

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
NKRO_ENABLE = no        # USB Nkey Rollover(+500)
PS2_MOUSE_ENABLE = no   # PS/2 mouse(TrackPoint) support

#---------------- Programming Options --------------------------
AVRDUDE = ${ARDUINO_PATH}/Contents/Java/hardware/tools/avr/bin/avrdude
# Type: avrdude -c ? to get a full listing.
AVRDUDE_PROGRAMMER = avr109
AVRDUDE_MCU = atmega32u4
AVRDUDE_PORT = /dev/tty.usbmodem411
AVRDUDE_BAUD = 57600
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_CFG = ${ARDUINO_PATH}/Contents/Java/hardware/tools/avr/etc/avrdude.conf
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
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk

plain: OPT_DEFS += -DKEYMAP_PLAIN
plain: all

git_reset:
	git reset --hard
	git checkout origin/master
	git branch -D master
	git branch master
	git pull origin master

git_update:
	git checkout master
	git pull origin master

git_tests:
	git checkout tests
	git reset --hard
	git fetch
	git checkout origin/tests
	git branch -D tests
	git branch tests
	git checkout tests

