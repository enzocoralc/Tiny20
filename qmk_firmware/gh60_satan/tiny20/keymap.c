#include QMK_KEYBOARD_H
#include "action_layer.h"

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  ALT_TAB,
  CTRL_TAB,
  ALT_F4,
  CTRL_F4,
  CTRL_V,
  SC_ST
};

// Fillers to make layering more clear
#define ____ KC_TRNS
#define MT_CTL_GUI LCTL_T(KC_NO)
#define MT_SFT_ALT LSFT_T(KC_NO)
#define LT_S1 LT(1,KC_SPC)
#define LT_E2 LT(2,KC_ENT)

// alt + tab

bool is_alt_tab_active = false;
bool is_ctrl_tab_active = false;
uint16_t alt_tab_timer = 0;
uint16_t ctrl_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(is_alt_tab_active && record->event.pressed && keycode!=ALT_TAB && keycode!=KC_LALT && keycode!=KC_LSFT && keycode!=KC_RSFT)
  {
        unregister_code(KC_LALT);
        is_alt_tab_active=false;
  }
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case CTRL_TAB:
      if (record->event.pressed) {
        if (!is_ctrl_tab_active) {
          is_ctrl_tab_active = true;
          register_code(KC_LCTL);
        }
        ctrl_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ALT_F4:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_F4);
      } else {
        unregister_code(KC_F4);
        unregister_code(KC_LALT);
      }
      break;
    case CTRL_F4:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_F4);
      } else {
        unregister_code(KC_F4);
        unregister_code(KC_LCTL);
      }
      break;
      case CTRL_V:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_V);
      } else {
        unregister_code(KC_V);
        unregister_code(KC_LCTL);
      }
      break;
      case SC_ST:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_S);
      } else {
        register_code(KC_S);
        register_code(KC_LSFT);
        register_code(KC_LGUI);
      }
      break;
       // Sticky mods
      case MT_CTL_GUI:
        if (record->tap.count && record->event.pressed) {
            add_oneshot_mods(MOD_LGUI);
            return false;
        }
        break;
      case MT_SFT_ALT:
        if (record->tap.count && record->event.pressed) {
            add_oneshot_mods(MOD_RALT);
            return false;
        }
        break;
  }
  
  return true;

}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_ctrl_tab_active) {
    if (timer_elapsed(ctrl_tab_timer) > 500) {
      unregister_code(KC_LCTL);
      is_ctrl_tab_active = false;
    }
  }
}



// COMBOS #20

