/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

// Use for debugging with QMK Console
// #include "print.h"

// OLED animation
#include "lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _VISIBILITY,
    _MODE_SNAP,
    _FIND1,
    _FIND2,
    _FOUR,
    _FIVE,
    _SIX,
    _RGB,
};

// Tap Dance declarations
enum {
    // Keyboard Layers
    TD_L0_L4,
    TD_L1_L5,
    TD_L2_L6,
    TD_L3_L7,
    // PCB Layers
    TD_L01_VIZ,
    TD_L02_VIZ,
    TD_L03_VIZ,
    TD_L04_VIZ,
    TD_L05_VIZ,
    TD_L06_VIZ,
    TD_L07_VIZ,
    TD_L08_VIZ,
    TD_L09_VIZ,
    TD_L10_VIZ,
    TD_LUP_VIZ,
    TD_LDOWN_VIZ,
    // Snap Options
    TD_SNAP_SHAPE_CENTER,
    TD_SNAP_ARC_CENTER,
    TD_SNAP_SYMBOL_ORIGIN,
    TD_SNAP_GRID_POINT,
    TD_SNAP_PIN,
    TD_SNAP_FINGER,
    TD_SNAP_VIA,
    TD_SNAP_FIGURE,
    // RGB Animations
    TD_RGB_10,
    TD_RGB_11,
    TD_RGB_12,
    TD_RGB_13,
    TD_RGB_20,
    TD_RGB_21,
    TD_RGB_22,
    TD_RGB_23,
    TD_RGB_30,
    TD_RGB_31,
};

// Function used by Tap Dance Keyboard Layer keys
void keyboard_layer_change(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_L0_L4):
                // when keycode TD_L0_L4 is pressed once, go to keyboard layer 0
                layer_move(_VISIBILITY);
                break;
            case TD(TD_L1_L5):
                // when keycode TD_L0_L4 is pressed once, go to keyboard layer 1
                layer_move(_MODE_SNAP);
                break;
            case TD(TD_L2_L6):
                // when keycode TD_L0_L4 is pressed once, go to keyboard layer 2
                layer_move(_FIND1);
                break;
            case TD(TD_L3_L7):
                // when keycode TD_L0_L4 is pressed once, go to keyboard layer 3
                layer_move(_FIND2);
                break;
        }
    } else if (state->count == 2) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_L0_L4):
                // when keycode TD_L0_L4 is pressed twice, go to keyboard layer 4
                layer_move(_FOUR);
                break;
            case TD(TD_L1_L5):
                // when keycode TD_L0_L4 is pressed twice, go to keyboard layer 5
                layer_move(_FIVE);
                break;
            case TD(TD_L2_L6):
                // when keycode TD_L0_L4 is pressed twice, go to keyboard layer 6
                layer_move(_SIX);
                break;
            case TD(TD_L3_L7):
                // when keycode TD_L0_L4 is pressed twice, go to keyboard layer 7
                layer_move(_RGB);
                break;
        }
    }
};

