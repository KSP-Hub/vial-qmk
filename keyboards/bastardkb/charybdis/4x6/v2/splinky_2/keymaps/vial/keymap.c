#include QMK_KEYBOARD_H
#include "timer.h"

enum charybdis_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

// Кастомные коды для макросов (привязка в process_record_user)
enum custom_keycodes {
    MC_LCHG = QK_USER,
    MC_NBSP,
    MC_SUDO,
    MC_PRINT,
    MC_SELECT,
    MC_JOIN,
    MC_WHERE,
    MC_FROM,
    MC_LE,
    MC_GE,
    MC_APPROX,
    MC_PLUSMINUS,
    MC_RUB,
    MC_LAQUO,
    MC_RAQUO,
    MC_ELLIPSIS
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_charybdis_4x6(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LSFT,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_INS,     KC_N,    KC_M,    KC_COMM, KC_DOT,  PT_SLSH, KC_RALT,
    // ╰───────────────────────╮                              ╰─╯                              ╭───────────────────────╯
                      KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_ENT,  KC_LALT,    KC_BSPC, KC_DEL
    // ╰───────────────────────╯                              ╰─╯                              ╰───────────────────────╯
),

[LAYER_LOWER] = LAYOUT_charybdis_4x6(
         KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC, KC_P7,   KC_P8,   KC_P9,   KC_RBRC, XXXXXXX,
         XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PEQL,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_PDOT,
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, KC_P0,    XXXXXXX, XXXXXXX
),

[LAYER_RAISE] = LAYOUT_charybdis_4x6(
         KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
         KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
         KC_MPLY, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
         KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                      _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
),

[LAYER_POINTER] = LAYOUT_charybdis_4x6(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_RMOD,DPI_RMOD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
         XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
                      KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN1, KC_BTN2,    XXXXXXX, XXXXXXX
)
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, LAYER_POINTER));
    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_LCHG: SEND_STRING(SS_LALT(SS_TAP(X_SPACE))); break;
            case MC_NBSP: SEND_STRING(SS_LALT(SS_TAP(X_SPACE))); break;
            case MC_SUDO: SEND_STRING("sudo " SS_TAP(X_ENTER)); break;
            case MC_PRINT: SEND_STRING("print("); break;
            case MC_SELECT: SEND_STRING("SELECT "); break;
            case MC_JOIN: SEND_STRING("JOIN "); break;
            case MC_WHERE: SEND_STRING("WHERE "); break;
            case MC_FROM: SEND_STRING("FROM "); break;
            case MC_LE: SEND_STRING("<="); break;
            case MC_GE: SEND_STRING(">="); break;
            case MC_APPROX: SEND_STRING("~="); break;
            case MC_PLUSMINUS: SEND_STRING("+/-"); break;
            case MC_RUB: SEND_STRING("₽"); break;
            case MC_LAQUO: SEND_STRING("«"); break;
            case MC_RAQUO: SEND_STRING("»"); break;
            case MC_ELLIPSIS: SEND_STRING("…"); break;
        }
    }
    return true;
}
