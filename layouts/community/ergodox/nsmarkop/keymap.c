#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define ______ KC_TRNS
#define XXXXXX KC_NO

#define L_COLEMAK 0 // Colemak layer
#define L_QWERTY  1 // QWERTY layer, needed until Windows stops sucking for Korean IMEs
#define L_STENO   2 // MIDI / stenography layer
#define L_MISC    3 // Function / symbols layer
#define L_MOUSE   4 // Mouse layer
#define L_SYSTEM  6 // System / keyboard functionality related layer

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    STENO,
    KOREAN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_COLEMAK] = LAYOUT_ergodox(
        // Left hand
        KC_ESCAPE, KC_1,        KC_2,        KC_3,    KC_4,     KC_5,      KC_GRAVE,
        KC_EQUAL,  KC_Q,        KC_W,        KC_F,    KC_P,     KC_G,      STENO,
        KC_LSHIFT, KC_A,        KC_R,        KC_S,    KC_T,     KC_D,
        KC_LCTL,   KC_Z,        KC_X,        KC_C,    KC_V,     KC_B,      KC_HYPR,
        KC_LALT,   KC_LBRACKET, KC_RBRACKET, KC_LPRN, KC_RPRN,
                                                                KC_LGUI,   KC_INSERT,
                                                                           KC_HOME,
                                                      KC_SPACE, KC_BSPACE, KC_END,

        // Right hand
        QWERTY,     KC_6,               KC_7,     KC_8,     KC_9,   KC_0,      KC_MINUS,
        KOREAN,     KC_J,               KC_L,     KC_U,     KC_Y,   KC_SCOLON, KC_BSLASH,
                    KC_H,               KC_N,     KC_E,     KC_I,   KC_O,      KC_QUOTE,
        KC_DEL,     KC_K,               KC_M,     KC_COMMA, KC_DOT, KC_SLASH,  KC_RALT,
                                        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,  KC_RCTL,
        KC_PSCREEN, KC_PAUSE,
        KC_PGUP,
        KC_PGDOWN,  LT(L_MISC, KC_TAB), KC_ENTER
    ),

    [L_QWERTY] = LAYOUT_ergodox(
        // Left hand
        ______, ______, ______, ______, ______, ______, ______,
        ______, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   ______,
        ______, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        ______, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   ______,
        ______, ______, ______, ______, ______,
                                                ______, ______,
                                                        ______,
                                        ______, ______, ______,

        // Right hand
        COLEMAK, ______, ______, ______,   ______, ______,    ______,
        ______,  KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,      ______,
                 KC_H,   KC_J,   KC_K,     KC_L,   KC_SCOLON, ______,
        ______,  KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLASH,  ______,
                         ______, ______,   ______, ______,    ______,
        ______,  ______,
        ______,
        ______,  ______, ______
    ),

    [L_STENO] = LAYOUT_ergodox(
        // Left hand
        MI_C,   MI_Cs,   MI_D,   MI_Ds,   MI_E,   MI_F,    COLEMAK,
        MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1,  XXXXXX,
        MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2,
        MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3,  XXXXXX,
        MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4,
                                                  MI_F_5,  MI_E_5,
                                                           MI_Ds_5,
                                          MI_C_5, MI_Cs_5, MI_D_5,

        // Right hand
        COLEMAK, MI_Fs,   MI_G,   MI_Gs,   MI_A,   MI_As,   MI_B,
        XXXXXX,  MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1,
                 MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
        XXXXXX,  MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
                          MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, MI_B_3,
        MI_As_5, MI_B_5,
        MI_A_5,
        MI_Gs_5, MI_G_5,  MI_Fs_5
    ),

    [L_MISC] = LAYOUT_ergodox(
        // Left hand
        ______, KC_F1,   KC_F2,   KC_F3,       KC_F4,        KC_F5,       ______,
        ______, KC_EXLM, KC_AT,   KC_LCBR,     KC_RCBR,      KC_GRAVE,    KC_TILD,
        ______, KC_HASH, KC_DLR,  KC_LPRN,     KC_RPRN,      KC_BSLASH,
        ______, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET,  KC_PIPE,     ______,
        ______, KC_AMPR, KC_ASTR, ______,      ______,
                                                             ______,      ______,
                                                                          ______,
                                               MO(L_SYSTEM), MO(L_MOUSE), ______, 

        // Right hand
        ______, KC_F6,         KC_F7,   KC_F8,     KC_F9,       KC_F10,         KC_F11,
        ______, KC_SCROLLLOCK, KC_KP_7, KC_KP_8,   KC_KP_9,     KC_KP_SLASH,    KC_F12,
                KC_NUMLOCK,    KC_KP_4, KC_KP_5,   KC_KP_6,     KC_KP_ASTERISK, ______,
        ______, KC_CAPSLOCK,   KC_KP_1, KC_KP_2,   KC_KP_3,     KC_KP_MINUS,    ______,
                               KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_KP_PLUS,     ______,
        ______, ______,
        ______,
        ______, ______,        ______
    ),

    [L_MOUSE] = LAYOUT_ergodox(
        // Left hand
        ______, ______,     ______,     ______,        ______,        ______, ______,
        ______, ______,     ______,     KC_MS_WH_LEFT, KC_MS_WH_DOWN, ______, ______,
        ______, KC_MS_BTN3, KC_MS_BTN1, KC_MS_LEFT,    KC_MS_DOWN,    ______,  
        ______, ______,     ______,     ______,        ______,        ______, ______,
        ______, ______,     ______,     ______,        ______,
                                                                      ______, ______,
                                                                              ______,
                                                       XXXXXX,        ______, ______,

        // Right hand
        ______, ______, ______,       ______,         ______,       ______,     ______,
        ______, ______, KC_MS_WH_UP,  KC_MS_WH_RIGHT, ______,       ______,     ______,
                ______, KC_MS_UP,     KC_MS_RIGHT,    KC_MS_BTN2,   KC_MS_BTN4, ______,
        ______, ______, KC_MS_ACCEL0, KC_MS_ACCEL1,   KC_MS_ACCEL2, ______,     ______,
                        ______,       ______,         ______,       ______,     ______,
        ______, ______,
        ______,
        ______, ______, ______
    ),

    [L_SYSTEM] = LAYOUT_ergodox(
        // Left hand
        ______, ______, ______, ______, ______,            ______, ______,
        ______, ______, ______, ______, ______,            ______, ______,
        ______, ______, ______, RESET,  MAGIC_TOGGLE_NKRO, ______,
        ______, ______, ______, ______, ______,            ______, ______,
        ______, ______, ______, ______, ______,
                                                           ______, ______,
                                                                   ______,
                                        ______,            XXXXXX, ______,

        // Right hand
        ______, ______, ______,              ______,              ______,              ______,          ______,
        ______, ______, ______,              ______,              ______,              ______,          ______,
                ______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_SELECT, ______,
        ______, ______, KC_AUDIO_MUTE,       KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_MEDIA_STOP,   ______,
                        ______,              ______,              ______,              ______,          ______,
        ______, ______,
        ______,
        ______, ______, ______
    )

    // [L_BLANK] = LAYOUT_ergodox(
    //     // Left hand
    //     ______, ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______,
    //                                             ______, ______,
    //                                                     ______,
    //                                     ______, ______, ______,

    //     // Right hand
    //     ______, ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______, ______, ______,
    //             ______, ______, ______, ______, ______, ______,
    //     ______, ______, ______, ______, ______, ______, ______,
    //                     ______, ______, ______, ______, ______,
    //     ______, ______,
    //     ______,
    //     ______, ______, ______
    // )
};