// Function used by Tap Dance Layer keys
void layer_toggle_isolate(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_L01_VIZ):
                // when keycode TD_L01_VIZ is pressed once, toggle visibility
                SEND_STRING("l01t");
                break;
            case TD(TD_L02_VIZ):
                // when keycode TD_L02_VIZ is pressed once, toggle visibility
                SEND_STRING("l02t");
                break;
            case TD(TD_L03_VIZ):
                // when keycode TD_L03_VIZ is pressed once, toggle visibility
                SEND_STRING("l03t");
                break;
            case TD(TD_L04_VIZ):
                // when keycode TD_L04_VIZ is pressed once, toggle visibility
                SEND_STRING("l04t");
                break;
            case TD(TD_L05_VIZ):
                // when keycode TD_L05_VIZ is pressed once, toggle visibility
                SEND_STRING("l05t");
                break;
            case TD(TD_L06_VIZ):
                // when keycode TD_L06_VIZ is pressed once, toggle visibility
                SEND_STRING("l06t");
                break;
            case TD(TD_L07_VIZ):
                // when keycode TD_L07_VIZ is pressed once, toggle visibility
                SEND_STRING("l07t");
                break;
            case TD(TD_L08_VIZ):
                // when keycode TD_L08_VIZ is pressed once, toggle visibility
                SEND_STRING("l08t");
                break;
            case TD(TD_L09_VIZ):
                // when keycode TD_L09_VIZ is pressed once, toggle visibility
                SEND_STRING("l09t");
                break;
            case TD(TD_L10_VIZ):
                // when keycode TD_L10_VIZ is pressed once, toggle visibility
                SEND_STRING("l10t");
                break;
            case TD(TD_LUP_VIZ):
                // when keycode TD_LUP_VIZ is pressed once, toggle visibility
                SEND_STRING("lupt");
                break;
            case TD(TD_LDOWN_VIZ):
                // when keycode TD_LDOWN_VIZ is pressed once, toggle visibility
                SEND_STRING("ldnt");
                break;
        }
    } else if (state->count == 2) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_L01_VIZ):
                // when keycode TD_L01_VIZ is pressed once, toggle isolation
                SEND_STRING("l01i");
                break;
            case TD(TD_L02_VIZ):
                // when keycode TD_L02_VIZ is pressed once, toggle isolation
                SEND_STRING("l02i");
                break;
            case TD(TD_L03_VIZ):
                // when keycode TD_L03_VIZ is pressed once, toggle isolation
                SEND_STRING("l03i");
                break;
            case TD(TD_L04_VIZ):
                // when keycode TD_L04_VIZ is pressed once, toggle isolation
                SEND_STRING("l04i");
                break;
            case TD(TD_L05_VIZ):
                // when keycode TD_L05_VIZ is pressed once, toggle isolation
                SEND_STRING("l05i");
                break;
            case TD(TD_L06_VIZ):
                // when keycode TD_L06_VIZ is pressed once, toggle isolation
                SEND_STRING("l06i");
                break;
            case TD(TD_L07_VIZ):
                // when keycode TD_L07_VIZ is pressed once, toggle isolation
                SEND_STRING("l07i");
                break;
            case TD(TD_L08_VIZ):
                // when keycode TD_L08_VIZ is pressed once, toggle isolation
                SEND_STRING("l08i");
                break;
            case TD(TD_L09_VIZ):
                // when keycode TD_L09_VIZ is pressed once, toggle isolation
                SEND_STRING("l09i");
                break;
            case TD(TD_L10_VIZ):
                // when keycode TD_L10_VIZ is pressed once, toggle isolation
                SEND_STRING("l10i");
                break;
            case TD(TD_LUP_VIZ):
                // when keycode TD_LUP_VIZ is pressed once, toggle isolation
                SEND_STRING("lupi");
                break;
            case TD(TD_LDOWN_VIZ):
                // when keycode TD_LDOWN_VIZ is pressed once, toggle isolation
                SEND_STRING("ldni");
                break;
        }
    }
};