enum combos {
  AS_Q,
  SH_W,
  HT_B,
  ZX_Y,
  XC_M,
  CV_G,
  NE_J,
  EO_F,
  OI_P,
  RD_K,
  DU_COM,
  UL_DOT,
  SPEN_L3,
  F4F5_F7,
  F5F6_F8,
  F1F2_F9,
  F2F3_F10,
  F2F5_F11,
  F3F6_F12,
  RE_MED
};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sh_combo[] = {KC_S, KC_H, COMBO_END};
const uint16_t PROGMEM ht_combo[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM eo_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM oi_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM rd_combo[] = {KC_R, KC_D, COMBO_END};
const uint16_t PROGMEM du_combo[] = {KC_D, KC_U, COMBO_END};
const uint16_t PROGMEM ul_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM spen_combo[] = {LT_S1, LT_E2, COMBO_END};
const uint16_t PROGMEM f4f5_combo[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM f5f6_combo[] = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM f1f2_combo[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM f2f3_combo[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM f2f5_combo[] = {KC_F2, KC_F5, COMBO_END};
const uint16_t PROGMEM f3f6_combo[] = {KC_F3, KC_F6, COMBO_END};
const uint16_t PROGMEM re_combo[] = {KC_R, KC_E, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [AS_Q] = COMBO(as_combo, KC_Q),
  [SH_W] = COMBO(sh_combo, KC_W),
  [HT_B] = COMBO(ht_combo, KC_B),
  [ZX_Y] = COMBO(zx_combo, KC_Y),
  [XC_M] = COMBO(xc_combo, KC_M),
  [CV_G] = COMBO(cv_combo, KC_G),
  [NE_J] = COMBO(ne_combo, KC_J),
  [EO_F] = COMBO(eo_combo, KC_F),
  [OI_P] = COMBO(oi_combo, KC_P),
  [RD_K] = COMBO(rd_combo, KC_K),
  [DU_COM] = COMBO(du_combo, KC_COMM),
  [UL_DOT] = COMBO(ul_combo, KC_DOT),
  [SPEN_L3] = COMBO(spen_combo, OSL(3)),
  [F4F5_F7] = COMBO(f4f5_combo, KC_F7),
  [F5F6_F8] = COMBO(f5f6_combo, KC_F8),
  [F1F2_F9] = COMBO(f1f2_combo, KC_F9),
  [F2F3_F10] = COMBO(f2f3_combo, KC_F10),
  [F2F5_F11] = COMBO(f2f5_combo, KC_F11),
  [F3F6_F12] = COMBO(f3f6_combo, KC_F12),
  [RE_MED] = COMBO(re_combo, DF(4))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_60_ansi(____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                             ____, KC_A, KC_S, KC_H, KC_T, ____, ____, ____, KC_N, KC_E, KC_O, KC_I, ____, ____,
                             ____, KC_Z, KC_X, KC_C, KC_V, ____, ____, ____, KC_R, KC_D, KC_U, KC_L, ____,
                             ____, ____, ____, MT_CTL_GUI, LT_S1, ____, ____, LT_E2, MT_SFT_ALT, ____, ____, ____,
                             ____, ____, ____, ____, ____, ____, ____, ____),

        [1] = LAYOUT_60_ansi(____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                             ____, KC_ESC, ALT_TAB, CTRL_TAB, KC_9, ____, ____, ____, KC_5, KC_6, KC_7, KC_8, ____, ____,
                             ____, KC_TAB, ALT_F4,  CTRL_F4,  KC_0, ____, ____, ____, KC_1, KC_2, KC_3, KC_4, ____,
                             ____, ____, ____, MT_CTL_GUI, LT_S1, ____, ____, LT_E2, MT_SFT_ALT, ____, ____, ____,
                             ____, ____, ____, ____, ____, ____, ____, ____),

        [2] = LAYOUT_60_ansi(____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                             ____, KC_F4, KC_F5, KC_F6, KC_DEL, ____, ____, ____, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ____, ____,
                             ____, KC_F1, KC_F2, KC_F3, KC_BSPC, ____, ____, ____, KC_HOME, KC_PGUP, KC_PGDN, KC_END, ____,
                             ____, ____, ____, MT_CTL_GUI, LT_S1, ____, ____, LT_E2, MT_SFT_ALT, ____, ____, ____,
                             ____, ____, ____, ____, ____, ____, ____, ____),

        [3] = LAYOUT_60_ansi(____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                             ____, KC_AT, KC_HASH, KC_PLUS, KC_EQL, ____, ____, ____, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, ____, ____,
                             ____, KC_GRV, KC_EXLM, KC_MINS, KC_UNDS, ____, ____, ____, KC_COLN, KC_SCLN, KC_QUOT, KC_SLSH, ____,
                             ____, ____, ____, MT_CTL_GUI, LT_S1, ____, ____, LT_E2, MT_SFT_ALT, ____, ____, ____,
                             ____, ____, ____, ____, ____, ____, ____, ____),

        [4] = LAYOUT_60_ansi(____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                             ____, SC_ST, KC_MPLY, KC_VOLU, DF(0), ____, ____, ____, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ____, ____,
                             ____, KC_MPRV, KC_MUTE, KC_VOLD, KC_MNXT, ____, ____, ____, KC_BTN4, KC_WH_D, KC_WH_U, KC_BTN5, ____,
                             ____, ____, ____, MT_CTL_GUI, KC_BTN3, ____, ____, KC_BTN1, KC_BTN2, ____, ____, ____,
                             ____, ____, ____, ____, ____, ____, ____, ____)

};
