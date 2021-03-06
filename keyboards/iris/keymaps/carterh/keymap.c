#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
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
  SWITCH_DESKTOPS_LEFT,
  SWITCH_DESKTOPS_RIGHT,
  WINDOWS_RUN
};

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


#define KC_DLFT SWITCH_DESKTOPS_LEFT
#define KC_DRGT SWITCH_DESKTOPS_RIGHT
#define KC_WRUN LGUI(KC_R)
#define KC_EXPL LGUI(KC_E)

//Tap Dance Declarations
enum {
  TD_ESCAPE_UNDO = 0,
  TD_EQUALS_REDO,
};
#define KC_TDEZ TD(TD_ESCAPE_UNDO)
#define KC_TDEY TD(TD_EQUALS_REDO)

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESCAPE_UNDO]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_Z), KC_ESC),
  [TD_EQUALS_REDO]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_Y), KC_EQL),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TDEZ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,MINS,GRV ,TDEY,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+- ---+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,RSFT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     , Z  , X  , C  , V  , B  ,DEL ,         , N  , M  ,COMM,DOT ,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,TTDN,BSPC,       SPC ,TTUP,ENT
  //                  `----+----+----'      `----+----+----'
  ),
  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     F1  , F2 , F3 , F4 , F5 , F6 ,                F7  , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,SELU, NO , UP ,VOLU,MNXT,                PMNS, P7 , P8 , P9 ,PPLS,NLCK,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,SELD,LEFT,DOWN,RGHT,MPLY,                PSLS, P4 , P5 , P6 ,PAST,PGUP,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         , NO , NO ,MUTE,VOLD,MNXT,WSCH      ,EXPL,PDOT, P1 , P2 , P3 ,PEQL,PGDN,
  //`----+----+----+--+-+----+----+----/     \----+----+----+----+----+----+----'
                             ,    ,WRUN,         LGUI, P0 ,PENT   //
  //                    `----+----+----'      ----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     DLFT,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,DRGT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO , NO ,MS_U, NO ,LCBR,               RCBR,WH_L,WH_U,WH_R, NO , NO ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO ,MS_L,MS_D,MS_R,LPRN,               RPRN,BTN1,WH_D,BTN2, NO , NO ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , NO , NO , NO , NO ,LBRC,    ,         ,RBRC,BTN2,BTN3,BTN5, NO ,RST ,
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
      persistent_default_layer_set(1UL<<_QWERTY);
      return false;
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

