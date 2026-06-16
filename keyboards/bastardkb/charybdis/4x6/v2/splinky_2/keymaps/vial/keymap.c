cat > keymap.c << 'EOF'
#include QMK_KEYBOARD_H
#include "timer.h"

enum charybdis_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_EMOJI,
    LAYER_SYSTEM
};

enum custom_keycodes {
    MC_DOT_SFT = QK_USER,
    MC_COMM_SPC,
    MC_PILCROW, MC_COPYR, MC_REGISTERED, MC_SECTION, MC_TRADE, MC_ELLIPSIS,
    MC_PI, MC_SUM, MC_SIGMA, MC_INFINITY, MC_DEGREE,
    MC_APPROXIMATE, MC_LESS_EQUAL, MC_GREATER_EQUAL,
    MC_SQUARE_ROOT, MC_INTEGRAL, MC_IDENTICAL,
    MC_NOT, MC_NOT_EQUAL, MC_DIVIDE, MC_MULTIPLY, MC_PLUS_MINUS,
    MC_EMDASH, MC_ENDASH, MC_LAQUO, MC_RAQUO, MC_LDQUO, MC_RDQUO,
    MC_NUMERO, MC_CHECK, MC_WARN,
    EMOJI_WARN, EMOJI_QUEST, EMOJI_MAIL, EMOJI_PHONE, EMOJI_FOLDER,
    ARROW_L, ARROW_D, ARROW_U, ARROW_R, EM_DASH,
    EMOJI_CHECK, EMOJI_CROSS, EMOJI_LINK, EMOJI_BOLT, EMOJI_STAR,
    MC_TARGET, EMOJI_THUMB, EMOJI_FLEX, MC_BULB, MC_FIRE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_BASE] = LAYOUT_charybdis_4x6(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(5),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LT(4,KC_LBRC),
    MC_DOT_SFT, KC_A, KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MC_COMM_SPC,
    LSFT(KC_LCTL), LSFT_T(KC_Z), LCTL_T(KC_X), KC_C, KC_V, KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT,  LALT_T(KC_QUOT), RALT_T(KC_RBRC),
    LGUI(KC_SPC), MO(2), LT(3,KC_BSPC), LSFT_T(KC_SPC), LCTL_T(KC_DEL), MO(1), LALT_T(KC_ENT), KC_LGUI
),

[LAYER_SYMBOLS] = LAYOUT_charybdis_4x6(
    MC_PILCROW, MC_COPYR, MC_REGISTERED, MC_SECTION, MC_TRADE, MC_ELLIPSIS, MC_PI, MC_SUM, MC_SIGMA, MC_INFINITY, MC_DEGREE, KC_TRNS,
    KC_CAPS,    KC_GRV,   MC_APPROXIMATE,KC_NO,      KC_NO,    KC_NO,       MC_LESS_EQUAL, KC_SLSH, KC_BSLS, KC_MINS, MC_EMDASH, MC_ENDASH,
    MC_LAQUO,   MC_RAQUO, MC_LDQUO,      MC_RDQUO,   KC_NO,    KC_NO,       MC_GREATER_EQUAL, MC_SQUARE_ROOT, MC_INTEGRAL, MC_IDENTICAL, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_NO,    TG(1),         KC_NO,      KC_NO,    MC_NOT,      KC_EQL, MC_NOT_EQUAL, MC_DIVIDE, MC_MULTIPLY, MC_PLUS_MINUS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[LAYER_NAV] = LAYOUT_charybdis_4x6(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_NO,   KC_SCRL, KC_PSCR, KC_INS,  KC_NO,      KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F12,
    KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, LCTL(LSFT(KC_Z)), TG(2), KC_NO, KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[LAYER_MOUSE] = LAYOUT_charybdis_4x6(
    KC_ESC,  KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_NO,      KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_SLEP, KC_PWR,
    KC_TRNS, ANY(DPI_MOD), ANY(DPI_RMOD), KC_NO,   ANY(S_D_MOD), ANY(S_D_RMOD),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
    ANY(DRGSCRL), MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, ANY(SNIPING),    KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS,
    KC_TRNS, MS_BTN4, TG(3),   KC_NO,   MS_BTN5, KC_NO,      KC_NO,   MS_BTN1, MS_BTN3, KC_NO,   MS_BTN2, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[LAYER_EMOJI] = LAYOUT_charybdis_4x6(
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   MC_CHECK,KC_NO,   KC_NO,   KC_NO,   MC_NUMERO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      MC_WARN, EMOJI_WARN, EMOJI_QUEST, EMOJI_MAIL, EMOJI_PHONE, EMOJI_FOLDER,
    KC_TRNS, ARROW_L, ARROW_D, ARROW_U, ARROW_R, KC_NO,      EM_DASH, EMOJI_CHECK, EMOJI_CROSS, EMOJI_LINK, EMOJI_BOLT, EMOJI_STAR,
    KC_TRNS, KC_NO,   TG(4),   KC_NO,   KC_NO,   KC_NO,      MC_TARGET, EMOJI_THUMB, EMOJI_FLEX, KC_NO, MC_BULB, MC_FIRE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[LAYER_SYSTEM] = LAYOUT_charybdis_4x6(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,     QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   TG(5),   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
)

};

#ifdef POINTING_DEVICE_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, LAYER_MOUSE));
    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_DOT_SFT:    SEND_STRING(". "); set_oneshot_mods(MOD_LSFT); return false;
            case MC_COMM_SPC:   SEND_STRING(", "); return false;
            case MC_PILCROW:    SEND_STRING("¶"); return false;
            case MC_COPYR:      SEND_STRING("©"); return false;
            case MC_REGISTERED: SEND_STRING("®"); return false;
            case MC_SECTION:    SEND_STRING("§"); return false;
            case MC_TRADE:      SEND_STRING("™"); return false;
            case MC_ELLIPSIS:   SEND_STRING("…"); return false;
            case MC_PI:         SEND_STRING("π"); return false;
            case MC_SUM:        SEND_STRING("Σ"); return false;
            case MC_SIGMA:      SEND_STRING("σ"); return false;
            case MC_INFINITY:   SEND_STRING("∞"); return false;
            case MC_DEGREE:     SEND_STRING("°"); return false;
            case MC_APPROXIMATE:SEND_STRING("≈"); return false;
            case MC_LESS_EQUAL: SEND_STRING("≤"); return false;
            case MC_GREATER_EQUAL: SEND_STRING("≥"); return false;
            case MC_SQUARE_ROOT: SEND_STRING("√"); return false;
            case MC_INTEGRAL:   SEND_STRING("∫"); return false;
            case MC_IDENTICAL:  SEND_STRING("≡"); return false;
            case MC_NOT:        SEND_STRING("¬"); return false;
            case MC_NOT_EQUAL:  SEND_STRING("≠"); return false;
            case MC_DIVIDE:     SEND_STRING("÷"); return false;
            case MC_MULTIPLY:   SEND_STRING("×"); return false;
            case MC_PLUS_MINUS: SEND_STRING("±"); return false;
            case MC_EMDASH:     SEND_STRING("—"); return false;
            case MC_ENDASH:     SEND_STRING("–"); return false;
            case MC_LAQUO:      SEND_STRING("«"); return false;
            case MC_RAQUO:      SEND_STRING("»"); return false;
            case MC_LDQUO:      SEND_STRING("""); return false;
            case MC_RDQUO:      SEND_STRING("""); return false;
            case MC_NUMERO:     SEND_STRING("№"); return false;
            case MC_CHECK:      SEND_STRING("✓"); return false;
            case MC_WARN:       SEND_STRING("⚠"); return false;
            case EMOJI_WARN:    SEND_STRING("⚠️"); return false;
            case EMOJI_QUEST:   SEND_STRING(""); return false;
            case EMOJI_MAIL:    SEND_STRING("📧"); return false;
            case EMOJI_PHONE:   SEND_STRING("📞"); return false;
            case EMOJI_FOLDER:  SEND_STRING(""); return false;
            case ARROW_L:       SEND_STRING("←"); return false;
            case ARROW_D:       SEND_STRING("↓"); return false;
            case ARROW_U:       SEND_STRING("↑"); return false;
            case ARROW_R:       SEND_STRING("→"); return false;
            case EM_DASH:       SEND_STRING("—"); return false;
            case EMOJI_CHECK:   SEND_STRING("✅"); return false;
            case EMOJI_CROSS:   SEND_STRING("❌"); return false;
            case EMOJI_LINK:    SEND_STRING("🔗"); return false;
            case EMOJI_BOLT:    SEND_STRING(""); return false;
            case EMOJI_STAR:    SEND_STRING("⭐"); return false;
            case MC_TARGET:     SEND_STRING(""); return false;
            case EMOJI_THUMB:   SEND_STRING("👍"); return false;
            case EMOJI_FLEX:    SEND_STRING("💪"); return false;
            case MC_BULB:       SEND_STRING("💡"); return false;
            case MC_FIRE:       SEND_STRING("🔥"); return false;
        }
    }
    return true;
}
EOF
