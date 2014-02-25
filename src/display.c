#include <mruby.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

#define Get_Display(mrb, obj, sval) Check_Destroyed(mrb, obj, display, sval)

static void
display_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_display(p);
  }
}

struct mrb_data_type const display_data_type = { "allegro/display", display_free };

static mrb_value
initialize(mrb_state *mrb, mrb_value self)
{
  mrb_int w;
  mrb_int h;
  ALLEGRO_DISPLAY *d;
  DATA_TYPE(self) = &display_data_type;
  mrb_get_args(mrb, "ii", &w, &h);
  d = al_create_display(clamp_int(w), clamp_int(h));
  if (!d) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not initialize display");
  }
  DATA_PTR(self) = d;
  return self;
}

static mrb_value
destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d = DATA_PTR(self);
  if (d) {
    al_destroy_display(d);
    DATA_PTR(self) = NULL;
  }
  return mrb_nil_value();
}

static mrb_value
destroyed(mrb_state *mrb, mrb_value self)
{
  return Destroyed(self);
}

static mrb_value
event_source(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  ALLEGRO_EVENT_SOURCE *es;
  Check_Destroyed(mrb, self, display, d);
  es = al_get_display_event_source(d);
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_EVENTSOURCE, &eventsource_data_type, es));
}

static mrb_value
backbuffer(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, display, d);
  b = al_get_backbuffer(d);
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_BITMAP, &bitmap_data_type, b));
}

static mrb_value
flip(mrb_state *mrb, mrb_value self)
{
  al_flip_display();
  return mrb_nil_value();
}

static mrb_value
update_region(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  mrb_int width;
  mrb_int height;
  mrb_get_args(mrb, "iiii", &x, &y, &width, &height);
  al_update_display_region(x, y, width, height);
  return mrb_nil_value();
}

static mrb_value
wait_for_vsync(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_wait_for_vsync());
}

static mrb_value
acknowledge_resize(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Check_Destroyed(mrb, self, display, d);
  return mrb_bool_value(al_acknowledge_resize(d));
}

static mrb_value
window_title_setter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  mrb_value s;
  Get_Display(mrb, self, d);
  mrb_get_args(mrb, "S", &s);
  al_set_window_title(d, mrb_string_value_cstr(mrb, &s));
  return s;
}

static mrb_value
resize(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  mrb_int w;
  mrb_int h;
  Get_Display(mrb, self, d);
  mrb_get_args(mrb, "ii", &w, &h);
  return mrb_bool_value(al_resize_display(d, clamp_int(w), clamp_int(h)));
}

static mrb_value
icon_setter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  mrb_value o;
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, display, d);
  mrb_get_args(mrb, "o", &o);
  Check_Destroyed(mrb, o, bitmap, b);
  al_set_display_icon(d, b);
  return mrb_nil_value();
}

static mrb_value
window_position_getter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  int w;
  int h;
  mrb_value a;
  Get_Display(mrb, self, d);
  al_get_window_position(d, &w, &h);
  a = mrb_ary_new_capa(mrb, 2);
  mrb_ary_push(mrb, a, mrb_fixnum_value(w));
  mrb_ary_push(mrb, a, mrb_fixnum_value(h));
  return a;
}

static mrb_value
window_position_setter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  mrb_value a;
  mrb_value *p;
  Get_Display(mrb, self, d);
  mrb_get_args(mrb, "A", &a);
  if (RARRAY_LEN(a) != 2) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected Array with 2 elements");
  }
  p = RARRAY_PTR(a);
  if (!mrb_fixnum_p(p[0]) || !mrb_fixnum_p(p[1])) {
    mrb_raise(mrb, E_TYPE_ERROR, "expected Fixnum");
  }
  al_set_window_position(d, mrb_fixnum(p[0]), mrb_fixnum(p[1]));
  return a;
}

static mrb_value
width_getter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Get_Display(mrb, self, d);
  return mrb_fixnum_value(al_get_display_width(d));
}

static mrb_value
height_getter(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  Get_Display(mrb, self, d);
  return mrb_fixnum_value(al_get_display_height(d));
}

static mrb_value
inhibit_screensaver_setter(mrb_state *mrb, mrb_value self)
{
  int b;
  mrb_get_args(mrb, "b", &b);
  al_inhibit_screensaver(b);
  return mrb_bool_value(b);
}

void
mruby_allegro_display_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *dc = mrb_define_class_under(mrb, am, "Display", mrb->object_class);
  MRB_SET_INSTANCE_TT(dc, MRB_TT_DATA);
  mrb_define_alias(mrb, dc->c, "create", "new");
  mrb_define_method(mrb, dc, "initialize", initialize, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, dc, "destroy", destroy, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "destroyed?", destroyed, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "backbuffer", backbuffer, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "event_source", event_source, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, dc, "flip", flip, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, dc, "update_region", update_region, MRB_ARGS_REQ(4));
  mrb_define_class_method(mrb, am, "wait_for_vsync", wait_for_vsync, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "height", height_getter, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "width", width_getter, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "window_position", window_position_getter, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, am, "inhibit_screensaver=", inhibit_screensaver_setter, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, dc, "resize", resize, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, dc, "acknowledge_resize?", acknowledge_resize, MRB_ARGS_NONE());
  mrb_define_method(mrb, dc, "window_position=", window_position_setter, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, dc, "window_title=", window_title_setter, MRB_ARGS_REQ(1));
}
