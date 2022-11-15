#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum tap_dance_codes {
  DANCE_KC_1,
  DANCE_KC_2,
  DANCE_KC_3,
  DANCE_KC_4,
  DANCE_KC_5,
  DANCE_KC_MINUS,
  DANCE_KC_EQUAL,
  DANCE_KC_6,
  DANCE_KC_7,
  DANCE_KC_8,
  DANCE_KC_9,
  DANCE_KC_0,
  DANCE_KC_24,
  DANCE_KC_25,
  DANCE_KC_PGDOWN,
  DANCE_KC_PGUP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSP  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/LO|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RAISE |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtr | LAlt | LCmd | / LOWER /       \Enter \  |Space |  -_  |  =+  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRAVE,              TD(DANCE_KC_1), TD(DANCE_KC_2), TD(DANCE_KC_3),TD(DANCE_KC_4), TD(DANCE_KC_5),              TD(DANCE_KC_6), TD(DANCE_KC_7), TD(DANCE_KC_8), TD(DANCE_KC_9), TD(DANCE_KC_0), KC_BSPACE,
  KC_TAB,                KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  LT(_LOWER, KC_ESCAPE), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,               KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,     KC_LBRC,                             KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_RAISE),
                                          KC_LCTRL, KC_LALT, KC_LGUI, TG(_LOWER),                          KC_ENT, KC_SPC,  TD(DANCE_KC_MINUS), TD(DANCE_KC_EQUAL)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   -  |                    |   =  | PGUP |   I  |   O  |   P  |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/LO|   A  |   S  | PGDN |   F  |   G  |-------.    ,-------| Left | Down |  Up  |Right |   :  |  "   |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   <  |   >  |   ?  |RAISE |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtr | LAlt | LCmd | / QWERTY/       \Enter \  |Space |   _  |   +  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
        KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                         KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_KC_MINUS),                              TD(DANCE_KC_EQUAL), TD(DANCE_KC_PGUP), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PIPE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_KC_PGDOWN), KC_TRANSPARENT, KC_TRANSPARENT,                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_COLON,  KC_DQUO,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR             ,KC_RCBR, KC_TRANSPARENT, KC_TRANSPARENT, KC_LT, KC_GT, KC_QUES, KC_TRANSPARENT,
                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(_QWERTY)         ,KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS, KC_PLUS
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
*  | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/LO|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |TR_PRE|TR_NEX|   /  |RAISE |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  | MUTE |VOL DN|VOL UP|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                                       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(_QWERTY),                                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtr | LAlt | LCmd | / LOWER /       \Enter \  |Space |  -_  |  =+  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                             KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[16];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void ON_DANCE_KC_1(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_1_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_1_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if(state->count > 3) {
        tap_code16(KC_1);
    }
}

void DANCE_KC_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_1); break;
        case SINGLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_1); register_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_1); register_code16(KC_1);
    }
}

void DANCE_KC_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_1); break;
        case SINGLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_1); break;
    }
    dance_state[0].step = 0;
}
void ON_DANCE_KC_2(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_2_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_2_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if(state->count > 3) {
        tap_code16(KC_2);
    }
}

void DANCE_KC_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_2); break;
        case SINGLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_2); register_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_2); register_code16(KC_2);
    }
}

void DANCE_KC_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_2); break;
        case SINGLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_2); break;
    }
    dance_state[1].step = 0;
}
void ON_DANCE_KC_3(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_3_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_3_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if(state->count > 3) {
        tap_code16(KC_3);
    }
}

void DANCE_KC_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_3); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_3); register_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_3); register_code16(KC_3);
    }
}

void DANCE_KC_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_3); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_3); break;
    }
    dance_state[2].step = 0;
}
void ON_DANCE_KC_4(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_4_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_4_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void DANCE_KC_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case SINGLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void DANCE_KC_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case SINGLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state[3].step = 0;
}
void ON_DANCE_KC_5(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_5_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_5_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void DANCE_KC_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void DANCE_KC_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[4].step = 0;
}

void ON_DANCE_KB_6(qk_tap_dance_state_t *state, void *user_data);
void dance_kb_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_kb_6_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KB_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_kb_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_kb_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[9].step = 0;
}
void ON_DANCE_KC_7(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_7_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_7_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if(state->count > 3) {
        tap_code16(KC_7);
    }
}

void DANCE_KC_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_7); register_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_7); register_code16(KC_7);
    }
}

void DANCE_KC_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_7); break;
    }
    dance_state[10].step = 0;
}
void ON_DANCE_KC_8(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_8_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_8_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

void DANCE_KC_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_8); break;
        case SINGLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_8); register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_8); register_code16(KC_8);
    }
}

