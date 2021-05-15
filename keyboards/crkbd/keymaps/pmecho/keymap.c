#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMSYM 1
#define _NAV 2
#define _NUMFUN 3
#define _RESET 4
#define _GAME 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMSYM,
  NAV,
  NUMFUN,
  GAME,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
           KC_ESC,        KC_Q,       KC_W,         KC_E,        KC_R,        KC_T,                                     KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,     KC_BSPC,\
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
    CMD_T(KC_TAB), SFT_T(KC_A), CTL_T(KC_S), ALT_T(KC_D), CMD_T(KC_F),        KC_G,                                     KC_H, CMD_T(KC_J), ALT_T(KC_K), CTL_T(KC_L), SFT_T(KC_SCLN),  KC_QUOT,\
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
          KC_LSFT,        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,                                     KC_N,        KC_M,     KC_COMM,      KC_DOT,     KC_SLSH,     KC_RSFT,\
  //|------------+------------+------------+------------+------------+------------|------------|  |------------|------------+------------+------------+------------+------------+------------|
                                                KC_BSLS, LT(_NUMFUN,KC_GRV), LT(_NUMSYM,KC_SPC),   LT(_NAV,KC_ENT),  KC_MINS,  KC_EQL \
                                                      //`--------------------------------------'  `--------------------------------------'
  ),
	[_NUMSYM] = LAYOUT(KC_ESC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_PLUS, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, LSFT_T(KC_MINS), LCTL_T(KC_EQL), LALT_T(KC_LBRC), LGUI_T(KC_RBRC), KC_BSLS, KC_EQL, RGUI_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6), RSFT_T(KC_NO), KC_NO, KC_LSFT, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_NO, KC_MINS, KC_1, KC_2, KC_3, KC_NO, KC_RSFT, KC_NO, KC_NO, KC_SPC, LT(_NUMFUN,KC_0), KC_DOT, LALT_T(KC_COMM)),
	[_NAV] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_BSPC, LCTL_T(KC_TAB), KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LT(_NUMFUN,KC_MPLY), KC_NO, KC_NO, KC_NO),
	[_NUMFUN] = LAYOUT(LCMD(LCTL(KC_Q)), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, TG(_GAME), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_ESC, KC_CAPS, KC_ENT, KC_NO, LT(_RESET,KC_NO)),
	[_RESET] = LAYOUT(RESET, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [_GAME] = LAYOUT( \
  //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
           KC_ESC,        KC_Q,       KC_W,         KC_E,        KC_R,        KC_T,                                     KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,     KC_BSPC,\
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
           KC_TAB,        KC_A,       KC_S,         KC_D,        KC_F,        KC_G,                                     KC_H,        KC_J,        KC_K,        KC_L,     KC_SCLN,  KC_QUOT,\
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
          KC_LSFT,        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,                                     KC_N,        KC_M,     KC_COMM,      KC_DOT,     KC_SLSH,     TG(_GAME),\
  //|------------+------------+------------+------------+------------+------------|------------|  |------------|------------+------------+------------+------------+------------+------------|
                                                      KC_BSLS,              KC_GRV,      KC_SPC,   LT(_NAV,KC_ENT),  KC_MINS,  KC_EQL \
                                                      //`--------------------------------------'  `--------------------------------------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting NUMFUN layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case NUMSYM:
      if (record->event.pressed) {
        layer_on(_NUMSYM);
        update_tri_layer_RGB(_NUMSYM, _NAV, _NUMFUN);
      } else {
        layer_off(_NUMSYM);
        update_tri_layer_RGB(_NUMSYM, _NAV, _NUMFUN);
      }
      return false;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer_RGB(_NUMSYM, _NAV, _NUMFUN);
      } else {
        layer_off(_NAV);
        update_tri_layer_RGB(_NUMSYM, _NAV, _NUMFUN);
      }
      return false;
    case NUMFUN:
        if (record->event.pressed) {
          layer_on(_NUMFUN);
        } else {
          layer_off(_NUMFUN);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
