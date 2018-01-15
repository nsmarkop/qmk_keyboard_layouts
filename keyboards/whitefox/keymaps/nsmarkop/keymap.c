#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define L_COLEMAK 0 // Colemak layer
#define L_QWERTY  1 // QWERTY layer, needed until Windows stops sucking for Korean IMEs
#define L_MISC    2 // Function / symbols layer
#define L_MOUSE   3 // Mouse layer
#define L_SYSTEM  4 // System / keyboard functionality related layer
#define L_BLANK   5 // Blank layer to use as reference, does nothing

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    KOREAN
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|Ins|
     * |---------------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del|
     * |---------------------------------------------------------------|
     * |  FN  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |PgU|
     * |---------------------------------------------------------------|
     * | Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space         |Alt |Ctrl|  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        KC_GESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,KC_NO,KC_BSPC,KC_INS, \
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,   KC_BSLS,  KC_DEL, \
        MO(1),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,  KC_ENT,    KC_PGUP,\
        KC_LSFT, KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT, KC_UP,  KC_PGDN,\
        KC_LCTL, KC_LGUI,KC_LALT,                        KC_SPC,                 KC_RALT,KC_RCTL,KC_NO,       KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    /* Layer 1: FN Layer
     * ,---------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |       |pup|   |
     * |---------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |hom|pdn|end|
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP( \
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_MUTE,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,BL_TOGG,KC_TRNS,KC_TRNS,BL_INC, KC_TRNS,KC_PSCR,KC_SLCK,KC_PAUS,KC_TRNS,        KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,BL_DEC, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_VOLU,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_PGUP,KC_VOLD,\
        KC_TRNS,KC_TRNS,KC_TRNS,                        KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,        KC_HOME,KC_PGDN,KC_END  \
    ),
};

void enable_QWERTY(void) {
    // Overrides the base part of Colemak but keeps other keys
    layer_on(L_COLEMAK);
    layer_on(L_QWERTY); 
};

void disable_all_layers(void) {
    layer_off(L_COLEMAK);
    layer_off(L_QWERTY);
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

};

// Runs constantly in the background, in a loop
void matrix_scan_user(void) {
    // TODO: any LED stuff?
};