// Function used by Tap Dance Snap keys
void snap_persistent(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_SNAP_SHAPE_CENTER):
                // when keycode TD_SNAP_SHAPE_CENTER is pressed once, snap to shape center this time
                SEND_STRING("snap_shape_center\n");
                break;
            case TD(TD_SNAP_ARC_CENTER):
                // when keycode TD_SNAP_ARC_CENTER is pressed once, snap to arc/circle center this time
                SEND_STRING("snap_arc_circle_center\n");
                break;
            case TD(TD_SNAP_SYMBOL_ORIGIN):
                // when keycode TD_SNAP_SYMBOL_ORIGIN is pressed once, snap to symbol origin this time
                SEND_STRING("snap_symbol_origin\n");
                break;
            case TD(TD_SNAP_GRID_POINT):
                // when keycode TD_SNAP_GRID_POINT is pressed once, snap to grid point this time
                SEND_STRING("snap_grid_point\n");
                break;
            case TD(TD_SNAP_PIN):
                // when keycode TD_SNAP_PIN is pressed once, snap to pin this time
                SEND_STRING("snap_pin\n");
                break;
            case TD(TD_SNAP_FINGER):
                // when keycode TD_SNAP_FINGER is pressed once, snap to finger this time
                SEND_STRING("snap_finger\n");
                break;
            case TD(TD_SNAP_VIA):
                // when keycode TD_SNAP_VIA is pressed once, snap to via this time
                SEND_STRING("snap_via\n");
                break;
            case TD(TD_SNAP_FIGURE):
                // when keycode TD_SNAP_FIGURE is pressed once, snap to figure this time
                SEND_STRING("snap_figure\n");
                break;
        }
    } else if (state->count == 2) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_SNAP_SHAPE_CENTER):
                // when keycode TD_SNAP_SHAPE_CENTER is pressed twice, set persistent snap to shape center
                SEND_STRING("persistent_snap_shape_center\n");
                break;
            case TD(TD_SNAP_ARC_CENTER):
                // when keycode TD_SNAP_ARC_CENTER is pressed twice, set persistent snap to arc/circle center
                SEND_STRING("persistent_snap_arc_circle_center\n");
                break;
            case TD(TD_SNAP_SYMBOL_ORIGIN):
                // when keycode TD_SNAP_SYMBOL_ORIGIN is pressed twice, set persistent snap to symbol origin
                SEND_STRING("persistent_snap_symbol_origin\n");
                break;
            case TD(TD_SNAP_GRID_POINT):
                // when keycode TD_SNAP_GRID_POINT is pressed twice, set persistent snap to grid point
                SEND_STRING("persistent_snap_grid_point\n");
                break;
            case TD(TD_SNAP_PIN):
                // when keycode TD_SNAP_PIN is pressed twice, set persistent snap to pin
                SEND_STRING("persistent_snap_pin\n");
                break;
            case TD(TD_SNAP_FINGER):
                // when keycode TD_SNAP_FINGER is pressed twice, set persistent snap to finger
                SEND_STRING("persistent_snap_finger\n");
                break;
            case TD(TD_SNAP_VIA):
                // when keycode TD_SNAP_VIA is pressed twice, set persistent snap to via
                SEND_STRING("persistent_snap_via\n");
                break;
            case TD(TD_SNAP_FIGURE):
                // when keycode TD_SNAP_FIGURE is pressed twice, set persistent snap to figure
                SEND_STRING("persistent_snap_figure\n");
                break;
        }
    }
};

