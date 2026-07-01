#include QMK_KEYBOARD_H

// ===================== CUSTOM KEYCODES =====================
enum custom_keycodes {
    MC_DOT_SFT = SAFE_RANGE,
    MC_COMM_SPC,
};

// ===================== TAP DANCE (Multi-tap!) =====================
enum {
    TD_LEFT = 0,   // 1 тап = ←, 2+ тапа = ↓
    TD_RIGHT,      // 1 тап = →, 2+ тапа = ↑
};

void td_left_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LEFT);
    } else {
        register_code(KC_DOWN);
    }
}

void td_left_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LEFT);
    } else {
        unregister_code(KC_DOWN);
    }
}

void td_right_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_RIGHT);
    } else {
        register_code(KC_UP);
    }
}

void td_right_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_RIGHT);
    } else {
        unregister_code(KC_UP);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_left_finished, td_left_reset),
    [TD_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_right_finished, td_right_reset),
};

// ===================== COMBOS =====================
enum combos {
    COMBO_DV_HOME = 0,
    COMBO_KM_END,
};

const uint16_t PROGMEM combo_dv[] = {LCTL_T(KC_D), KC_V, COMBO_END};
const uint16_t PROGMEM combo_km[] = {LCTL_T(KC_K), KC_M, COMBO_END};

combo_t key_combos[] = {
    [COMBO_DV_HOME] = COMBO(combo_dv, KC_HOME),
    [COMBO_KM_END]  = COMBO(combo_km, KC_END),
};

// ===================== KEYMAPS (7 слоёв) =====================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // СЛОЙ 0: BASE
    [0] = LAYOUT(
        MO(6),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(6),
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        MC_DOT_SFT, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), MC_COMM_SPC,
        KC_GRV,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, RALT_T(KC_RBRC),
        LT(4,KC_ESC), LT(2,KC_SPC), LT(3,KC_TAB), LT(6,KC_BSPC),             LT(5,KC_DEL), TD(TD_LEFT), TD(TD_RIGHT), LT(1,KC_ENT)
    ),
    
    // СЛОЙ 1: SYMBOLS (чистые символы, без Mod-Tap)
    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_PERC, KC_LALT, KC_LCTL, KC_ASTR, KC_PLUS,                 KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_EXLM, KC_NO,   KC_NO,   KC_NO,   KC_UNDS,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
        KC_LPRN, KC_RPRN, KC_SLSH, KC_TRNS, KC_TRNS, KC_BSLS,                 KC_PSLS, KC_TRNS
    ),

    // СЛОЙ 2: NAV (стрелки + Home/End/PgUp/PgDn)
    [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         LCTL(LSFT(KC_Z)), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z), KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                         KC_CAPS, LSFT_T(KC_LEFT), LCTL_T(KC_DOWN), LALT_T(KC_UP), LGUI_T(KC_RGHT), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,                         KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL,                                 KC_TRNS, KC_TRNS, KC_ENT
    ),

    // СЛОЙ 3: MOUSE (чистые кнопки + SNIPING_MODE + DRAGSCROLL_MODE)
    [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   SNIPING_MODE, KC_NO,                    LCTL(LSFT(KC_Z)), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z), KC_TRNS,
        KC_NO,   MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5,                       KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   DRAGSCROLL_MODE, KC_NO,                  KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                                  KC_NO,   KC_TRNS, KC_NO
    ),

    // СЛОЙ 4: MEDIA + DPI + SLEEP/POWER
    [4] = LAYOUT(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         DPI_MOD, DPI_RMOD, S_D_MOD, S_D_RMOD, KC_SLEP, KC_PWR,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                         KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MUTE,                                KC_TRNS, KC_TRNS, KC_MSTP
    ),

    // СЛОЙ 5: SYSTEM (F-клавиши)
    [5] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   LGUI_T(KC_F5), LALT_T(KC_F6), LCTL_T(KC_F7), LSFT_T(KC_F8), KC_SCRL, KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PAUS,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_APP,  KC_SPC,  KC_TAB,  KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // СЛОЙ 6: NUMPAD + BOOT/EE_CLR
    [6] = LAYOUT(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,                       QK_BOOT, KC_NO,   EE_CLR,  KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   KC_P9,   KC_P0,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_PEQL,                       KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_PMNS,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_PDOT, KC_PCMM, KC_NO,   KC_NO,   KC_NO,                                  KC_NO,   KC_NO,   KC_NO
    )
};

// ===================== SMART PUNCTUATION (Linux Unicode Bypass) =====================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_DOT_SFT:
                // Linux Unicode: Ctrl+Shift+U, 2, e, Space (DOT + SPACE)
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_U);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                tap_code(KC_2);
                tap_code(KC_E);
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_LSFT); // Следующий символ будет заглавным
                return false;
            case MC_COMM_SPC:
                // Linux Unicode: Ctrl+Shift+U, 2, c, Space (COMMA + SPACE)
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_U);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                tap_code(KC_2);
                tap_code(KC_C);
                tap_code(KC_SPC);
                return false;
        }
    }
    return true;
}
