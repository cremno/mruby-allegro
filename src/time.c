#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

struct mrb_data_type const mrbal_timeout_data_type = { "allegro/timeout", mrb_free };

static mrb_value
get_time(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, al_get_time());
}

static mrb_value
timeout_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_float f;
  ALLEGRO_TIMEOUT *t;
  mrb_get_args(mrb, "f", &f);
  t = mrb_malloc(mrb, sizeof(*t));
  al_init_timeout(t, f);
  DATA_TYPE(self) = &mrbal_timeout_data_type;
  DATA_PTR(self) = t;
  return self;
}

static mrb_value
rest(mrb_state *mrb, mrb_value self)
{
  mrb_float f;
  mrb_get_args(mrb, "f", &f);
  al_rest(f);
  return mrb_nil_value();
}

void
mruby_allegro_time_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *tc = mrb_define_class_under(mrb, am, "Timeout", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_module_function(mrb, am, "time", get_time, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "current_time", get_time, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "initialize", timeout_initialize, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, am, "rest", rest, MRB_ARGS_REQ(1));
}
