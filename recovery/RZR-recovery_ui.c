/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"

int
device_recovery_start ()
{
  return 0;
}

int
device_reboot_now (volatile char *key_pressed, int key_code)
{
  return 0;
}

int
device_handle_key (int key_code)
{
  switch (key_code)
	  {
	  case KEY_CAPSLOCK:
	  case 52:              //galaxy s 4g
	    return HIGHLIGHT_DOWN;
	  
	  case KEY_VOLUMEDOWN:	//114
	    if (backwardsVolume_toggled()) return HIGHLIGHT_UP;
	    if (!backwardsVolume_toggled()) return HIGHLIGHT_DOWN;

	  case KEY_VOLUMEUP:	//115
	    if (backwardsVolume_toggled()) return HIGHLIGHT_DOWN;
	    if (!backwardsVolume_toggled()) return HIGHLIGHT_UP;
	  
	  case KEY_LEFTSHIFT:
	  case 51:              //galaxy s 4g
	    return HIGHLIGHT_UP;

	  case KEY_POWER:
	  case KEY_END:
	    if (virtualBack_toggled()) return SELECT_ITEM;
	    if (!virtualBack_toggled()) return ITEM_BACK;
	  
	  case KEY_ENTER:
	  case KEY_CAMERA:
	  case KEY_CENTER:
	  case KEY_HOME:	//102
	  case KEY_MENU:
	  case KEY_SEARCH:
	  case 272:  		//trackball press
	    return SELECT_ITEM;

	  case KEY_BACKSPACE:
	  case KEY_BACK:	//158
	    return ITEM_BACK;
	  }
  return NO_ACTION;
}

int
device_perform_action (int which)
{
  return which;
}

int
device_wipe_data ()
{
  return 0;
}

