#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static void
event_free(mrb_state *mrb, void *p)
{
  if (p) {
    mrb_free(mrb, p);
  }
}

struct mrb_data_type event_data_type = { "allegro/event", event_free };

struct mrb_data_type eventsource_data_type = { "allegro/eventsource", NULL };

static void
eventqueue_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_event_queue(p);
  }
}

struct mrb_data_type eventqueue_data_type = { "allegro/eventqueue", eventqueue_free };

static mrb_value
event_type(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->type);
}

static mrb_value
event_keyboard_keycode(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->keyboard.keycode);
}

static mrb_value
event_mouse_x(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.x);
}

static mrb_value
event_mouse_y(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.y);
}

static mrb_value
event_mouse_z(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.z);
}

static mrb_value
event_mouse_w(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.w);
}

static mrb_value
event_mouse_dx(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.dx);
}

static mrb_value
event_mouse_dy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.dy);
}

static mrb_value
event_mouse_dz(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.dz);
}

static mrb_value
event_mouse_dw(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.dw);
}

static mrb_value
event_mouse_button(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT *e = DATA_PTR(self);
  return mrb_fixnum_value(e->mouse.button);
}

static mrb_value
eventqueue_initialize(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq;
  eq = al_create_event_queue();
  if (!eq) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not create event queue");
  }
  DATA_TYPE(self) = &eventqueue_data_type;
  DATA_PTR(self) = eq;
  return self;
}

static mrb_value
eventqueue_destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq = DATA_PTR(self);
  if (eq) {
    al_destroy_event_queue(eq);
    DATA_PTR(self) = NULL;
  }
  return mrb_nil_value();
}

static mrb_value
eventqueue_destroyed(mrb_state *mrb, mrb_value self)
{
  return Destroyed(self);
}

static mrb_value
eventqueue_register(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE* eq;
  mrb_value o;
  ALLEGRO_EVENT_SOURCE *es;
  Check_Destroyed(mrb, self, eventqueue, eq);
  mrb_get_args(mrb, "o", &o);
  Data_Get_Struct(mrb, o, &eventsource_data_type, es);
  al_register_event_source(eq, es);
  return mrb_nil_value();
}

static mrb_value
eventqueue_unregister(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE* eq;
  mrb_value o;
  ALLEGRO_EVENT_SOURCE *es;
  Check_Destroyed(mrb, self, eventqueue, eq);
  mrb_get_args(mrb, "o", &o);
  Data_Get_Struct(mrb, o, &eventsource_data_type, es);
  al_unregister_event_source(eq, es);
  return mrb_nil_value();
}

static mrb_value
eventqueue_empty(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE* eq;
  Check_Destroyed(mrb, self, eventqueue, eq);
  return mrb_bool_value(al_is_event_queue_empty(eq));
}

static mrb_value
eventqueue_next_event(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq;
  ALLEGRO_EVENT *e;
  Check_Destroyed(mrb, self, eventqueue, eq);
  e = safe_malloc(mrb, sizeof(*e));
  if (al_get_next_event(eq, e)) {
    return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENT, &event_data_type, e));
  } else {
    return mrb_nil_value();
  }
}

static mrb_value
eventqueue_drop_next_event(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq;
  Check_Destroyed(mrb, self, eventqueue, eq);
  return mrb_bool_value(al_drop_next_event(eq));
}

static mrb_value
eventqueue_flush(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq;
  Check_Destroyed(mrb, self, eventqueue, eq);
  al_flush_event_queue(eq);
  return mrb_nil_value();
}

static mrb_value
eventqueue_wait_for_event(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_EVENT_QUEUE *eq;
  ALLEGRO_EVENT *e;
  Check_Destroyed(mrb, self, eventqueue, eq);
  e = safe_malloc(mrb, sizeof(*e));
  al_wait_for_event(eq, e);
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENT, &event_data_type, e));
}

void
mruby_allegro_events_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *ec = mrb_define_class_under(mrb, am, "Event", mrb->object_class);
  struct RClass *esc = mrb_define_class_under(mrb, am, "EventSource", mrb->object_class);
  struct RClass *eqc = mrb_define_class_under(mrb, am, "EventQueue", mrb->object_class);
  MRB_SET_INSTANCE_TT(ec, MRB_TT_DATA);
  mrb_undef_class_method(mrb, ec, "new");
  mrb_define_method(mrb, ec, "type", event_type, ARGS_NONE());
  mrb_define_method(mrb, ec, "keycode", event_keyboard_keycode, ARGS_NONE());
  mrb_define_method(mrb, ec, "x", event_mouse_x, ARGS_NONE());
  mrb_define_method(mrb, ec, "y", event_mouse_y, ARGS_NONE());
  mrb_define_method(mrb, ec, "z", event_mouse_z, ARGS_NONE());
  mrb_define_method(mrb, ec, "w", event_mouse_w, ARGS_NONE());
  mrb_define_method(mrb, ec, "dx", event_mouse_dx, ARGS_NONE());
  mrb_define_method(mrb, ec, "dy", event_mouse_dy, ARGS_NONE());
  mrb_define_method(mrb, ec, "dz", event_mouse_dz, ARGS_NONE());
  mrb_define_method(mrb, ec, "dw", event_mouse_dw, ARGS_NONE());
  mrb_define_method(mrb, ec, "button", event_mouse_button, ARGS_NONE());
  MRB_SET_INSTANCE_TT(esc, MRB_TT_DATA);
  mrb_undef_class_method(mrb, esc, "new");
  MRB_SET_INSTANCE_TT(eqc, MRB_TT_DATA);
  mrb_define_alias(mrb, eqc->c, "create", "new");
  mrb_define_method(mrb, eqc, "initialize", eventqueue_initialize, ARGS_NONE());
  mrb_define_method(mrb, eqc, "destroy", eventqueue_destroy, ARGS_NONE());
  mrb_define_method(mrb, eqc, "destroyed?", eventqueue_destroyed, ARGS_NONE());
  mrb_define_method(mrb, eqc, "register", eventqueue_register, ARGS_REQ(1));
  mrb_define_method(mrb, eqc, "unregister", eventqueue_unregister, ARGS_REQ(1));
  mrb_define_method(mrb, eqc, "empty?", eventqueue_empty, ARGS_NONE());
  mrb_define_method(mrb, eqc, "next_event", eventqueue_next_event, ARGS_NONE());
  mrb_define_method(mrb, eqc, "drop_next_event", eventqueue_drop_next_event, ARGS_NONE());
  mrb_define_method(mrb, eqc, "flush", eventqueue_flush, ARGS_NONE());
  mrb_define_method(mrb, eqc, "wait_for_event", eventqueue_wait_for_event, ARGS_NONE());
}