// Function used by Tap Dance RGB animation keys
void rgb_animation_select(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_RGB_10):
                // when keycode TD_RGB_10 is pressed once, activate alphas_mods RGB animation
                rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
                break;
            case TD(TD_RGB_11):
                // when keycode TD_RGB_11 is pressed once, activate gradient_up_down RGB animation
                rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
                break;
            case TD(TD_RGB_12):
                // when keycode TD_RGB_12 is pressed once, activate breathing RGB animation
                rgb_matrix_mode(RGB_MATRIX_BREATHING);
                break;
            case TD(TD_RGB_13):
                // when keycode TD_RGB_13 is pressed once, activate band_sat RGB animation
                rgb_matrix_mode(RGB_MATRIX_BAND_SAT);
                break;
            case TD(TD_RGB_20):
                // when keycode TD_RGB_20 is pressed once, activate band_val RGB animation
                rgb_matrix_mode(RGB_MATRIX_BAND_VAL);
                break;
            case TD(TD_RGB_21):
                // when keycode TD_RGB_21 is pressed once, activate band_pinwheel_sat RGB animation
                rgb_matrix_mode(RGB_MATRIX_BAND_PINWHEEL_SAT);
                break;
            case TD(TD_RGB_22):
                // when keycode TD_RGB_22 is pressed once, activate band_pinwheel_val RGB animation
                rgb_matrix_mode(RGB_MATRIX_BAND_PINWHEEL_VAL);
                break;
            case TD(TD_RGB_23):
                // when keycode TD_RGB_23 is pressed once, activate cycle_all RGB animation
                rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
                break;
            case TD(TD_RGB_30):
                // when keycode TD_RGB_30 is pressed once, activate cycle_up_down RGB animation
                rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
                break;
            case TD(TD_RGB_31):
                // when keycode TD_RGB_31 is pressed once, activate cycle_out_in RGB animation
                rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
                break;
        }
    } else if (state->count == 2) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_RGB_10):
                // when keycode TD_RGB_10 is pressed twice, activate cycle_pinwheel RGB animation
                rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL);
                break;
            case TD(TD_RGB_11):
                // when keycode TD_RGB_11 is pressed twice, activate dual_beacon RGB animation
                rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                break;
            case TD(TD_RGB_12):
                // when keycode TD_RGB_12 is pressed twice, activate rainbow_pinwheels RGB animation
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_PINWHEELS);
                break;
            case TD(TD_RGB_13):
                // when keycode TD_RGB_13 is pressed twice, activate raindrops RGB animation
                rgb_matrix_mode(RGB_MATRIX_RAINDROPS);
                break;
            case TD(TD_RGB_20):
                // when keycode TD_RGB_20 is pressed twice, activate jellybean_raindrops RGB animation
                rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
                break;
            case TD(TD_RGB_21):
                // when keycode TD_RGB_21 is pressed twice, activate hue_breathing RGB animation
                rgb_matrix_mode(RGB_MATRIX_HUE_BREATHING);
                break;
            case TD(TD_RGB_22):
                // when keycode TD_RGB_22 is pressed twice, activate hue_pendulum RGB animation
                rgb_matrix_mode(RGB_MATRIX_HUE_PENDULUM);
                break;
            case TD(TD_RGB_23):
                // when keycode TD_RGB_23 is pressed twice, activate hue_wave RGB animation
                rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
                break;
            case TD(TD_RGB_30):
                // when keycode TD_RGB_30 is pressed twice, activate pixel_fractal RGB animation
                rgb_matrix_mode(RGB_MATRIX_PIXEL_FRACTAL);
                break;
            case TD(TD_RGB_31):
                // when keycode TD_RGB_31 is pressed twice, activate pixel_flow RGB animation
                rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
                break;
        }
    } else if (state->count == 3) {
        switch (TAP_DANCE_KEYCODE(state)) {
            case TD(TD_RGB_10):
                // when keycode TD_RGB_10 is pressed thrice, activate pixel_rain RGB animation
                rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
                break;
            case TD(TD_RGB_11):
                // when keycode TD_RGB_11 is pressed thrice, activate solid_reactive_simple RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
                break;
            case TD(TD_RGB_12):
                // when keycode TD_RGB_12 is pressed thrice, activate solid_reactive RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
                break;
            case TD(TD_RGB_13):
                // when keycode TD_RGB_13 is pressed thrice, activate solid_reactive_multiwide RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
                break;
            case TD(TD_RGB_20):
                // when keycode TD_RGB_20 is pressed thrice, activate solid_reactive_multicross RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTICROSS);
                break;
            case TD(TD_RGB_21):
                // when keycode TD_RGB_21 is pressed thrice, activate solid_reactive_multinexus RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
                break;
            case TD(TD_RGB_22):
                // when keycode TD_RGB_22 is pressed thrice, activate multisplash RGB animation
                rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
                break;
            case TD(TD_RGB_23):
                // when keycode TD_RGB_23 is pressed thrice, activate solid_multisplash RGB animation
                rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
                break;
        }
    }
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Keyboard layers
    [TD_L0_L4] = ACTION_TAP_DANCE_FN(keyboard_layer_change),
    [TD_L1_L5] = ACTION_TAP_DANCE_FN(keyboard_layer_change),
    [TD_L2_L6] = ACTION_TAP_DANCE_FN(keyboard_layer_change),
    [TD_L3_L7] = ACTION_TAP_DANCE_FN(keyboard_layer_change),
    // PCB Layers
    [TD_L01_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L02_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L03_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L04_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L05_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L06_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L07_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L08_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L09_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_L10_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_LUP_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    [TD_LDOWN_VIZ] = ACTION_TAP_DANCE_FN(layer_toggle_isolate),
    // Snap Options
    [TD_SNAP_SHAPE_CENTER] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_ARC_CENTER] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_SYMBOL_ORIGIN] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_GRID_POINT] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_PIN] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_FINGER] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_VIA] = ACTION_TAP_DANCE_FN(snap_persistent),
    [TD_SNAP_FIGURE] = ACTION_TAP_DANCE_FN(snap_persistent),
    // RGB Animations
    [TD_RGB_10] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_11] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_12] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_13] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_20] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_21] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_22] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_23] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_30] = ACTION_TAP_DANCE_FN(rgb_animation_select),
    [TD_RGB_31] = ACTION_TAP_DANCE_FN(rgb_animation_select),
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
        Layer 0 - Visibility
        Single-tap = toggle; Double-tap - isolate
       ┌─────────┬─────────┬─────────┬───────────┐   ┌─────┐ ┌─────┐
       │  TO0/4  │  TO1/5  │  TO2/6  │   TO3/7   │   │ F13 │ │ F14 │
       ├─────────┼─────────┼─────────┼───────────┤   └─────┘ └─────┘
       │ L01_VIZ │ L02_VIZ │ L03_VIZ │  L04_VIZ  │
       ├─────────┼─────────┼─────────┼───────────┤
       │ L05_VIZ │ L06_VIZ │ L07_VIZ │  L08_VIZ  │      ┌─────┐
       ├─────────┼─────────┼─────────┼───────────┤      │ F15 │
       │ L09_VIZ │ L10_VIZ │ LUP_VIZ │ LDOWN_VIZ │      └─────┘
       └─────────┴─────────┴─────────┴───────────┘
