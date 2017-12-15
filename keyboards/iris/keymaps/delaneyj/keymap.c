#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
// #define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
// #define _ADJUST 16

enum custom_keycodes {
  // QWERTY = SAFE_RANGE,
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  // ADJUST,
  GO_CHANNEL_PULL,
  GO_CHANNEL_PUSH,
  GO_VARIABLE_INIT,
  SWITCH_DESKTOPS_LEFT,
  SWITCH_DESKTOPS_RIGHT,
  WINDOWS_RUN
};

#define KC_MCUP KC_MS_UP
#define KC_MCDN KC_MS_DOWN
#define KC_MCLT KC_MS_LEFT
#define KC_MCRT KC_MS_RIGHT
#define KC_MCB1 KC_MS_BTN1
#define KC_MCB2 KC_MS_BTN2
#define KC_MCB3 KC_MS_BTN3
#define KC_MCB4 KC_MS_BTN4
#define KC_MCB5 KC_MS_BTN5
#define KC_MCWU KC_MS_WH_UP
#define KC_MCWD KC_MS_WH_DOWN
#define KC_MCWL KC_MS_WH_LEFT
#define KC_MCWR KC_MS_WH_RIGHT
// #define KC_MCA0 KC_MS_ACCEL0
// #define KC_MCA1 KC_MS_ACCEL1
// #define KC_MCA2 KC_MS_ACCEL2

#define KC_UNDR KC_UNDERSCORE
#define KC_WGUI LCTL(KC_LGUI)

#define KC_TTUP TT(_RAISE)
#define KC_TTDN TT(_LOWER)

#define KC_SELU LCTL(LALT(KC_UP))
#define KC_SELD LCTL(LALT(KC_DOWN))

#define KC_CTLZ LCTL(KC_Z)
#define KC_CTLY LCTL(KC_Y)

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_GOPS GO_CHANNEL_PUSH
#define KC_GOPL GO_CHANNEL_PULL
#define KC_GOVR GO_VARIABLE_INIT

#define KC_DLFT SWITCH_DESKTOPS_LEFT
#define KC_DRGT SWITCH_DESKTOPS_RIGHT
#define KC_WRUN LGUI(KC_R)
//Tap Dance Declarations
enum {
  TD_ESCAPE_UNDO = 0,
  TD_EQUALS_REDO,
  // TD_SUPER_ARROW_LEFT,
  // TD_SUPER_ARROW_RIGHT
};
#define KC_TDEZ TD(TD_ESCAPE_UNDO)
#define KC_TDEY TD(TD_EQUALS_REDO)
// #define KC_TDSL TD(TD_SUPER_ARROW_LEFT)
// #define KC_TDSR TD(TD_SUPER_ARROW_RIGHT)

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESCAPE_UNDO]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_Z), KC_ESC),
  [TD_EQUALS_REDO]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_Y), KC_EQL),
  // [TD_SUPER_ARROW_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LCTL(KC_LEFT)),
  // [TD_SUPER_ARROW_RIGHT] =  ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, LCTL(KC_RGHT))
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TDEZ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,MINS,GRV ,TDEY,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+- ---+----+----|
     LSFT, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,RSFT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,DEL ,         , K  , M  ,COMM,DOT ,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,TTDN,BSPC,       SPC ,TTUP,ENT
  //                  `----+----+----'      `----+----+----'
  ),
  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     F1  , F2 , F3 , F4 , F5 , F6 ,                F7  , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,SELU, NO , UP ,VOLU,LPRN,                RPRN, P7 , P8 , P9 ,PLUS,ASTR,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,SELD,LEFT,DOWN,RGHT,LBRC,                RBRC, P4 , P5 , P6 ,MINS,PGUP,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         , NO , NO ,MUTE,VOLD,LCBR,          ,    ,RCBR, P1 , P2 , P3 ,ENT ,PGDN,
  //`----+----+----+--+-+----+----+----/     \----+----+----+----+----+----+----'
                             ,    ,WRUN,         LGUI, P0 ,ENT   //
  //                    `----+----+----'      ----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     DLFT,    ,    ,    ,    ,GOPS,               GOPL,GOVR,    ,    ,    ,DRGT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO , NO ,MCUP, NO , NO ,                NO ,MCWL,MCWU,MCWR, NO , NO ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO ,MCLT,MCDN,MCRT, NO ,                NO ,MCB1,MCWD,MCB2, NO , NO ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , NO , NO , NO , NO , NO ,    ,         , NO ,MCB4,MCB3,MCB5, NO ,RST ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  switch (keycode) {
    case COLEMAK:
      #ifdef AUDIO_ENABLE
       PLAY_SONG(tone_qwerty);
      #endif
      persistent_default_layer_set(1UL<<_COLEMAK);
      return false;
    // case GO_CHANNEL_PULL:
    //   SEND_STRING("->");
    //   return false;
    // case GO_CHANNEL_PUSH:
    //   SEND_STRING("<-");
    //   return false;
    // case GO_VARIABLE_INIT:
    //   SEND_STRING(":=");
    case SWITCH_DESKTOPS_LEFT:
      SEND_STRING(
        SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LEFT)
        SS_UP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTRL)
      );
      #ifdef AUDIO_ENABLE
       PLAY_SONG(tone_qwerty);
      #endif
      return false;
    case SWITCH_DESKTOPS_RIGHT:
      SEND_STRING(
        SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_RIGHT)
        SS_UP(X_RIGHT)SS_UP(X_LGUI)SS_UP(X_LCTRL)
      );
      #ifdef AUDIO_ENABLE
       PLAY_SONG(tone_qwerty);
      #endif
      return false;
  }
  }
  return true;
}

