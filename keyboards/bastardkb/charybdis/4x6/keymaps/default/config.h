#pragma once

/* ==========================================
   PMW3360 Trackball SPI Configuration (RP2040)
   ========================================== */
// Явное назначение пинов SPI0 для RP2040 Pro Micro
#define SPI_SCK_PIN  GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

// Chip Select пин сенсора PMW3360
#define POINTING_DEVICE_CS_PIN GP21

// Опционально: поворот оси трекбола (раскомментируйте, если курсор движется не туда)
// #define POINTING_DEVICE_ROTATION_90
// #define POINTING_DEVICE_ROTATION_180
// #define POINTING_DEVICE_ROTATION_270

// Опционально: базовый CPI (по умолчанию 1600)
// #define PMW3360_CPI 1600

/* ==========================================
   Отключение RGB (если потребуется позже)
   ========================================== */
// #undef RGB_MATRIX_ENABLE
// #define RGB_MATRIX_ENABLE FALSE
