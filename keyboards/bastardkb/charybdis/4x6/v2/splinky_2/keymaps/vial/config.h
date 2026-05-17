#pragma once

/* SPI для PMW3360 (пины, на которых трекбол уже заработал) */
#undef SPI_DRIVER
#undef SPI_SCK_PIN
#undef SPI_MOSI_PIN
#undef SPI_MISO_PIN
#undef POINTING_DEVICE_CS_PIN
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define POINTING_DEVICE_CS_PIN GP16

/* Vial / VIA настройки */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define VIAL_KEYBOARD_UID { 0x6D, 0xA5, 0xCD, 0x8D, 0xC7, 0x3D, 0x7B, 0xA8 }
#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }
#define VIALRGB_NO_DIRECT
#define NO_ACTION_ONESHOT
#define TAPPING_TERM 200

/* ==========================================================
   Fix: align matrix pins with official BKB Splinktegrated / Elite-C Holder 2.1 standard
   (vial-qmk info.json incorrectly uses GP15 for C3 instead of GP21)
   ========================================================== */
#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_COL_PINS { GP27, GP28, GP21, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP29, GP26, GP5, GP4, GP9 }
