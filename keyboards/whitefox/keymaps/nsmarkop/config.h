#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

// Enable features
#define FORCE_NKRO
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

// #define MIDI_BASIC
// #define MIDI_ADVANCED
// #define MIDI_TONE_KEYCODE_OCTAVES 3

// Disable features
#ifndef NO_DEBUG
#define NO_DEBUG
#endif
#ifndef NO_PRINT
#define NO_PRINT
#endif

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO

// Mousekeys configuration
// #define MOUSEKEY_DELAY             300
// #define MOUSEKEY_INTERVAL          50
// #define MOUSEKEY_MAX_SPEED         10
// #define MOUSEKEY_TIME_TO_MAX       20
// #define MOUSEKEY_WHEEL_MAX_SPEED   8
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif