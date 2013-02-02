#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static void
color_free(mrb_state *mrb, void *p)
{
  if (p) {
    mrb_free(mrb, p);
  }
}

struct mrb_data_type color_data_type = { "allegro/color", color_free };

static mrb_value
color_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  int argc;
  ALLEGRO_COLOR *oc;
  ALLEGRO_COLOR *c;
  DATA_TYPE(self) = &color_data_type;
  argc = mrb_get_args(mrb, "|o", &o);
  Data_Get_Struct(mrb, o, &color_data_type, oc);
  c = safe_malloc(mrb, sizeof(*c));
  if (argc) {
    *c = *oc;
  } else {
    ALLEGRO_COLOR cd = { 0.f, 0.f, 0.f, 1.f };
    *c = cd;
  }
  DATA_PTR(self) = c;
  return self;
}

static mrb_value
color_rgb(mrb_state *mrb, mrb_value self)
{
  mrb_int r;
  mrb_int g;
  mrb_int b;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "iii", &r, &g, &b);
  c = safe_malloc(mrb, sizeof(*c));
  *c = al_map_rgb(clamp_uc(r), clamp_uc(g), clamp_uc(b));
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &color_data_type, c));
}

static mrb_value
color_rgba(mrb_state *mrb, mrb_value self)
{
  mrb_int r;
  mrb_int g;
  mrb_int b;
  mrb_int a;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "iiii", &r, &g, &b, &a);
  c = safe_malloc(mrb, sizeof(*c));
  *c = al_map_rgba(clamp_uc(r), clamp_uc(g), clamp_uc(b), clamp_uc(a));
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &color_data_type, c));
}

static mrb_value
color_rgb_f(mrb_state *mrb, mrb_value self)
{
  mrb_float r;
  mrb_float g;
  mrb_float b;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fff", &r, &g, &b);
  c = safe_malloc(mrb, sizeof(*c));
  *c = al_map_rgb_f(clamp_f(r), clamp_f(g), clamp_f(b));
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &color_data_type, c));
}

static mrb_value
color_rgba_f(mrb_state *mrb, mrb_value self)
{
  mrb_float r;
  mrb_float g;
  mrb_float b;
  mrb_float a;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffff", &r, &g, &b, &a);
  c = safe_malloc(mrb, sizeof(*c));
  *c = al_map_rgba_f(clamp_f(r), clamp_f(g), clamp_f(b), clamp_f(a));
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &color_data_type, c));
}

static mrb_value
clear_to_color(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  if (mrb_get_args(mrb, "|o", &o) == 1) {
    ALLEGRO_COLOR *c;
    Data_Get_Struct(mrb, o, &color_data_type, c);
    al_clear_to_color(*c);
  } else {
    ALLEGRO_COLOR c = { 0.f, 0.f, 0.f, 1.f };
    al_clear_to_color(c);
  }
  return mrb_nil_value();
}

void
mruby_allegro_graphics_init(mrb_state *mrb)
{
  struct RClass *am = ALLEGRO_MODULE;
  struct RClass *cc = mrb_define_class_under(mrb, am, "Color", mrb->object_class);
  MRB_SET_INSTANCE_TT(cc, MRB_TT_DATA);
  mrb_define_method(mrb, cc, "initialize", color_initialize, ARGS_ANY());
  mrb_define_class_method(mrb, cc, "rgb", color_rgb, ARGS_REQ(3));
  mrb_define_class_method(mrb, cc, "rgba", color_rgba, ARGS_REQ(4));
  mrb_define_class_method(mrb, cc, "rgb_f", color_rgb_f, ARGS_REQ(3));
  mrb_define_class_method(mrb, cc, "rgba_f", color_rgba_f, ARGS_REQ(4));
  mrb_define_class_method(mrb, am, "clear_to_color", clear_to_color, ARGS_OPT(1));
}
