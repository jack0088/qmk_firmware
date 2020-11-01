#include QMK_KEYBOARD_H
#include <string.h>



// keymap for Kinesis Advantage2 (KB600) QWERTZ layout
// designed to run on MacOS/iPadOS/iOS and Windows
// please set system keyboard language to german!



enum keyboard_layer {
  QWERTZ_MACOS,
  QWERTZ_WINDOWS,
  QWERTZ_KEYPAD
};

#define IS_QWERTZ_MACOS (default_layer_state & (1UL << QWERTZ_MACOS))
#define IS_QWERTZ_WINDOWS (default_layer_state & (1UL << QWERTZ_WINDOWS))

enum custom_key {
  KCC_Q,
  KCC_A,
  KCC_S,
  KCC_E,
  KCC_D,
  KCC_C,
  KCC_R,
  KCC_T,
  KCC_F,
  KCC_G,
  KCC_B,
  KCC_Z,
  KCC_H,
  KCC_J,
  KCC_U,
  KCC_N,
  KCC_M,
  KCC_I,
  KCC_K,
  KCC_O,
  KCC_L,
  KCC_P,
  KCC_COMMA,
  KCC_DOT,
};

enum {
    SINGLE_TAP = 1,
    DOUBLE_TAP_CLR,
    DOUBLE_TAP,
    TRIPLE_TAP,
    QUADRUPLE_TAP,
    SINGLE_HOLD,
    DOUBLE_HOLD,
    TRIPLE_HOLD,
    QUADRUPLE_HOLD,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /******************************************************/
  /******************* base layer mac *******************/
  /******************************************************/

  [QWERTZ_MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,            KC_F1,        KC_F2,      KC_F3,      KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,            KC_1,         KC_2,       KC_3,       KC_4,       KC_5,
    XXXXXXX,            KC_Q,         KC_W,       TD(KCC_E),  TD(KCC_R),  TD(KCC_F),
    XXXXXXX,            TD(KCC_A),    TD(KCC_S),  TD(KCC_D),  TD(KCC_T),  TD(KCC_G),
    XXXXXXX,            KC_Z,         KC_X,       TD(KCC_C),  KC_V,       TD(KCC_B),
                        XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_LGUI,
    // left thumb
                  LALT_T(KC_DELETE),    XXXXXXX,
                                        KC_LCTRL,
    KC_SPACE,     LSFT_T(KC_TAB),       KC_LGUI,
    // right keywell
    KC_F9,      KC_F10,       KC_F11,         KC_F12,       KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    KC_6,       KC_7,         KC_8,           KC_9,         KC_0,           XXXXXXX,
    TD(KCC_Z),  TD(KCC_U),    TD(KCC_I),      TD(KCC_O),    XXXXXXX,        XXXXXXX,
    TD(KCC_H),  TD(KCC_N),    TD(KCC_K),      TD(KCC_L),    TD(KCC_P),      XXXXXXX,
    TD(KCC_J),  TD(KCC_M),    TD(KCC_COMMA),  TD(KCC_DOT),  KC_SLASH,       XXXXXXX,
                KC_LEFT,      KC_DOWN,        KC_UP,        KC_RGHT,
    // right thumb
    XXXXXXX,            LALT_T(KC_BSPACE),
    XXXXXXX,
    LGUI_T(KC_ESCAPE),  RSFT_T(KC_ENTER),       MO(QWERTZ_KEYPAD)
  ),

  /******************************************************/
  /******************* windows layer ********************/
  /******************************************************/

  [QWERTZ_WINDOWS] = LAYOUT(
    // left keywell
    _______,      _______,     _______,     _______,     _______,    _______,  _______,  _______,  _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
                  _______,     _______,     _______,     KC_LCTRL,
    // left thumb
                  RALT_T(KC_DELETE),  KC_LALT,
                                      KC_LGUI,
    _______,      _______,            KC_LCTRL,
    // right keywell
    _______,      _______,      _______,    _______,    _______,  _______,  _______,  _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
                  _______,      _______,    _______,    _______,
    // right thumb
    _______,            RALT_T(KC_BSPACE),
    _______,
    LCTL_T(KC_ESCAPE),  _______,    _______
  ),

  /******************************************************/
  /******************* keypad layer *********************/
  /******************************************************/

