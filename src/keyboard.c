#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static mrb_value
install(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_install_keyboard());
}
static
mrb_value
installed(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_is_keyboard_installed());
}

static mrb_value
uninstall(mrb_state *mrb, mrb_value self)
{
  al_uninstall_keyboard();
  return mrb_nil_value();
}

static mrb_value
event_source(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_SOURCE *es = al_get_keyboard_event_source();
  if (!es) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "keyboard subsystem is not installed");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENTSOURCE, &eventsource_data_type, es));
}

void
mruby_allegro_keyboard_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *km = mrb_define_module_under(mrb, am, "Keyboard");
  mrb_define_class_method(mrb, km, "install", install, ARGS_NONE());
  mrb_define_class_method(mrb, km, "installed?", installed, ARGS_NONE());
  mrb_define_class_method(mrb, km, "uninstall", uninstall, ARGS_NONE());
  mrb_define_class_method(mrb, km, "event_source", event_source, ARGS_NONE());
}
