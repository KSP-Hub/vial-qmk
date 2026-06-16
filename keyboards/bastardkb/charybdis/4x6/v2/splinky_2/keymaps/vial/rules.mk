cd ~/vial-qmk/keyboards/bastardkb/charybdis/4x6/v2/splinky_2/keymaps/vial/

cat > rules.mk << 'EOF'
VIA_ENABLE = yes
VIAL_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
RGB_MATRIX_ENABLE = no
LTO_ENABLE = yes
MACRO_ENABLE = yes
# Disable unused features to save flash & avoid conflicts
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
QMK_SETTINGS = no
SPACE_CADET_ENABLE = no
KEY_OVERRIDE_ENABLE = no
EOF
