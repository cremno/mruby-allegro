#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static mrb_value
install(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_install_mouse());
}

static mrb_value
installed(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_is_mouse_installed());
}

static mrb_value
uninstall(mrb_state *mrb, mrb_value self)
{
  al_uninstall_mouse();
  return mrb_nil_value();
}

static mrb_value
num_axes(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(al_get_mouse_num_axes());
}

static mrb_value
num_buttons(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(al_get_mouse_num_buttons());
}

static mrb_value
set_z(mrb_state *mrb, mrb_value self)
{
  mrb_int z;
  mrb_get_args(mrb, "i", &z);
  return mrb_bool_value(al_set_mouse_z(clamp_int(z)));
}

static mrb_value
set_w(mrb_state *mrb, mrb_value self)
{
  mrb_int w;
  mrb_get_args(mrb, "i", &w);
  return mrb_bool_value(al_set_mouse_w(clamp_int(w)));
}

static mrb_value
set_axis(mrb_state *mrb, mrb_value self)
{
  mrb_int which;
  mrb_int value;
  mrb_get_args(mrb, "ii", &which, &value);
  return mrb_bool_value(al_set_mouse_axis(clamp_int(which), clamp_int(value)));
}

static mrb_value
event_source(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_SOURCE *es = al_get_mouse_event_source();
  if (!es) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "mouse subsystem is not installed");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENTSOURCE, &eventsource_data_type, es));
}

static mrb_value
hide_mouse_cursor(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Check_Destroyed(mrb, self, display, d);
  return mrb_bool_value(al_hide_mouse_cursor(d));
}

static mrb_value
show_mouse_cursor(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Check_Destroyed(mrb, self, display, d);
  return mrb_bool_value(al_show_mouse_cursor(d));
}

static mrb_value
grab_mouse(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Check_Destroyed(mrb, self, display, d);
  return mrb_bool_value(al_grab_mouse(d));
}

static mrb_value
ungrab(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Check_Destroyed(mrb, self, display, d);
  return mrb_bool_value(al_ungrab_mouse());
}

void
mruby_allegro_mouse_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *mm = mrb_define_module_under(mrb, am, "Mouse");
  struct RClass *dc = C_DISPLAY;
  mrb_define_class_method(mrb, mm, "install", install, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "installed?", installed, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "uninstall", uninstall, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "num_axes", num_axes, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "num_buttons", num_buttons, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "set_z", set_z, ARGS_REQ(1));
  mrb_define_class_method(mrb, mm, "set_w", set_w, ARGS_REQ(1));
  mrb_define_class_method(mrb, mm, "set_axis", set_axis, ARGS_REQ(2));
  mrb_define_class_method(mrb, mm, "event_source", event_source, ARGS_NONE());
  mrb_define_method(mrb, dc, "hide_mouse_cursor", hide_mouse_cursor, ARGS_NONE());
  mrb_define_method(mrb, dc, "show_mouse_cursor", show_mouse_cursor, ARGS_NONE());
  mrb_define_method(mrb, dc, "grab_mouse", grab_mouse, ARGS_NONE());
  mrb_define_class_method(mrb, mm, "ungrab", ungrab, ARGS_NONE());
}
