#pragma once
/* ==========================================================
⛔ WORKING PINS - DO NOT MODIFY
RP2040 Pro Micro + Elite-C Holder 2.1 + PMW3360
========================================================== */
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

#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_COL_PINS { GP27, GP28, GP21, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP29, GP26, GP5, GP4, GP9 }

/* Vial / VIA Configuration */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6  // <-- ИСПРАВЛЕНО: было 4, стало 6
#define VIAL_KEYBOARD_UID { 0x6D, 0xA5, 0xCD, 0x8D, 0xC7, 0x3D, 0x7B, 0xA8 }
#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }
#define VIALRGB_NO_DIRECT

// УБРАНО: #define NO_ACTION_ONESHOT (иначе умная точка не сработает)
#define TAPPING_TERM 200

/* Charybdis Trackball Features */
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER
