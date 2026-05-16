#pragma once

/* ==========================================================
   Переопределение пинов под RP2040 Pro Micro + Elite-C Holder 2.1
   ========================================================== */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26, GP12 }
#define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8, GP9 }

/* SPI для PMW3360 (стандарт BKB RP2040) */
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

/* Отключение RGB (экономит место и убирает конфликты) */
#undef RGB_MATRIX_ENABLE
#define RGB_MATRIX_ENABLE FALSE

/* Vial / VIA настройки */
#define VIA_ENABLE
#define VIAL_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define VIAL_KEYBOARD_UID { 0x6D, 0xA5, 0xCD, 0x8D, 0xC7, 0x3D, 0x7B, 0xA8 }
#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }
#define VIALRGB_NO_DIRECT
#define NO_ACTION_ONESHOT
#define TAPPING_TERM 200
