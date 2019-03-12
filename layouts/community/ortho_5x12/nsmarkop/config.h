#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

// TODO: Fix I2C on the board 
// Use I2C instead of Serial
// #undef USE_SERIAL
// #define USE_I2C

// Hand configuration
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

// Enable features
#define FORCE_NKRO
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#define MIDI_ADVANCED
#define MIDI_TONE_KEYCODE_OCTAVES 6

// Disable features
#ifndef NO_DEBUG
#define NO_DEBUG
#endif
#ifndef NO_PRINT
#define NO_PRINT
#endif

#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO

#endif