*/
    /* Col: 0               1               2               3                 4      */
    [_VISIBILITY] = LAYOUT(
            TD(TD_L0_L4),   TD(TD_L1_L5),   TD(TD_L2_L6),   TD(TD_L3_L7),     KC_F13,
            TD(TD_L01_VIZ), TD(TD_L02_VIZ), TD(TD_L03_VIZ), TD(TD_L04_VIZ),   KC_F14,
            TD(TD_L05_VIZ), TD(TD_L06_VIZ), TD(TD_L07_VIZ), TD(TD_L08_VIZ),   KC_F15,
            TD(TD_L09_VIZ), TD(TD_L10_VIZ), TD(TD_LUP_VIZ), TD(TD_LDOWN_VIZ)
        ),

/*
        Layer 1 - Mode and Snap
        Single-tap = single snap; Double-tap = persistent snap
       ┌──────────────────────┬────────────────────┬───────────────────────┬────────────────────┐   ┌─────┐ ┌─────┐
       │        TO0/4         │       TO1/5        │         TO2/6         │       TO3/7        │   │ F16 │ │ F17 │
       ├──────────────────────┼────────────────────┼───────────────────────┼────────────────────┤   └─────┘ └─────┘
       │        CSGF13        │       CSGF14       │        CSGF15         │       CSGF16       │
       ├──────────────────────┼────────────────────┼───────────────────────┼────────────────────┤
       │ TD_SNAP_SHAPE_CENTER │ TD_SNAP_ARC_CENTER │ TD_SNAP_SYMBOL_ORIGIN │ TD_SNAP_GRID_POINT │      ┌─────┐
       ├──────────────────────┼────────────────────┼───────────────────────┼────────────────────┤      │ F18 │
       │     TD_SNAP_PIN      │   TD_SNAP_FINGER   │      TD_SNAP_VIA      │   TD_SNAP_FIGURE   │      └─────┘
       └──────────────────────┴────────────────────┴───────────────────────┴────────────────────┘
*/
    /* Col: 0                         1                       2                          3                       4      */
    [_MODE_SNAP] = LAYOUT(
            _______,                  _______,                _______,                   _______,                KC_F16,
            C(S(G(KC_F13))),          C(S(G(KC_F14))),        C(S(G(KC_F15))),           C(S(G(KC_F16))),        KC_F17,
            TD(TD_SNAP_SHAPE_CENTER), TD(TD_SNAP_ARC_CENTER), TD(TD_SNAP_SYMBOL_ORIGIN), TD(TD_SNAP_GRID_POINT), KC_F18,
            TD(TD_SNAP_PIN),          TD(TD_SNAP_FINGER),     TD(TD_SNAP_VIA),           TD(TD_SNAP_FIGURE)
            ),

/*
        Layer 2 - Find Filter left column
       ┌───────┬───────┬───────┬───────┐   ┌─────┐ ┌─────┐
       │ TO0/4 │ TO1/5 │ TO2/6 │ TO3/7 │   │ F19 │ │ F20 │
       ├───────┼───────┼───────┼───────┤   └─────┘ └─────┘
       │ CSF13 │ CSF14 │ CSF15 │ CSF16 │
       ├───────┼───────┼───────┼───────┤
       │ CSF17 │ CSF18 │ CSF19 │ CSF20 │      ┌─────┐
       ├───────┼───────┼───────┼───────┤      │ F21 │
       │ CSF21 │ CSF22 │ CSF23 │ CSF24 │      └─────┘
       └───────┴───────┴───────┴───────┘
*/
    /* Col: 0             1             2             3             4      */
    [_FIND1] = LAYOUT(
            _______,      _______,      _______,      _______,      KC_F19,
            C(S(KC_F13)), C(S(KC_F14)), C(S(KC_F15)), C(S(KC_F16)), KC_F20,
            C(S(KC_F17)), C(S(KC_F18)), C(S(KC_F19)), C(S(KC_F20)), KC_F21,
            C(S(KC_F21)), C(S(KC_F22)), C(S(KC_F23)), C(S(KC_F24))
        ),

