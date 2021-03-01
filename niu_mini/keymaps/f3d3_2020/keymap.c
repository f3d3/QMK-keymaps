#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_LSFT_CAPS,
	TD_WIN,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS), // Tap once for Shift, twice for Caps Lock
	[TD_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)), // Tap once for Win, twice for opening Explorer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |LSh+CL|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |Layer1| PrScr| Space| Media|Layer2| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_ortho_4x12(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        TD(TD_LSFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, TD(TD_WIN), KC_LALT, KC_PSCR, MO(1), KC_SPC, KC_MPLY,MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |  [   |   ]  |   =  |   `  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |   \  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |Layer3| Prev | Vol- | Vol+ | Next |
     * `---------------------------------------------------------  --------------------------'
     */
    [1] = LAYOUT_ortho_4x12(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_EQL,  KC_GRV,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_MINS,
        _______, _______, _______, _______, _______, _______, _______, MO(3),   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    ),
	
    /* Layer 2 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |r_TOG |r_Mode|r_Hue+|r_Hue-|r_Sat+|r_Sat-|r_Bri+|r_Bri-|      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [2] = LAYOUT_ortho_4x12(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	/* Layer 3
     * ,-----------------------------------------------------------------------------------.
     * | Power|      | Wake |      |      |      |      |      |   7  |   8  |   9  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      | Sleep|      |      |      |      |      |   4  |   5  |   6  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |Tog(4)|   1  |   2  |   3  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |   0  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [3] = LAYOUT_ortho_4x12(
        KC_PWR,  _______, KC_WAKE, _______, RESET,   _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______,
        _______, _______, KC_SLEP, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______,
        _______, _______, _______, _______, _______, _______, _______, TO(4),   KC_KP_1, KC_KP_2, KC_KP_3, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______
    ),
	
	/* Layer 4
     * ,-----------------------------------------------------------------------------------.
     * |      |      |MOUSEU|      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |MOUSEL|MOUSED|MOUSER|      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |CLICKL|CLICKR|      |      |Tog(0)|      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |WHEELL|WHEELD|WHEELU|WHEELR|
     * `-----------------------------------------------------------------------------------'
     */
    [4] = LAYOUT_ortho_4x12(
        _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, TO(0),   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
    )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    } else {

    }

}
