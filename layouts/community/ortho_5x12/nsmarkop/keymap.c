#include QMK_KEYBOARD_H
#include "action_layer.h"
// TODO: #include "steno.h"

// Make things a little easier to read in the keymaps
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MIDI,
  _FOURTHS
  // TODO: _SERIAL
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MIDI,
  FOURTHS_ON,
  FOURTHS_OFF
  // TODO: SERIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = KEYMAP(
  KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,  KC_5,      KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    ADJUST,
  KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,      KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_BSPACE,  KC_A,    KC_R,    KC_S,    KC_T,  KC_D,      KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
  KC_LCTL,    KC_LGUI, KC_LALT, KC_HYPR, LOWER, KC_SPC,    KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_QWERTY] = KEYMAP(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
),

[_LOWER] = KEYMAP(
  _______, _______,    _______, _______,   _______, _______,    _______, _______, _______, _______,   _______, _______,
  _______, KC_F1,      KC_F2,   KC_F3,     KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  _______,
  _______, KC_LEFT,    KC_DOWN, KC_UP,     KC_RGHT, KC_HOME,    _______, KC_MPLY, KC_MUTE, KC_F11,    KC_F12,  _______,
  _______, KC_PSCREEN, _______, KC_PGDOWN, KC_PGUP, KC_END,     _______, KC_MNXT, KC_MPRV, KC_INSERT, _______, _______,
  _______, _______,    _______, _______,   _______, _______,    _______, _______, _______, _______,   _______, _______
),

[_RAISE] = KEYMAP(
  _______, _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______,  _______,
  _______, KC_UNDS, KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH,    KC_BSLASH, KC_RPRN, KC_RBRC, KC_RCBR, KC_EQUAL, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,      KC_7,    KC_8,    KC_9,    KC_0,     _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,   KC_AMPR, KC_ASTR, KC_MINUS,KC_PLUS,  _______,
  _______, _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______,  _______
),

[_ADJUST] = KEYMAP(
  RESET,   MAGIC_TOGGLE_NKRO, _______, _______, _______, _______,    _______, _______,    _______, _______, _______,  _______,
  _______, _______,           _______, _______, _______, _______,    _______, FOURTHS_ON, _______, _______, _______,  _______,
  _______, _______,           _______, _______, _______, _______,    _______, MIDI,       QWERTY,  KC_RALT, KC_RCTRL, _______,
  _______, _______,           _______, _______, _______, _______,    _______, _______,    _______, _______, _______,  _______,
  _______, _______,           _______, _______, _______, _______,    _______, _______,    _______, _______, _______,  _______
),

// NOTE: At this point in time, QMK's MIDI values are 2 off from what they actually
//       output for some reason. Octave shifts are taken care of automatically during
//       layer switching.

[_MIDI] = KEYMAP(
  MI_C,   MI_Cs,   MI_D,   MI_Ds,   MI_E,   MI_F,      MIDI,    MI_G,   MI_Gs,   MI_A,   MI_As,   MI_B,
  MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1,    MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1,
  MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2,    MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
  MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3,    MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
  MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4, MI_F_4,    MI_Fs_4, MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, MI_B_4
),

[_FOURTHS] = KEYMAP(
  MI_Cs_3, MI_D_3,  MI_Ds_3, MI_E_3,  MI_F_3, MI_Fs_3,    MI_G_3, MI_Gs_3, MI_A_3,  MI_As_3, MI_B_3,  MI_C_4,
  MI_Gs_2, MI_A_2,  MI_As_2, MI_B_2,  MI_C_3, MI_Cs_3,    MI_D_3, MI_Ds_3, MI_E_3,  MI_F_3,  MI_Fs_3, MI_G_3,
  MI_Ds_2, MI_E_2,  MI_F_2,  MI_Fs_2, MI_G_2, MI_Gs_2,    MI_A_2, MI_As_2, MI_B_2,  MI_C_3,  MI_Cs_3, MI_D_3,
  MI_As_1, MI_B_1,  MI_C_2,  MI_Cs_2, MI_D_2, MI_Ds_2,    MI_E_2, MI_F_2,  MI_Fs_2, MI_G_2,  MI_Gs_2, MI_A_2,
  MI_F_1,  MI_Fs_1, MI_G_1,  MI_Gs_1, MI_A_1, MI_As_1,    MI_B_1, MI_C_2,  MI_Cs_2, MI_D_2,  MI_Ds_2, FOURTHS_OFF
)

// TODO:
// [_SERIAL] = KEYMAP(
//   STN_NA,  STN_N1,  STN_N2,  STN_N3,   STN_N4,  STN_N5,     STN_N6,  STN_N7,  STN_N8,   STN_N9,  STN_NB,  STN_NC,
//   STN_PWR, STN_S1,  STN_TL,  STN_PL,   STN_HL,  STN_ST1,    STN_ST3, STN_FR,  STN_PR,   STN_LR,  STN_TR,  STN_DR,
//   STN_FN,  STN_S2,  STN_KL,  STN_WL,   STN_RL,  STN_ST2,    STN_ST4, STN_RR,  STN_BR,   STN_GR,  STN_SR,  STN_ZR,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, STN_RES1, STN_A,   STN_O,      STN_E,   STN_U,   STN_RES2, XXXXXXX, XXXXXXX, SERIAL
// )

};

void matrix_init_user(void) {
  // TODO: steno_set_mode(STENO_MODE_GEMINI);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool sendKeypress = true;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_invert(_QWERTY);
      }
      sendKeypress = false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      sendKeypress = false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      sendKeypress = false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      sendKeypress = false;
      break;
    case MIDI:
      if (record->event.pressed) {
        layer_invert(_MIDI);
      }
      sendKeypress = false;
      break;
    case FOURTHS_ON:
      if (record->event.pressed) {
        // Account for QMK being 2 octaves too high
        midi_config.octave = midi_config.octave - 2;
        layer_on(_FOURTHS);
      }
      sendKeypress = false;
      break;
    case FOURTHS_OFF:
      if (record->event.pressed) {
        // Account for QMK being 2 octaves too high
        midi_config.octave = midi_config.octave + 2;
        layer_off(_FOURTHS);
      }
      sendKeypress = false;
      break;
    // TODO:
    // case SERIAL:
    //   if (record->event.pressed) {
    //     layer_invert(_SERIAL);
    //   }
    //   sendKeypress = false;
    //   break;
    default:
      sendKeypress = true;
      break;
  }

  return sendKeypress;
};