  [QWERTZ_KEYPAD] = LAYOUT(
    // left keywell
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    DF(QWERTZ_MACOS),  XXXXXXX,  DF(QWERTZ_WINDOWS),  XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
    XXXXXXX,      KC_KP_1,     KC_KP_2,     KC_KP_3,     KC_KP_4,    KC_KP_5,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
                  XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,
    // left thumb
                  _______,  _______,
                            _______,
    _______,      _______,  _______,
    // right keywell
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  _______,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
    KC_KP_6,      KC_KP_7,      KC_KP_8,    KC_KP_9,    KC_KP_0,              XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
                  _______,      _______,    _______,    _______,
    // right thumb
    XXXXXXX,  XXXXXXX,
    XXXXXXX,
    XXXXXXX,  KC_RSHIFT,  _______
  )
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LALT_T(KC_DELETE):
    case LALT_T(KC_BSPACE):
    case LGUI_T(KC_ESCAPE):
    case LSFT_T(KC_TAB):
    case RSFT_T(KC_ENTER):
    case RALT_T(KC_DELETE):
    case RALT_T(KC_BSPACE):
    case LCTL_T(KC_ESCAPE):
      return 100;
    default:
      return TAPPING_TERM;
  }
};



#define MODELESS(...) \
  do { \
    /*const uint8_t _modifiers = get_mods();*/ \
    /*del_mods(_modifiers);*/ \
    /*clear_mods();*/ \
    clear_keyboard(); \
    /*send_keyboard_report();*/ \
    {__VA_ARGS__} \
    /*set_mods(_modifiers);*/ \
  } while(0)



uint8_t get_tap_dance_state(qk_tap_dance_state_t *state) {
  switch(state->count) {
    case 1:
      if(state->interrupted || !state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    case 2:
      if(state->interrupted) return DOUBLE_TAP_CLR;
      if(state->pressed) return DOUBLE_HOLD;
      return DOUBLE_TAP;
    case 3:
      if(state->interrupted || !state->pressed) return TRIPLE_TAP;
      return TRIPLE_HOLD;
    case 4:
      if(state->interrupted || !state->pressed) return QUADRUPLE_TAP;
      return QUADRUPLE_HOLD;
    default:
      return 99; // magic number (TODO extend cases?)
  }
};



typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

static tap tap_dance_multitap = {
    .is_press_action = true,
    .state = 0
};

void tap_dance_multitap_reset(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = 0;
};



// on mac...
// KC_NONUS_BSLASH is ^ and LSFT(KC_NONUS_BSLASH) is °
// KC_EQUAL is ´ and LSFT(KC_EQUAL) is `
// KC_BSLASH is # and LSFT(KC_BSLASH) is '
// KC_GRAVE is < and LSFT(KC_GRAVE) is >
// X_MINUS is ß

// on windows...
// KC_NONUS_BSLASH  is < and LSFT(KC_GRAVE) is >
// KC_EQUAL is ´ and LSFT(KC_EQUAL) is `
// KC_BSLASH is # and LSFT(KC_BSLASH) is '
// KC_GRAVE is ^ and LSFT(KC_NONUS_BSLASH) is °
// X_MINUS is ß

/*
SEND_STRING(SS_DOWN(X_RALT)); // type codes on windows... expample
SEND_STRING(SS_TAP(X_KP_0));
SEND_STRING(SS_TAP(X_KP_1));
SEND_STRING(SS_TAP(X_KP_6));
SEND_STRING(SS_TAP(X_KP_3));
SEND_STRING(SS_UP(X_RALT));
*/



void kcc_a(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      SEND_STRING(SS_TAP(X_QUOTE)); // ä
      return;
    case TRIPLE_TAP:
      tap_code(KC_EQUAL); // ´ französisch-accent (hold shift for `)
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_A);
};

void kcc_s(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      SEND_STRING(SS_TAP(X_MINUS)); // ß
      return;
    case TRIPLE_TAP:
      SEND_STRING(SS_LSFT("4")); // $
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_S);
};

