#include <mruby.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "mruby-allegro.h"

static mrb_value
display_msgbox(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  char *title;
  char *heading;
  char *text = NULL;
  char *buttons = NULL;
  int flags = 0;
  int rv;
  Check_Destroyed(mrb, self, display, d);
  mrb_get_args(mrb, "zz|zz", &title, &heading, &text, &buttons);
  rv = al_show_native_message_box(d, title, heading, text, buttons, flags);
  return mrb_fixnum_value(rv);
}

static mrb_value
global_msgbox(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  char *text = NULL;
  char *title = NULL;
  char *heading;
  char *buttons = NULL;
  int flags = 0;
  int rv;
  mrb_get_args(mrb, "z|zzz", &heading, &text, &title, &buttons);
  d = al_get_current_display();
  rv = al_show_native_message_box(d, title, heading, text, buttons, flags);
  return mrb_fixnum_value(rv);
}

static mrb_value
version(mrb_state *mrb, mrb_value self)
{
  return version_to_hash(mrb, al_get_allegro_native_dialog_version());
}

void
mruby_allegro_dialog_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *dc = C_ALLEGRO_DISPLAY;
  mrb_define_method(mrb, dc, "msgbox", display_msgbox, MRB_ARGS_REQ(2) | MRB_ARGS_OPT(2));
  mrb_define_module_function(mrb, mrb->kernel_module, "msgbox", global_msgbox, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
  mrb_define_class_method(mrb, am, "native_dialog_version", version, MRB_ARGS_NONE());
}
