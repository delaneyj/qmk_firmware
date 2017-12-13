#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
// #define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  // QWERTY = SAFE_RANGE,
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  GO_CHANNEL_PULL,
  GO_CHANNEL_PUSH,
  GO_VARIABLE_INIT,
  SWITCH_DESKTOPS_LEFT,
  SWITCH_DESKTOPS_RIGHT,
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
#define KC_MCA0 KC_MS_ACCEL0
#define KC_MCA1 KC_MS_ACCEL1
#define KC_MCA2 KC_MS_ACCEL2

#define KC_UNDR KC_UNDERSCORE
#define KC_WGUI LCTL(KC_LGUI)

#define KC_TTUP TT(_RAISE)
#define KC_TTDN TT(_LOWER)

#define KC_SELU LCTL(LALT(KC_UP))
#define KC_SELD LCTL(LALT(KC_DOWN))
// #define KC_SELL LCTL(LSFT(KC_LEFT))
// #define KC_SELR LCTL(LSFT(KC_RGHT))

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,UNDR,GRV ,LGUI,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+- ---+----+----|
     LSFT, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,RSFT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,DEL ,     ENT , K  , M  ,COMM,DOT ,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,TTDN,BSPC,       SPC ,TTUP,RCTL
  //                  `----+----+----'      `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     F1  , F2 , F3 , F4 , F5 , F6 ,                F7  , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,SELU, NO , UP ,VOLU,LPRN,                RPRN, 7  , 8  , 9  ,PLUS,ASTR,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,SELD,LEFT,DOWN,RGHT,LBRC,                RBRC, 4  , 5  , 6  ,MINS,PGUP,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         , NO , NO ,MUTE,VOLD,LCBR,          , NO ,RCBR, 1  , 2  , 3  ,ENT ,PGDN,
  //`----+----+----+--+-+----+----+----/     \----+----+----+----+----+----+----'
                           ,    ,   ,         LGUI, 0  ,ENT   //
  //                    `----+----+----'      ----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     DLFT,    ,    ,    ,    ,GOPS,               GOPL,GOVR,    ,    ,    ,DRGT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO , NO ,MCUP, NO , NO ,               MCA0,MCWL,MCWU,MCWR, NO , NO ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO ,MCLT,MCDN,MCRT, NO ,               MCA1,MCB1,MCWD,MCB2, NO , NO ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , NO , NO , NO , NO , NO ,    ,         ,MCA2,MCB4,MCB3,MCB5, NO ,RST ,
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
    // case QWERTY:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(tone_qwerty);
    //     #endif
    //     persistent_default_layer_set(1UL<<_QWERTY);
    //   }
    //   return false;
    //   break;
    case COLEMAK:
      #ifdef AUDIO_ENABLE
       PLAY_SONG(tone_qwerty);
      #endif
      persistent_default_layer_set(1UL<<_COLEMAK);
      return false;
    case GO_CHANNEL_PULL:
      SEND_STRING("->");
      return false;
    case GO_CHANNEL_PUSH:
      SEND_STRING("<-");
      return false;
    case SWITCH_DESKTOPS_LEFT:
      SEND_STRING(
        SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LEFT)
        SS_UP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTRL)
      );
      return false;
    case SWITCH_DESKTOPS_RIGHT:
      SEND_STRING(
        SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LEFT)
        SS_UP(X_RIGHT)SS_UP(X_LGUI)SS_UP(X_LCTRL)
      );
      return false;

    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
  }
  }
  return true;
}
