/* Copyright 2019 Thomas Baart
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

uint8_t mod_state;

enum layers {
    _WIN = 0,
    _LINUX,
    _NUMPAD,
    _GW2,
    _RGB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT(
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_LINUX] = LAYOUT(
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX),

    
    [_NUMPAD] = LAYOUT(
                 XXXXXXX,     KC_0,   KC_DOT,
                    KC_7,     KC_8,     KC_9,
                    KC_4,     KC_5,     KC_6,
                    KC_1,     KC_2,     KC_3),
  
    [_GW2] = LAYOUT(
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_RGB] = LAYOUT(
                 XXXXXXX,  RGB_MOD, RGB_RMOD,
                 RGB_TOG,  RGB_SAI,  RGB_SAD,
                 XXXXXXX,  RGB_HUI,  RGB_HUD,
                 XXXXXXX,  RGB_VAI,  RGB_VAD),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_status(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
      case _WIN:
          oled_write_P(PSTR("windows\n"), false);
          break;
      case _LINUX:
          oled_write_P(PSTR("linux\n"), false);
          break;
      case _NUMPAD:
          oled_write_P(PSTR("numpad\n"), false);
          break;
      case _GW2:
          oled_write_P(PSTR("gw2\n"), false);
          break;
      case _RGB:
          oled_write_P(PSTR("rgb\n"), false);
          break;
      default:
          oled_write_P(PSTR("undefined\n"), false);
  }
}

void oled_task_user(void) {
    render_status();
}
#endif

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

#ifdef ENCODER_ENABLE
uint8_t selected_layer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
		switch (index) {
			case 0:
			if (!clockwise && selected_layer  < 6) {
				selected_layer ++;
			} else if (clockwise && selected_layer  > 0){
				selected_layer --;
			}
			layer_clear();
			layer_on(selected_layer);
		}
  }
}
#endif
