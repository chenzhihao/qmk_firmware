// /* Copyright 2020 Josef Adamcik
//  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
//  *
//  * This program is free software: you can redistribute it and/or modify
//  * it under the terms of the GNU General Public License as published by
//  * the Free Software Foundation, either version 2 of the License, or
//  * (at your option) any later version.
//  *
//  * This program is distributed in the hope that it will be useful,
//  * but WITHOUT ANY WARRANTY; without even the implied warranty of
//  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  * GNU General Public License for more details.
//  *
//  * You should have received a copy of the GNU General Public License
//  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
//  */
//
//#pragma once
//
///* The way how "handedness" is decided (which half is which),
//see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
//for more options.
//*/
//
////Add RGB underglow
//#define RGB_DI_PIN D3
//#define RGBLED_NUM 58
//#define RGBLED_SPLIT {29,29}
//#define RGBLIGHT_ANIMATIONS
//
//#define EE_HANDS

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

#pragma once

#define EE_HAND

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


#define TAPPING_FORCE_HOLD

#ifdef TAPPING_TERM
#undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif

#define TAPPING_TOGGLE 2

#define ENCODER_DIRECTION_FLIP

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

//Add RGB underglow
#define RGB_DI_PIN D3
#define RGBLED_NUM 58
#define DRIVER_LED_TOTAL 58
#define RGBLED_SPLIT {29,29}
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_ANIMATIONS
