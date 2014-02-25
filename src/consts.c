#include <mruby.h>
#include <allegro5/allegro.h>

void
consts_init(mrb_state *mrb)
{
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_JOYSTICK_AXIS", mrb_fixnum_value(ALLEGRO_EVENT_JOYSTICK_AXIS));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN", mrb_fixnum_value(ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_JOYSTICK_BUTTON_UP", mrb_fixnum_value(ALLEGRO_EVENT_JOYSTICK_BUTTON_UP));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_JOYSTICK_CONFIGURATION", mrb_fixnum_value(ALLEGRO_EVENT_JOYSTICK_CONFIGURATION));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_KEY_DOWN", mrb_fixnum_value(ALLEGRO_EVENT_KEY_DOWN));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_KEY_CHAR", mrb_fixnum_value(ALLEGRO_EVENT_KEY_CHAR));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_KEY_UP", mrb_fixnum_value(ALLEGRO_EVENT_KEY_UP));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_AXES", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_AXES));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_BUTTON_DOWN", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_BUTTON_DOWN));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_BUTTON_UP", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_BUTTON_UP));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_MOUSE_WARPED", mrb_fixnum_value(ALLEGRO_EVENT_MOUSE_WARPED));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_TIMER", mrb_fixnum_value(ALLEGRO_EVENT_TIMER));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_EXPOSE", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_EXPOSE));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_RESIZE", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_RESIZE));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_CLOSE", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_CLOSE));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_LOST", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_LOST));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_FOUND", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_FOUND));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_SWITCH_IN", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_SWITCH_IN));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_SWITCH_OUT", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_SWITCH_OUT));
  mrb_define_global_const(mrb, "ALLEGRO_EVENT_DISPLAY_ORIENTATION", mrb_fixnum_value(ALLEGRO_EVENT_DISPLAY_ORIENTATION));

  mrb_define_global_const(mrb, "ALLEGRO_KEY_A", mrb_fixnum_value(ALLEGRO_KEY_A));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_B", mrb_fixnum_value(ALLEGRO_KEY_B));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_C", mrb_fixnum_value(ALLEGRO_KEY_C));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_D", mrb_fixnum_value(ALLEGRO_KEY_D));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_E", mrb_fixnum_value(ALLEGRO_KEY_E));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F", mrb_fixnum_value(ALLEGRO_KEY_F));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_G", mrb_fixnum_value(ALLEGRO_KEY_G));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_H", mrb_fixnum_value(ALLEGRO_KEY_H));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_I", mrb_fixnum_value(ALLEGRO_KEY_I));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_J", mrb_fixnum_value(ALLEGRO_KEY_J));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_K", mrb_fixnum_value(ALLEGRO_KEY_K));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_L", mrb_fixnum_value(ALLEGRO_KEY_L));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_M", mrb_fixnum_value(ALLEGRO_KEY_M));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_N", mrb_fixnum_value(ALLEGRO_KEY_N));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_O", mrb_fixnum_value(ALLEGRO_KEY_O));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_P", mrb_fixnum_value(ALLEGRO_KEY_P));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_Q", mrb_fixnum_value(ALLEGRO_KEY_Q));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_R", mrb_fixnum_value(ALLEGRO_KEY_R));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_S", mrb_fixnum_value(ALLEGRO_KEY_S));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_T", mrb_fixnum_value(ALLEGRO_KEY_T));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_U", mrb_fixnum_value(ALLEGRO_KEY_U));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_V", mrb_fixnum_value(ALLEGRO_KEY_V));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_W", mrb_fixnum_value(ALLEGRO_KEY_W));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_X", mrb_fixnum_value(ALLEGRO_KEY_X));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_Y", mrb_fixnum_value(ALLEGRO_KEY_Y));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_Z", mrb_fixnum_value(ALLEGRO_KEY_Z));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_0", mrb_fixnum_value(ALLEGRO_KEY_0));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_1", mrb_fixnum_value(ALLEGRO_KEY_1));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_2", mrb_fixnum_value(ALLEGRO_KEY_2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_3", mrb_fixnum_value(ALLEGRO_KEY_3));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_4", mrb_fixnum_value(ALLEGRO_KEY_4));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_5", mrb_fixnum_value(ALLEGRO_KEY_5));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_6", mrb_fixnum_value(ALLEGRO_KEY_6));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_7", mrb_fixnum_value(ALLEGRO_KEY_7));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_8", mrb_fixnum_value(ALLEGRO_KEY_8));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_9", mrb_fixnum_value(ALLEGRO_KEY_9));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_0", mrb_fixnum_value(ALLEGRO_KEY_PAD_0));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_1", mrb_fixnum_value(ALLEGRO_KEY_PAD_1));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_2", mrb_fixnum_value(ALLEGRO_KEY_PAD_2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_3", mrb_fixnum_value(ALLEGRO_KEY_PAD_3));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_4", mrb_fixnum_value(ALLEGRO_KEY_PAD_4));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_5", mrb_fixnum_value(ALLEGRO_KEY_PAD_5));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_6", mrb_fixnum_value(ALLEGRO_KEY_PAD_6));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_7", mrb_fixnum_value(ALLEGRO_KEY_PAD_7));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_8", mrb_fixnum_value(ALLEGRO_KEY_PAD_8));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_9", mrb_fixnum_value(ALLEGRO_KEY_PAD_9));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F1", mrb_fixnum_value(ALLEGRO_KEY_F1));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F2", mrb_fixnum_value(ALLEGRO_KEY_F2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F3", mrb_fixnum_value(ALLEGRO_KEY_F3));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F4", mrb_fixnum_value(ALLEGRO_KEY_F4));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F5", mrb_fixnum_value(ALLEGRO_KEY_F5));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F6", mrb_fixnum_value(ALLEGRO_KEY_F6));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F7", mrb_fixnum_value(ALLEGRO_KEY_F7));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F8", mrb_fixnum_value(ALLEGRO_KEY_F8));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F9", mrb_fixnum_value(ALLEGRO_KEY_F9));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F10", mrb_fixnum_value(ALLEGRO_KEY_F10));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F11", mrb_fixnum_value(ALLEGRO_KEY_F11));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_F12", mrb_fixnum_value(ALLEGRO_KEY_F12));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_ESCAPE", mrb_fixnum_value(ALLEGRO_KEY_ESCAPE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_TILDE", mrb_fixnum_value(ALLEGRO_KEY_TILDE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_MINUS", mrb_fixnum_value(ALLEGRO_KEY_MINUS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_EQUALS", mrb_fixnum_value(ALLEGRO_KEY_EQUALS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_BACKSPACE", mrb_fixnum_value(ALLEGRO_KEY_BACKSPACE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_TAB", mrb_fixnum_value(ALLEGRO_KEY_TAB));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_OPENBRACE", mrb_fixnum_value(ALLEGRO_KEY_OPENBRACE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_CLOSEBRACE", mrb_fixnum_value(ALLEGRO_KEY_CLOSEBRACE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_ENTER", mrb_fixnum_value(ALLEGRO_KEY_ENTER));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_SEMICOLON", mrb_fixnum_value(ALLEGRO_KEY_SEMICOLON));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_QUOTE", mrb_fixnum_value(ALLEGRO_KEY_QUOTE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_BACKSLASH", mrb_fixnum_value(ALLEGRO_KEY_BACKSLASH));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_BACKSLASH2", mrb_fixnum_value(ALLEGRO_KEY_BACKSLASH2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_COMMA", mrb_fixnum_value(ALLEGRO_KEY_COMMA));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_FULLSTOP", mrb_fixnum_value(ALLEGRO_KEY_FULLSTOP));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_SLASH", mrb_fixnum_value(ALLEGRO_KEY_SLASH));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_SPACE", mrb_fixnum_value(ALLEGRO_KEY_SPACE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_INSERT", mrb_fixnum_value(ALLEGRO_KEY_INSERT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_DELETE", mrb_fixnum_value(ALLEGRO_KEY_DELETE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_HOME", mrb_fixnum_value(ALLEGRO_KEY_HOME));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_END", mrb_fixnum_value(ALLEGRO_KEY_END));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PGUP", mrb_fixnum_value(ALLEGRO_KEY_PGUP));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PGDN", mrb_fixnum_value(ALLEGRO_KEY_PGDN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_LEFT", mrb_fixnum_value(ALLEGRO_KEY_LEFT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_RIGHT", mrb_fixnum_value(ALLEGRO_KEY_RIGHT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_UP", mrb_fixnum_value(ALLEGRO_KEY_UP));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_DOWN", mrb_fixnum_value(ALLEGRO_KEY_DOWN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_SLASH", mrb_fixnum_value(ALLEGRO_KEY_PAD_SLASH));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_ASTERISK", mrb_fixnum_value(ALLEGRO_KEY_PAD_ASTERISK));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_MINUS", mrb_fixnum_value(ALLEGRO_KEY_PAD_MINUS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_PLUS", mrb_fixnum_value(ALLEGRO_KEY_PAD_PLUS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_DELETE", mrb_fixnum_value(ALLEGRO_KEY_PAD_DELETE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_ENTER", mrb_fixnum_value(ALLEGRO_KEY_PAD_ENTER));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PRINTSCREEN", mrb_fixnum_value(ALLEGRO_KEY_PRINTSCREEN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAUSE", mrb_fixnum_value(ALLEGRO_KEY_PAUSE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_ABNT_C1", mrb_fixnum_value(ALLEGRO_KEY_ABNT_C1));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_YEN", mrb_fixnum_value(ALLEGRO_KEY_YEN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_KANA", mrb_fixnum_value(ALLEGRO_KEY_KANA));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_CONVERT", mrb_fixnum_value(ALLEGRO_KEY_CONVERT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_NOCONVERT", mrb_fixnum_value(ALLEGRO_KEY_NOCONVERT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_AT", mrb_fixnum_value(ALLEGRO_KEY_AT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_CIRCUMFLEX", mrb_fixnum_value(ALLEGRO_KEY_CIRCUMFLEX));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_COLON2", mrb_fixnum_value(ALLEGRO_KEY_COLON2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_KANJI", mrb_fixnum_value(ALLEGRO_KEY_KANJI));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_PAD_EQUALS", mrb_fixnum_value(ALLEGRO_KEY_PAD_EQUALS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_BACKQUOTE", mrb_fixnum_value(ALLEGRO_KEY_BACKQUOTE));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_SEMICOLON2", mrb_fixnum_value(ALLEGRO_KEY_SEMICOLON2));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_COMMAND", mrb_fixnum_value(ALLEGRO_KEY_COMMAND));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_UNKNOWN", mrb_fixnum_value(ALLEGRO_KEY_UNKNOWN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_MODIFIERS", mrb_fixnum_value(ALLEGRO_KEY_MODIFIERS));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_LSHIFT", mrb_fixnum_value(ALLEGRO_KEY_LSHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_RSHIFT", mrb_fixnum_value(ALLEGRO_KEY_RSHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_LCTRL", mrb_fixnum_value(ALLEGRO_KEY_LCTRL));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_RCTRL", mrb_fixnum_value(ALLEGRO_KEY_RCTRL));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_ALT", mrb_fixnum_value(ALLEGRO_KEY_ALT));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_ALTGR", mrb_fixnum_value(ALLEGRO_KEY_ALTGR));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_LWIN", mrb_fixnum_value(ALLEGRO_KEY_LWIN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_RWIN", mrb_fixnum_value(ALLEGRO_KEY_RWIN));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_MENU", mrb_fixnum_value(ALLEGRO_KEY_MENU));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_SCROLLLOCK", mrb_fixnum_value(ALLEGRO_KEY_SCROLLLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_NUMLOCK", mrb_fixnum_value(ALLEGRO_KEY_NUMLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEY_CAPSLOCK", mrb_fixnum_value(ALLEGRO_KEY_CAPSLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_SHIFT", mrb_fixnum_value(ALLEGRO_KEYMOD_SHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_CTRL", mrb_fixnum_value(ALLEGRO_KEYMOD_CTRL));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ALT", mrb_fixnum_value(ALLEGRO_KEYMOD_ALT));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_LWIN", mrb_fixnum_value(ALLEGRO_KEYMOD_LWIN));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_RWIN", mrb_fixnum_value(ALLEGRO_KEYMOD_RWIN));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_MENU", mrb_fixnum_value(ALLEGRO_KEYMOD_MENU));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ALTGR", mrb_fixnum_value(ALLEGRO_KEYMOD_ALTGR));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_COMMAND", mrb_fixnum_value(ALLEGRO_KEYMOD_COMMAND));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_SCROLLLOCK", mrb_fixnum_value(ALLEGRO_KEYMOD_SCROLLLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_NUMLOCK", mrb_fixnum_value(ALLEGRO_KEYMOD_NUMLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_CAPSLOCK", mrb_fixnum_value(ALLEGRO_KEYMOD_CAPSLOCK));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_INALTSEQ", mrb_fixnum_value(ALLEGRO_KEYMOD_INALTSEQ));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ACCENT1", mrb_fixnum_value(ALLEGRO_KEYMOD_ACCENT1));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ACCENT2", mrb_fixnum_value(ALLEGRO_KEYMOD_ACCENT2));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ACCENT3", mrb_fixnum_value(ALLEGRO_KEYMOD_ACCENT3));
  mrb_define_global_const(mrb, "ALLEGRO_KEYMOD_ACCENT4", mrb_fixnum_value(ALLEGRO_KEYMOD_ACCENT4));

  mrb_define_global_const(mrb, "ALLEGRO_LOCK_READWRITE", mrb_fixnum_value(ALLEGRO_LOCK_READWRITE));
  mrb_define_global_const(mrb, "ALLEGRO_LOCK_READONLY", mrb_fixnum_value(ALLEGRO_LOCK_READONLY));
  mrb_define_global_const(mrb, "ALLEGRO_LOCK_WRITEONLY", mrb_fixnum_value(ALLEGRO_LOCK_WRITEONLY));

  mrb_define_global_const(mrb, "ALLEGRO_ZERO", mrb_fixnum_value(ALLEGRO_ZERO));
  mrb_define_global_const(mrb, "ALLEGRO_ONE", mrb_fixnum_value(ALLEGRO_ONE));
  mrb_define_global_const(mrb, "ALLEGRO_ALPHA", mrb_fixnum_value(ALLEGRO_ALPHA));
  mrb_define_global_const(mrb, "ALLEGRO_INVERSE_ALPHA", mrb_fixnum_value(ALLEGRO_INVERSE_ALPHA));

  mrb_define_global_const(mrb, "ALLEGRO_ADD", mrb_fixnum_value(ALLEGRO_ADD));
  mrb_define_global_const(mrb, "ALLEGRO_SRC_MINUS_DEST", mrb_fixnum_value(ALLEGRO_SRC_MINUS_DEST));
  mrb_define_global_const(mrb, "ALLEGRO_SRC_MINUS_DEST", mrb_fixnum_value(ALLEGRO_DEST_MINUS_SRC));
  mrb_define_global_const(mrb, "ALLEGRO_NUM_BLEND_OPERATIONS", mrb_fixnum_value(ALLEGRO_NUM_BLEND_OPERATIONS));

  mrb_define_global_const(mrb, "ALLEGRO_WINDOWED", mrb_fixnum_value(ALLEGRO_WINDOWED));
  mrb_define_global_const(mrb, "ALLEGRO_FULLSCREEN", mrb_fixnum_value(ALLEGRO_FULLSCREEN));
  mrb_define_global_const(mrb, "ALLEGRO_OPENGL", mrb_fixnum_value(ALLEGRO_OPENGL));
  mrb_define_global_const(mrb, "ALLEGRO_DIRECT3D_INTERNAL", mrb_fixnum_value(ALLEGRO_DIRECT3D_INTERNAL));
  mrb_define_global_const(mrb, "ALLEGRO_RESIZABLE", mrb_fixnum_value(ALLEGRO_RESIZABLE));
  mrb_define_global_const(mrb, "ALLEGRO_FRAMELESS", mrb_fixnum_value(ALLEGRO_FRAMELESS));
  mrb_define_global_const(mrb, "ALLEGRO_NOFRAME", mrb_fixnum_value(ALLEGRO_NOFRAME));
  mrb_define_global_const(mrb, "ALLEGRO_GENERATE_EXPOSE_EVENTS", mrb_fixnum_value(ALLEGRO_GENERATE_EXPOSE_EVENTS));
  mrb_define_global_const(mrb, "ALLEGRO_OPENGL_3_0", mrb_fixnum_value(ALLEGRO_OPENGL_3_0));
  mrb_define_global_const(mrb, "ALLEGRO_OPENGL_FORWARD_COMPATIBLE", mrb_fixnum_value(ALLEGRO_OPENGL_FORWARD_COMPATIBLE));
  mrb_define_global_const(mrb, "ALLEGRO_FULLSCREEN_WINDOW", mrb_fixnum_value(ALLEGRO_FULLSCREEN_WINDOW));
  mrb_define_global_const(mrb, "ALLEGRO_MINIMIZED", mrb_fixnum_value(ALLEGRO_MINIMIZED));

  mrb_define_global_const(mrb, "ALLEGRO_RED_SIZE", mrb_fixnum_value(ALLEGRO_RED_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_GREEN_SIZE", mrb_fixnum_value(ALLEGRO_GREEN_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_BLUE_SIZE", mrb_fixnum_value(ALLEGRO_BLUE_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_ALPHA_SIZE", mrb_fixnum_value(ALLEGRO_ALPHA_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_RED_SHIFT", mrb_fixnum_value(ALLEGRO_RED_SHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_GREEN_SHIFT", mrb_fixnum_value(ALLEGRO_GREEN_SHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_BLUE_SHIFT", mrb_fixnum_value(ALLEGRO_BLUE_SHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_ALPHA_SHIFT", mrb_fixnum_value(ALLEGRO_ALPHA_SHIFT));
  mrb_define_global_const(mrb, "ALLEGRO_ACC_RED_SIZE", mrb_fixnum_value(ALLEGRO_ACC_RED_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_ACC_GREEN_SIZE", mrb_fixnum_value(ALLEGRO_ACC_GREEN_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_ACC_BLUE_SIZE", mrb_fixnum_value(ALLEGRO_ACC_BLUE_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_ACC_ALPHA_SIZE", mrb_fixnum_value(ALLEGRO_ACC_ALPHA_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_STEREO", mrb_fixnum_value(ALLEGRO_STEREO));
  mrb_define_global_const(mrb, "ALLEGRO_AUX_BUFFERS", mrb_fixnum_value(ALLEGRO_AUX_BUFFERS));
  mrb_define_global_const(mrb, "ALLEGRO_COLOR_SIZE", mrb_fixnum_value(ALLEGRO_COLOR_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_DEPTH_SIZE", mrb_fixnum_value(ALLEGRO_DEPTH_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_STENCIL_SIZE", mrb_fixnum_value(ALLEGRO_STENCIL_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_SAMPLE_BUFFERS", mrb_fixnum_value(ALLEGRO_SAMPLE_BUFFERS));
  mrb_define_global_const(mrb, "ALLEGRO_SAMPLES", mrb_fixnum_value(ALLEGRO_SAMPLES));
  mrb_define_global_const(mrb, "ALLEGRO_RENDER_METHOD", mrb_fixnum_value(ALLEGRO_RENDER_METHOD));
  mrb_define_global_const(mrb, "ALLEGRO_FLOAT_COLOR", mrb_fixnum_value(ALLEGRO_FLOAT_COLOR));
  mrb_define_global_const(mrb, "ALLEGRO_FLOAT_DEPTH", mrb_fixnum_value(ALLEGRO_FLOAT_DEPTH));
  mrb_define_global_const(mrb, "ALLEGRO_SINGLE_BUFFER", mrb_fixnum_value(ALLEGRO_SINGLE_BUFFER));
  mrb_define_global_const(mrb, "ALLEGRO_SWAP_METHOD", mrb_fixnum_value(ALLEGRO_SWAP_METHOD));
  mrb_define_global_const(mrb, "ALLEGRO_COMPATIBLE_DISPLAY", mrb_fixnum_value(ALLEGRO_COMPATIBLE_DISPLAY));
  mrb_define_global_const(mrb, "ALLEGRO_UPDATE_DISPLAY_REGION", mrb_fixnum_value(ALLEGRO_UPDATE_DISPLAY_REGION));
  mrb_define_global_const(mrb, "ALLEGRO_VSYNC", mrb_fixnum_value(ALLEGRO_VSYNC));
  mrb_define_global_const(mrb, "ALLEGRO_MAX_BITMAP_SIZE", mrb_fixnum_value(ALLEGRO_MAX_BITMAP_SIZE));
  mrb_define_global_const(mrb, "ALLEGRO_SUPPORT_NPOT_BITMAP", mrb_fixnum_value(ALLEGRO_SUPPORT_NPOT_BITMAP));
  mrb_define_global_const(mrb, "ALLEGRO_CAN_DRAW_INTO_BITMAP", mrb_fixnum_value(ALLEGRO_CAN_DRAW_INTO_BITMAP));
  mrb_define_global_const(mrb, "ALLEGRO_SUPPORT_SEPARATE_ALPHA", mrb_fixnum_value(ALLEGRO_SUPPORT_SEPARATE_ALPHA));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_OPTIONS_COUNT", mrb_fixnum_value(ALLEGRO_DISPLAY_OPTIONS_COUNT));

  mrb_define_global_const(mrb, "ALLEGRO_DONTCARE", mrb_fixnum_value(ALLEGRO_DONTCARE));
  mrb_define_global_const(mrb, "ALLEGRO_REQUIRE", mrb_fixnum_value(ALLEGRO_REQUIRE));
  mrb_define_global_const(mrb, "ALLEGRO_SUGGEST", mrb_fixnum_value(ALLEGRO_SUGGEST));

  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_FACE_UP", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_FACE_UP));
  mrb_define_global_const(mrb, "ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN", mrb_fixnum_value(ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN));
}
