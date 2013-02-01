#include <stdint.h>
#include <mruby.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static mrb_value
version(mrb_state *mrb, mrb_value self)
{
  return version_to_hash(mrb, al_get_allegro_version());
}

static mrb_value
install(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_init());
}

static mrb_value
uninstall(mrb_state *mrb, mrb_value self)
{
  al_uninstall_system();
  return mrb_nil_value();
}

static mrb_value
installed(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_is_system_installed());
}

static mrb_value
exe_name_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value s;
  mrb_get_args(mrb, "S", &s);
  al_set_exe_name(mrb_string_value_cstr(mrb, &s));
  return s;
}

static mrb_value
app_name_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value s;
  mrb_get_args(mrb, "S", &s);
  al_set_app_name(mrb_string_value_cstr(mrb, &s));
  return s;
}

static mrb_value
org_name_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value s;
  mrb_get_args(mrb, "S", &s);
  al_set_org_name(mrb_string_value_cstr(mrb, &s));
  return s;
}

static mrb_value
app_name_getter(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, al_get_app_name());
}

static mrb_value
org_name_getter(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, al_get_org_name());
}

void
mruby_allegro_system_init(mrb_state *mrb)
{
  struct RClass *am = ALLEGRO_MODULE;
  mrb_define_class_method(mrb, am, "allegro_version", version, ARGS_NONE());
  mrb_define_class_method(mrb, am, "init", install, ARGS_NONE());
  mrb_define_class_method(mrb, am, "install", install, ARGS_NONE());
  mrb_define_class_method(mrb, am, "uninstall", uninstall, ARGS_NONE());
  mrb_define_class_method(mrb, am, "installed?", installed, ARGS_NONE());
  mrb_define_class_method(mrb, am, "exe_name=", exe_name_setter, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "app_name=", app_name_setter, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "org_name=", org_name_setter, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "app_name", app_name_getter, ARGS_NONE());
  mrb_define_class_method(mrb, am, "org_name", org_name_getter, ARGS_NONE());
}
