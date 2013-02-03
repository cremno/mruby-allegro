#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static void
timer_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_timer(p);
  }
}

struct mrb_data_type timer_data_type = { "allegro/timer", timer_free };

static mrb_value
initialize(mrb_state *mrb, mrb_value self)
{
  mrb_float speed_secs;
  ALLEGRO_TIMER *t;
  DATA_TYPE(self) = &timer_data_type;
  mrb_get_args(mrb, "f", &speed_secs);
  t = al_create_timer(speed_secs);
  if (!t) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "failed to initialize timer");
  }
  DATA_PTR(self) = t;
  return self;
}

static mrb_value
destroyed(mrb_state *mrb, mrb_value self)
{
  return Destroyed(self);
}

static mrb_value
start(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  Check_Destroyed(mrb, self, timer, t);
  al_start_timer(t);
  return mrb_nil_value();
}

static mrb_value
stop(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  Check_Destroyed(mrb, self, timer, t);
  al_stop_timer(t);
  return mrb_nil_value();
}

static mrb_value
started(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  Check_Destroyed(mrb, self, timer, t);
  return mrb_bool_value(al_get_timer_started(t));
}

static mrb_value
destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t = DATA_PTR(self);
  if (t) {
    al_destroy_timer(t);
    DATA_PTR(self) = NULL;
  }
  return mrb_nil_value();
}

static mrb_value
speed_getter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  Check_Destroyed(mrb, self, timer, t);
  return mrb_float_value(al_get_timer_speed(t));
}

static mrb_value
speed_setter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  mrb_float new_speed_secs;
  Check_Destroyed(mrb, self, timer, t);
  mrb_get_args(mrb, "f", &new_speed_secs);
  al_set_timer_speed(t, new_speed_secs);
  return mrb_float_value(new_speed_secs);
}

static mrb_value
event_source(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_TIMER *t;
  ALLEGRO_EVENT_SOURCE *es;
  Check_Destroyed(mrb, self, timer, t);
  es = al_get_timer_event_source(t);
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENTSOURCE, &eventsource_data_type, es));
}

void
mruby_allegro_timer_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *tc = mrb_define_class_under(mrb, am, "Timer", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_alias(mrb, tc->c, "create", "new");
  mrb_define_method(mrb, tc, "initialize", initialize, ARGS_REQ(1));
  mrb_define_method(mrb, tc, "start", start, ARGS_NONE());
  mrb_define_method(mrb, tc, "stop", stop, ARGS_NONE());
  mrb_define_method(mrb, tc, "started?", started, ARGS_NONE());
  mrb_define_method(mrb, tc, "destroy", destroy, ARGS_NONE());
  mrb_define_method(mrb, tc, "destroyed?", destroyed, ARGS_NONE());
  mrb_define_method(mrb, tc, "speed", speed_getter, ARGS_NONE());
  mrb_define_method(mrb, tc, "speed=", speed_setter, ARGS_REQ(1));
  mrb_define_method(mrb, tc, "event_source", event_source, ARGS_NONE());
}
