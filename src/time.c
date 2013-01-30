#include <mruby.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static mrb_value
rest(mrb_state *mrb, mrb_value self)
{
  mrb_float f;
  mrb_get_args(mrb, "f", &f);
  al_rest(f);
  return mrb_float_value(f);
}

static mrb_value
current_time(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(al_get_time());
}

void
mruby_allegro_time_init(mrb_state *mrb)
{
  struct RClass *am = ALLEGRO_MODULE;
  mrb_define_class_method(mrb, am, "rest", rest, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "time", current_time, ARGS_NONE());
  mrb_define_class_method(mrb, am, "current_time", current_time, ARGS_NONE());
}