void kcc_d(qk_tap_dance_state_t *state, void *user_data) {
  bool holding_alt = get_mods() & MOD_MASK_ALT; //get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT);
  bool holding_shift = get_mods() & MOD_MASK_SHIFT; //get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT);
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case TRIPLE_TAP:
      if(holding_alt) {
        if(IS_QWERTZ_WINDOWS) MODELESS({tap_code16(RALT(KC_NONUS_BSLASH));});
        else tap_code16(LALT(KC_7)); // | pipe
      } else if(holding_shift) {
        if(IS_QWERTZ_WINDOWS) MODELESS({tap_code16(RALT(KC_MINUS));});
        else tap_code16(LSFT(LALT(KC_7))); // \ backslash
      } else {
        tap_code16(LSFT(KC_7)); // / forward slash
      }
      return;
    case TRIPLE_HOLD:
      if(holding_alt) {
        if(IS_QWERTZ_WINDOWS) MODELESS({tap_code16(RALT(KC_NONUS_BSLASH)); tap_code16(RALT(KC_NONUS_BSLASH));});
        else SEND_STRING(SS_LALT("77")); // | pipe
      } else if(holding_shift) {
        if(IS_QWERTZ_WINDOWS) MODELESS({tap_code16(RALT(KC_MINUS)); tap_code16(RALT(KC_MINUS));});
        else SEND_STRING(SS_LSFT(SS_LALT("77"))); // \ backslash
      } else {
        SEND_STRING(SS_LSFT("77")); // / forward slash
      }
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_D);
};

void kcc_e(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    tap_code16(LCA(KC_E)); // €
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_E);
};

void kcc_c(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    if(IS_QWERTZ_WINDOWS) {
      register_code(KC_LALT);
      tap_code(KC_KP_0);
      tap_code(KC_KP_1);
      tap_code(KC_KP_6);
      tap_code(KC_KP_9);
      unregister_code(KC_LALT);
    } else {
      SEND_STRING(SS_LALT("g")); // ©
    }
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_C);
};

void kcc_r(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    if(IS_QWERTZ_WINDOWS) {
      register_code(KC_LALT);
      tap_code(KC_KP_0);
      tap_code(KC_KP_1);
      tap_code(KC_KP_7);
      tap_code(KC_KP_4);
      unregister_code(KC_LALT);
    } else {
      SEND_STRING(SS_LALT("r")); // ®
    }
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_R);
};

void kcc_t(qk_tap_dance_state_t *state, void *user_data) {
  bool holding_shift = get_mods() & MOD_MASK_SHIFT;
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      if(holding_shift) {
        tap_code(KC_2); // "
      } else {
        if(IS_QWERTZ_WINDOWS) tap_code16(LSFT(KC_BSLASH));
        else SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_EQUAL) SS_UP(X_LALT)); // '
      }
      return;
    case TRIPLE_TAP:
      if(IS_QWERTZ_WINDOWS) {
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_1);
        tap_code(KC_KP_5);
        tap_code(KC_KP_3);
        unregister_code(KC_LALT);
      } else {
        SEND_STRING(SS_LALT(SS_LSFT("d"))); // ™
      }
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_T);
};

void kcc_f(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_7));
    else tap_code16(LALT(KC_8)); // {
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_F);
};

void kcc_g(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      tap_code16(LSFT(KC_8)); // (
      return;
    case DOUBLE_HOLD:
      if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_8));
      else tap_code16(LALT(KC_5)); // [
      return;
    case TRIPLE_TAP:
      if(IS_QWERTZ_WINDOWS) tap_code(KC_GRAVE);
      else tap_code(KC_NONUS_BSLASH); // ^
      return;
    case TRIPLE_HOLD:
      if(IS_QWERTZ_WINDOWS) {
        tap_code(KC_GRAVE);
        tap_code(KC_GRAVE);
      } else {
        tap_code(KC_NONUS_BSLASH); // ^
        tap_code(KC_NONUS_BSLASH);
      }
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_G);
};

void kcc_b(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    if(IS_QWERTZ_WINDOWS) tap_code(KC_NONUS_BSLASH);
    else SEND_STRING(SS_TAP(X_GRAVE)); // <
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_B);
};

void kcc_z(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_0));
    else SEND_STRING(SS_LALT("9")); // }
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_Y);
};

void kcc_h(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      SEND_STRING(SS_LSFT("9")); // )
      return;
    case DOUBLE_HOLD:
      if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_9));
      else SEND_STRING(SS_LALT("6")); // ]
      return;
    case TRIPLE_TAP:
      SEND_STRING(SS_TAP(X_BSLASH)); // #
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_H);
};