/*
        Layer 3 - Find Filter right column
       ┌───────┬───────┬───────┬───────┐   ┌─────┐ ┌─────┐
       │ TO0/4 │ TO1/5 │ TO2/6 │ TO3/7 │   │ F22 │ │ F23 │
       ├───────┼───────┼───────┼───────┤   └─────┘ └─────┘
       │ CAF13 │ CAF14 │ CAF15 │ CAF16 │
       ├───────┼───────┼───────┼───────┤
       │ CAF17 │ CAF18 │ CAF19 │ CAF20 │      ┌─────┐
       ├───────┼───────┼───────┼───────┤      │ F24 │
       │ CAF21 │ CAF22 │ CAF23 │ CAF24 │      └─────┘
       └───────┴───────┴───────┴───────┘
*/
    /* Col: 0             1             2             3             4      */
    [_FIND2] = LAYOUT(
            _______,      _______,      _______,      _______,      KC_F22,
            C(A(KC_F13)), C(A(KC_F14)), C(A(KC_F15)), C(A(KC_F16)), KC_F23,
            C(A(KC_F17)), C(A(KC_F18)), C(A(KC_F19)), C(A(KC_F20)), KC_F24,
            C(A(KC_F21)), C(A(KC_F22)), C(A(KC_F23)), C(A(KC_F24))
        ),

/*
        Layer 4 - 
       ┌───────┬───────┬───────┬───────┐   ┌───────┐ ┌───────┐
       │ TO0/4 │ TO1/5 │ TO2/6 │ TO3/7 │   │ CGF13 │ │ CGF14 │
       ├───────┼───────┼───────┼───────┤   └───────┘ └───────┘
       │ AF13  │ AF14  │ AF15  │ AF16  │
       ├───────┼───────┼───────┼───────┤
       │ AF17  │ AF18  │ AF19  │ AF20  │      ┌───────┐
       ├───────┼───────┼───────┼───────┤      │ CGF15 │
       │ AF21  │ AF22  │ AF23  │ AF24  │      └───────┘
       └───────┴───────┴───────┴───────┘
*/
    /* Col: 0          1          2          3          4      */
    [_FOUR] = LAYOUT(
            _______,   _______,   _______,   _______,   C(G(KC_F13)),
            A(KC_F13), A(KC_F14), A(KC_F15), A(KC_F16), C(G(KC_F14)),
            A(KC_F17), A(KC_F18), A(KC_F19), A(KC_F20), C(G(KC_F15)),
            A(KC_F21), A(KC_F22), A(KC_F23), A(KC_F24)
        ),

/*
        Layer 5 - 
       ┌───────┬───────┬───────┬───────┐   ┌───────┐ ┌───────┐
       │ TO0/4 │ TO1/5 │ TO2/6 │ TO3/7 │   │ CGF16 │ │ CGF17 │
       ├───────┼───────┼───────┼───────┤   └───────┘ └───────┘
       │ GF13  │ GF14  │ GF15  │ GF16  │
       ├───────┼───────┼───────┼───────┤
       │ GF17  │ GF18  │ GF19  │ GF20  │      ┌───────┐
       ├───────┼───────┼───────┼───────┤      │ CGF18 │
       │ GF21  │ GF22  │ GF23  │ GF24  │      └───────┘
       └───────┴───────┴───────┴───────┘
*/
    /* Col: 0          1          2          3          4      */
    [_FIVE] = LAYOUT(
            _______,   _______,   _______,   _______,   C(G(KC_F16)),
            G(KC_F13), G(KC_F14), G(KC_F15), G(KC_F16), C(G(KC_F17)),
            G(KC_F17), G(KC_F18), G(KC_F19), G(KC_F20), C(G(KC_F18)),
            G(KC_F21), G(KC_F22), G(KC_F23), G(KC_F24)
        ),