void enable_QWERTY(void) {
    // Overrides the base part of Colemak but keeps other keys
    layer_on(L_COLEMAK);
    layer_on(L_QWERTY); 
};

void disable_all_layers(void) {
    layer_off(L_COLEMAK);
    layer_off(L_QWERTY);
    layer_off(L_STENO);
    layer_off(L_MISC);
    layer_off(L_MOUSE);
    layer_off(L_SYSTEM);
};

// Override any behavior for key processing before the key event is handled 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool sendKeypress = true;

    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                disable_all_layers();
                layer_on(L_COLEMAK);
            }
            sendKeypress = false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                disable_all_layers();
                enable_QWERTY();
            }
            sendKeypress = false;
            break;
        case STENO:
            if (record->event.pressed) {
                disable_all_layers();
                layer_on(L_STENO);
            }
            sendKeypress = false;
            break;
        case KOREAN:
            if (record->event.pressed) {
                disable_all_layers();
                enable_QWERTY();

                // Enable Hangul via standard IME shortcut
                register_code(KC_RALT);
                unregister_code(KC_RALT);
            }
            sendKeypress = false;
            break;
        default:
            sendKeypress = true;
            break;
    }
    
    return sendKeypress;
};

// Runs just one time when the keyboard initializes
void matrix_init_user(void) {
    // TODO: steno_set_mode(STENO_MODE_GEMINI);
};

// Runs constantly in the background, in a loop
void matrix_scan_user(void) {
    // Reset LEDs
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Turn on layer-specific LEDs
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case L_COLEMAK:
            ergodox_right_led_1_on();
            break;
        case L_QWERTY:
            ergodox_right_led_2_on();
            break;
        case L_STENO:
            ergodox_right_led_3_on();
            break;
        case L_MISC:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case L_MOUSE:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case L_SYSTEM:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
};