void kcc_j(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    if(IS_QWERTZ_WINDOWS) tap_code16(LSFT(KC_NONUS_BSLASH));
    else SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRAVE) SS_UP(X_LSFT)); // >
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_J);
};

void kcc_u(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      tap_code(KC_LBRACKET); // ü
      return;
    case TRIPLE_TAP:
      SEND_STRING(SS_LSFT("6")); // &
      return;
    case TRIPLE_HOLD:
      SEND_STRING(SS_LSFT("66")); // &&
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_U);
};

void kcc_n(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_RBRACKET));
    else SEND_STRING(SS_LALT("n")); // ~
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_N);
};

void kcc_m(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    tap_code(KC_KP_ASTERISK); // *
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_M);
};

void kcc_k(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case TRIPLE_TAP:
      tap_code16(LSFT(KC_0)); // =
      return;
    case TRIPLE_HOLD:
      tap_code16(LSFT(KC_0)); // ==
      tap_code16(LSFT(KC_0));
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_K);
};

void kcc_i(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case TRIPLE_TAP:
      tap_code(KC_KP_PLUS); // +
      return;
    case TRIPLE_HOLD:
      tap_code(KC_KP_PLUS); // ++
      tap_code(KC_KP_PLUS);
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_I);
};

void kcc_o(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  switch(tap_dance_multitap.state) {
    case SINGLE_HOLD:
      tap_code(KC_SCOLON); // ö
      return;
    case TRIPLE_TAP:
      if(IS_QWERTZ_WINDOWS) {
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_2);
        tap_code(KC_KP_1);
        tap_code(KC_KP_6);
        unregister_code(KC_LALT);
      } else {
        SEND_STRING(SS_LALT(SS_LSFT("o"))); // Ø
      }
      return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_O);
};

void kcc_l(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    if(IS_QWERTZ_WINDOWS) tap_code16(RALT(KC_Q));
    else SEND_STRING(SS_LALT("l")); // @
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_L);
};

void kcc_p(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == TRIPLE_TAP) {
    SEND_STRING(SS_LSFT("5")); // %
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_P);
};

void kcc_comma(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    tap_code16(LSFT(KC_MINUS)); // ?
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_COMMA);
};

void kcc_dot(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_multitap.state = get_tap_dance_state(state);
  if(tap_dance_multitap.state == SINGLE_HOLD) {
    tap_code16(LSFT(KC_1)); // !
    return;
  }
  for(uint8_t n = 1; n <= state->count; n++) tap_code(KC_DOT);
};



qk_tap_dance_action_t tap_dance_actions[] = {
  [KCC_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_a, tap_dance_multitap_reset),
  [KCC_S] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_s, tap_dance_multitap_reset),
  [KCC_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_e, tap_dance_multitap_reset),
  [KCC_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_d, tap_dance_multitap_reset),
  [KCC_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_c, tap_dance_multitap_reset),
  [KCC_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_r, tap_dance_multitap_reset),
  [KCC_T] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_t, tap_dance_multitap_reset),
  [KCC_F] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_f, tap_dance_multitap_reset),
  [KCC_G] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_g, tap_dance_multitap_reset),
  [KCC_B] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_b, tap_dance_multitap_reset),
  [KCC_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_z, tap_dance_multitap_reset),
  [KCC_H] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_h, tap_dance_multitap_reset),
  [KCC_J] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_j, tap_dance_multitap_reset),
  [KCC_U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_u, tap_dance_multitap_reset),
  [KCC_N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_n, tap_dance_multitap_reset),
  [KCC_M] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_m, tap_dance_multitap_reset),
  [KCC_I] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_i, tap_dance_multitap_reset),
  [KCC_K] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_k, tap_dance_multitap_reset),
  [KCC_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_o, tap_dance_multitap_reset),
  [KCC_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_l, tap_dance_multitap_reset),
  [KCC_P] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_p, tap_dance_multitap_reset),
  [KCC_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_comma, tap_dance_multitap_reset),
  [KCC_DOT]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kcc_dot, tap_dance_multitap_reset),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_Q:
      if(record->event.pressed && get_mods() & MOD_MASK_CTRL) {
        MODELESS({ // forget about current key and modifier being presses and handle manually...
          tap_code16(LALT(KC_F4)); // send Alt+F4 to emulate Cmd + Q from MacOS
        });
        return false;
      }
    default:
      return true;
  }
};



void matrix_scan_user(void) {
};