/*
        Layer 6 - 
       ┌───────┬───────┬───────┬───────┐   ┌───────┐ ┌───────┐
       │ TO0/4 │ TO1/5 │ TO2/6 │ TO3/7 │   │ CGF19 │ │ CGF20 │
       ├───────┼───────┼───────┼───────┤   └───────┘ └───────┘
       │ SAF13 │ SAF14 │ SAF15 │ SAF16 │
       ├───────┼───────┼───────┼───────┤
       │ SAF17 │ SAF18 │ SAF19 │ SAF20 │      ┌───────┐
       ├───────┼───────┼───────┼───────┤      │ CGF21 │
       │ SAF21 │ SAF22 │ SAF23 │ SAF24 │      └───────┘
       └───────┴───────┴───────┴───────┘
*/
    /* Col: 0             1             2             3             4      */
    [_SIX] = LAYOUT(
            _______,      _______,      _______,      _______,      C(G(KC_F19)),
            S(A(KC_F13)), S(A(KC_F14)), S(A(KC_F15)), S(A(KC_F16)), C(G(KC_F20)),
            S(A(KC_F17)), S(A(KC_F18)), S(A(KC_F19)), S(A(KC_F20)), C(G(KC_F21)),
            S(A(KC_F21)), S(A(KC_F22)), S(A(KC_F23)), S(A(KC_F24))
        ),

/*
        Layer 7 - RGB
       ┌───────────┬───────────┬───────────┬───────────┐   ┌─────┐ ┌─────┐
       │   TO0/4   │   TO1/5   │   TO2/6   │   TO3/7   │   │ SPD │ │ SPI │
       ├───────────┼───────────┼───────────┼───────────┤   └─────┘ └─────┘
       │ TD_RGB_10 │ TD_RGB_11 │ TD_RGB_12 │ TD_RGB_13 │
       ├───────────┼───────────┼───────────┼───────────┤
       │ TD_RGB_20 │ TD_RGB_21 │ TD_RGB_22 │ TD_RGB_23 │      ┌────────┐
       ├───────────┼───────────┼───────────┼───────────┤      │ Toggle │
       │ TD_RGB_30 │ TD_RGB_31 │   RMOD    │    MOD    │      └────────┘
       └───────────┴───────────┴───────────┴───────────┘
*/
    /* Col: 0              1              2              3              4       */
    [_RGB] = LAYOUT(
            _______,       _______,       _______,       _______,       RGB_SPD,
            TD(TD_RGB_10), TD(TD_RGB_11), TD(TD_RGB_12), TD(TD_RGB_13), RGB_SPI,
            TD(TD_RGB_20), TD(TD_RGB_21), TD(TD_RGB_22), TD(TD_RGB_23), RGB_TOG,
            TD(TD_RGB_30), TD(TD_RGB_31), RGB_RMOD,      RGB_MOD
        ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_VISIBILITY] = { ENCODER_CCW_CW(S(KC_F13), C(KC_F13)), ENCODER_CCW_CW(S(KC_F14), C(KC_F14)), ENCODER_CCW_CW(S(KC_F15), C(KC_F15)) },
    [_MODE_SNAP] = { ENCODER_CCW_CW(S(KC_F16), C(KC_F16)), ENCODER_CCW_CW(S(KC_F17), C(KC_F17)), ENCODER_CCW_CW(S(KC_F18), C(KC_F18)) },
    [_FIND1] = { ENCODER_CCW_CW(S(KC_F19), C(KC_F19)), ENCODER_CCW_CW(S(KC_F20), C(KC_F20)), ENCODER_CCW_CW(S(KC_F21), C(KC_F21)) },
    [_FIND2] = { ENCODER_CCW_CW(S(KC_F22), C(KC_F22)), ENCODER_CCW_CW(S(KC_F23), C(KC_F23)), ENCODER_CCW_CW(S(KC_F24), C(KC_F24)) },
    [_FOUR] = { ENCODER_CCW_CW(S(G(KC_F13)), A(G(KC_F13))), ENCODER_CCW_CW(S(G(KC_F14)), A(G(KC_F14))), ENCODER_CCW_CW(S(G(KC_F15)), A(G(KC_F15))) },
    [_FIVE] = { ENCODER_CCW_CW(S(G(KC_F16)), A(G(KC_F16))), ENCODER_CCW_CW(S(G(KC_F17)), A(G(KC_F17))), ENCODER_CCW_CW(S(G(KC_F18)), A(G(KC_F18))) },
    [_SIX] = { ENCODER_CCW_CW(S(G(KC_F19)), A(G(KC_F19))), ENCODER_CCW_CW(S(G(KC_F20)), A(G(KC_F20))), ENCODER_CCW_CW(S(G(KC_F21)), A(G(KC_F21))) },
    [_RGB] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif
