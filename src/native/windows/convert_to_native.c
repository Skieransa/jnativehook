/* JNativeHook: Global keyboard and mouse hooking for Java.
 * Copyright (C) 2006-2013 Alexander Barker.  All Rights Received.
 * http://code.google.com/p/jnativehook/
 *
 * JNativeHook is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JNativeHook is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <nativehook.h>
#include <windows.h>

#include "convert_to_native.h"
#include "scancode_table.h"

unsigned int convert_to_native_key(unsigned int virtual_keycode) {
	UINT native_keycode = MapVirtualKey(virtual_keycode, 1); // MAPVK_VSC_TO_VK

	return native_keycode;
}

unsigned int convert_to_native_button(unsigned int virtual_button) {
	unsigned short int native_button;

	switch (virtual_button) {
		case MOUSE_BUTTON1:
		case MOUSE_BUTTON2:
			native_button = virtual_button;
			break;
			
		case MOUSE_BUTTON3:
		case MOUSE_BUTTON4:
		case MOUSE_BUTTON5:
			native_button = virtual_button + 1;
			break;

		default:
		case MOUSE_NOBUTTON:
			native_button = 0;
			break;
	}

	return native_button;
}

unsigned int convert_to_native_mask(unsigned int virtual_mask) {
	unsigned short int native_mask = virtual_mask;

	return native_mask;
}