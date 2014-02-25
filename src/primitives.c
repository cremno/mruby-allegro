#include <stddef.h>
#include <mruby.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "mruby-allegro.h"

static mrb_value
version(mrb_state *mrb, mrb_value self)
{
  return mrbal_version_to_hash(mrb, al_get_allegro_primitives_version());
}

static mrb_value
init(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_init_primitives_addon());
}

static mrb_value
shutdown_addon(mrb_state *mrb, mrb_value self)
{
  al_shutdown_primitives_addon();
  return mrb_nil_value();
}

static mrb_value
draw_line(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffdf", &x1, &y1, &x2, &y2, &c, &mrbal_color_data_type, &thickness);
  al_draw_line(x1, y1, x2, y2, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_triangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float x3;
  mrb_float y3;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffffof", &x1, &y1, &x2, &y2, &x3, &y3, &c, &mrbal_color_data_type, &thickness);
  al_draw_triangle(x1, y1, x2, y2, x3, y3, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_triangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float x3;
  mrb_float y3;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffffd", &x1, &y1, &x2, &y2, &x3, &y3, &c, &mrbal_color_data_type);
  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, *c);
  return mrb_nil_value();
}

static mrb_value
draw_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffdf", &x1, &y1, &x2, &y2, &c, &mrbal_color_data_type, &thickness);
  al_draw_rectangle(x1, y1, x2, y2, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffd", &x1, &y1, &x2, &y2, &c, &mrbal_color_data_type);
  al_draw_filled_rectangle(x1, y1, x2, y2, *c);
  return mrb_nil_value();
}

static mrb_value
draw_rounded_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float rx;
  mrb_float ry;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffffdf", &x1, &y1, &x2, &y2, &rx, &ry, &c, &mrbal_color_data_type, &thickness);
  al_draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_rounded_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_float rx;
  mrb_float ry;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffffd", &x1, &y1, &x2, &y2, &rx, &ry, &c, &mrbal_color_data_type);
  al_draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, *c);
  return mrb_nil_value();
}

static mrb_value
draw_pieslice(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_float start_theta;
  mrb_float delta_theta;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fffffdf", &cx, &cy, &r, &start_theta, &delta_theta, &c, &mrbal_color_data_type, &thickness);
  al_draw_pieslice(cx, cy, r, start_theta, delta_theta, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_pieslice(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_float start_theta;
  mrb_float delta_theta;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fffffd", &cx, &cy, &r, &start_theta, &delta_theta, &c, &mrbal_color_data_type);
  al_draw_filled_pieslice(cx, cy, r, start_theta, delta_theta, *c);
  return mrb_nil_value();
}

static mrb_value
draw_circle(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fffdf", &cx, &cy, &r, &c, &mrbal_color_data_type, &thickness);
  al_draw_circle(cx, cy, r, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_circle(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fffd", &cx, &cy, &r, &c, &mrbal_color_data_type);
  al_draw_filled_circle(cx, cy, r, *c);
  return mrb_nil_value();
}

static mrb_value
draw_arc(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_float start_theta;
  mrb_float delta_theta;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "fffffdf", &cx, &cy, &r, &start_theta, &delta_theta, &c, &mrbal_color_data_type, &thickness);
  al_draw_arc(cx, cy, r, start_theta, delta_theta, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_elliptical_arc(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float rx;
  mrb_float ry;
  mrb_float start_theta;
  mrb_float delta_theta;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffffdf", &cx, &cy, &rx, &ry, &start_theta, &delta_theta, &c, &mrbal_color_data_type, &thickness);
  al_draw_elliptical_arc(cx, cy, rx, ry, start_theta, delta_theta, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_ellipse(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float rx;
  mrb_float ry;
  mrb_float thickness;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffdf", &cx, &cy, &rx, &ry, &c, &mrbal_color_data_type, &thickness);
  al_draw_ellipse(cx, cy, rx, ry, *c, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_ellipse(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float rx;
  mrb_float ry;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffffd", &cx, &cy, &rx, &ry, &c, &mrbal_color_data_type);
  al_draw_filled_ellipse(cx, cy, rx, ry, *c);
  return mrb_nil_value();
}

static mrb_value
draw_spline(mrb_state *mrb, mrb_value self)
{
  mrb_float f[8];
  mrb_float thickness;
  float points[8];
  ALLEGRO_COLOR *c;
  size_t i;
  mrb_get_args(mrb, "ffffffffdf", &f[0], &f[1], &f[2], &f[3], &f[4], &f[5], &f[6], &f[7], &c, &mrbal_color_data_type, &thickness);
  for (i = 0; i < 8; ++i) {
    points[i] = f[i];
  }
  al_draw_spline(points, *c, thickness);
  return mrb_nil_value();
}

void
mruby_allegro_primitives_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  mrb_define_class_method(mrb, am, "primitives_version", version, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, am, "init_primitives_addon", init, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, am, "shutdown_primitives_addon", shutdown_addon, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "draw_line", draw_line, MRB_ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_triangle", draw_triangle, MRB_ARGS_REQ(8));
  mrb_define_module_function(mrb, am, "draw_filled_triangle", draw_filled_triangle, MRB_ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_rectangle", draw_rectangle, MRB_ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_filled_rectangle", draw_filled_rectangle, MRB_ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_rounded_rectangle", draw_rounded_rectangle, MRB_ARGS_REQ(8));
  mrb_define_module_function(mrb, am, "draw_filled_rounded_rectangle", draw_filled_rounded_rectangle, MRB_ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_pieslice", draw_pieslice, MRB_ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_filled_pieslice", draw_filled_pieslice, MRB_ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_ellipse", draw_ellipse, MRB_ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_filled_ellipse", draw_filled_ellipse, MRB_ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_circle", draw_circle, MRB_ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_filled_circle", draw_filled_circle, MRB_ARGS_REQ(4));
  mrb_define_module_function(mrb, am, "draw_arc", draw_arc, MRB_ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_elliptical_arc", draw_elliptical_arc, MRB_ARGS_REQ(8));
  mrb_define_module_function(mrb, am, "draw_spline", draw_spline, MRB_ARGS_REQ(10));
}
