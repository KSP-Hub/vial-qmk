#include QMK_KEYBOARD_H

// ===================== ОБЪЯВЛЕНИЕ КАСТОМНЫХ МАКРОСОВ =====================
enum custom_keycodes {
    MC_DOT_SFT = SAFE_RANGE,
    MC_COMM_SPC
};

// ===================== СЛОИ =====================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MO(6),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(6),
        KC_SLSH,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        MC_DOT_SFT, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), MC_COMM_SPC,
        LCTL_T(KC_GRV), KC_Z, KC_X, KC_C, KC_V, KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, RALT_T(KC_RBRC),
        LT(4,KC_ESC), LT(2,KC_SPC), LT(3,KC_TAB), LT(6,KC_BSPC),             LT(5,KC_DEL), TD(0), TD(1), LT(1,KC_ENT)
    ),
    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_PERC, KC_LALT, KC_LCTL, KC_ASTR, KC_PLUS,                 KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_EXLM, KC_NO,   KC_NO,   KC_NO,   KC_UNDS,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
        KC_LPRN, KC_RPRN, KC_PSLS, KC_NO,                                KC_NO, KC_NO, KC_BSLS, KC_NO
    ),
    [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         LCTL(LSFT(KC_Z)), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z), KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                         KC_CAPS, LSFT_T(KC_LEFT), LCTL_T(KC_DOWN), LALT_T(KC_UP), LGUI_T(KC_RGHT), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,                         KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL,                                 KC_TRNS, KC_TRNS, KC_ENT
    ),
    [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   SNIPING_MODE, KC_NO,                    LCTL(LSFT(KC_Z)), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z), KC_TRNS,
        KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,                       KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   DRAGSCROLL_MODE, KC_NO,                  KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                                  KC_NO,   KC_TRNS, KC_NO
    ),
    [4] = LAYOUT(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         DPI_MOD, DPI_RMOD, S_D_MOD, S_D_RMOD, KC_SLEP, KC_PWR,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                         KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MUTE,                                KC_TRNS, KC_TRNS, KC_MSTP
    ),
    [5] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   LGUI_T(KC_F5), LALT_T(KC_F6), LCTL_T(KC_F7), LSFT_T(KC_F8), KC_SCRL, KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PAUS,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_APP,  KC_SPC,  KC_TAB,  KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [6] = LAYOUT(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,                       QK_BOOT, KC_NO,   EE_CLR,  KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   KC_9,   KC_0,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_5,   KC_6,   KC_7,   KC_8,   KC_EQL,                       KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO,   KC_1,   KC_2,   KC_3,   KC_4,   KC_MINS,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,   KC_NO,                                           KC_NO,  KC_NO,   KC_NO,   KC_NO
    )
};

// ===================== ЛОГИКА МАКРОСОВ (ИСПРАВЛЕННАЯ) =====================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_DOT_SFT:
                // Явное удержание KC_SLSH с задержкой 100ms
                register_code(KC_SLSH);
                wait_ms(100);
                unregister_code(KC_SLSH);
                wait_ms(50);  // Задержка после отпускания для обработки системой
                return false;
            case MC_COMM_SPC:
                // Используем weak_mods для корректного добавления Shift
                add_weak_mods(MOD_BIT(KC_LSFT));
                register_code(KC_SLSH);
                wait_ms(100);
                unregister_code(KC_SLSH);
                wait_ms(50);
                del_weak_mods(MOD_BIT(KC_LSFT));
                return false;
        }
    }
    return true;
}

// ===================== ТРЕКБОЛ (Инверсия X) =====================
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.x = -mouse_report.x;
    return mouse_report;
}