void DANCE_KC_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_8); break;
        case SINGLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_8); break;
    }
    dance_state[11].step = 0;
}
void ON_DANCE_KC_9(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_9_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_9_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if(state->count > 3) {
        tap_code16(KC_9);
    }
}

void DANCE_KC_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_9); register_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_9); register_code16(KC_9);
    }
}

void DANCE_KC_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_9); break;
    }
    dance_state[12].step = 0;
}
void ON_DANCE_KC_0(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_0_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_0_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void DANCE_KC_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_0); register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void DANCE_KC_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state[13].step = 0;
}
void ON_DANCE_KC_24(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_24_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_24_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_24(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RBRACKET);
        tap_code16(KC_RBRACKET);
        tap_code16(KC_RBRACKET);
    }
    if(state->count > 3) {
        tap_code16(KC_RBRACKET);
    }
}

void DANCE_KC_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_RBRACKET); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); register_code16(KC_RBRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RBRACKET); register_code16(KC_RBRACKET);
    }
}

void DANCE_KC_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_RBRACKET); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RBRACKET); break;
    }
    dance_state[14].step = 0;
}
void ON_DANCE_KC_25(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_25_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_25_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_25(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLASH);
    }
}

void DANCE_KC_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_BSLASH); break;
        case SINGLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); register_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLASH); register_code16(KC_BSLASH);
    }
}

void DANCE_KC_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_BSLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_PIPE); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLASH); break;
    }
    dance_state[15].step = 0;
}

void ON_DANCE_KC_MINUS(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_MINUS_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_MINUS_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_MINUS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void DANCE_KC_MINUS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void DANCE_KC_MINUS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[5].step = 0;
}
void ON_DANCE_KC_EQUAL(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_EQUAL_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_EQUAL_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_EQUAL(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void DANCE_KC_EQUAL_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void DANCE_KC_EQUAL_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[8].step = 0;
}

void ON_DANCE_KC_PGDOWN(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_PGDOWN_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_PGDOWN_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_PGDOWN(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDOWN);
    }
}

void DANCE_KC_PGDOWN_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); register_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDOWN); register_code16(KC_PGDOWN);
    }
}

void DANCE_KC_PGDOWN_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
    }
    dance_state[0].step = 0;
}

void ON_DANCE_KC_PGUP(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_PGUP_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_KC_PGUP_reset(qk_tap_dance_state_t *state, void *user_data);

void ON_DANCE_KC_PGUP(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
    }
    if(state->count > 3) {
        tap_code16(KC_PGUP);
    }
}

void DANCE_KC_PGUP_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_PGUP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); register_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGUP); register_code16(KC_PGUP);
    }
}

void DANCE_KC_PGUP_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_PGUP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGUP); break;
    }
    dance_state[1].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_KC_1] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_1, DANCE_KC_1_finished, DANCE_KC_1_reset),
        [DANCE_KC_2] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_2, DANCE_KC_2_finished, DANCE_KC_2_reset),
        [DANCE_KC_3] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_3, DANCE_KC_3_finished, DANCE_KC_3_reset),
        [DANCE_KC_4] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_4, DANCE_KC_4_finished, DANCE_KC_4_reset),
        [DANCE_KC_5] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_5, DANCE_KC_5_finished, DANCE_KC_5_reset),
        [DANCE_KC_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_MINUS, DANCE_KC_MINUS_finished, DANCE_KC_MINUS_reset),
        [DANCE_KC_EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_EQUAL, DANCE_KC_EQUAL_finished, DANCE_KC_EQUAL_reset),

        [DANCE_KC_6] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KB_6, dance_kb_6_finished, dance_kb_6_reset),
        [DANCE_KC_7] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_7, DANCE_KC_7_finished, DANCE_KC_7_reset),
        [DANCE_KC_8] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_8, DANCE_KC_8_finished, DANCE_KC_8_reset),
        [DANCE_KC_9] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_9, DANCE_KC_9_finished, DANCE_KC_9_reset),
        [DANCE_KC_0] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_0, DANCE_KC_0_finished, DANCE_KC_0_reset),
        [DANCE_KC_24] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_24, DANCE_KC_24_finished, DANCE_KC_24_reset),
        [DANCE_KC_25] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_25, DANCE_KC_25_finished, DANCE_KC_25_reset),
        [DANCE_KC_PGDOWN] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_PGDOWN, DANCE_KC_PGDOWN_finished, DANCE_KC_PGDOWN_reset),
        [DANCE_KC_PGUP] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE_KC_PGUP, DANCE_KC_PGUP_finished, DANCE_KC_PGUP_reset),
};
