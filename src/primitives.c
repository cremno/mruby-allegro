#include <stddef.h>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "mruby-allegro.h"

static mrb_value
draw_line(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffof", &x1, &y1, &x2, &y2, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_line(x1, y1, x2, y2, *ac, thickness);
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
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffffof", &x1, &y1, &x2, &y2, &x3, &y3, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_triangle(x1, y1, x2, y2, x3, y3, *ac, thickness);
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
  mrb_value c;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffffo", &x1, &y1, &x2, &y2, &x3, &y3, &c);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, *ac);
  return mrb_nil_value();
}

static mrb_value
draw_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffof", &x1, &y1, &x2, &y2, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_rectangle(x1, y1, x2, y2, *ac, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_rectangle(mrb_state *mrb, mrb_value self)
{
  mrb_float x1;
  mrb_float y1;
  mrb_float x2;
  mrb_float y2;
  mrb_value c;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffo", &x1, &y1, &x2, &y2, &c);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_filled_rectangle(x1, y1, x2, y2, *ac);
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
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffffof", &x1, &y1, &x2, &y2, &rx, &ry, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, *ac, thickness);
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
  mrb_value c;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffffo", &x1, &y1, &x2, &y2, &rx, &ry, &c);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, *ac);
  return mrb_nil_value();
}

static mrb_value
draw_circle(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "fffof", &cx, &cy, &r, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_circle(cx, cy, r, *ac, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_circle(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float r;
  mrb_value c;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "fffo", &cx, &cy, &r, &c);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_filled_circle(cx, cy, r, *ac);
  return mrb_nil_value();
}


static mrb_value
draw_ellipse(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float rx;
  mrb_float ry;
  mrb_value c;
  mrb_float thickness;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffof", &cx, &cy, &rx, &ry, &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_ellipse(cx, cy, rx, ry, *ac, thickness);
  return mrb_nil_value();
}

static mrb_value
draw_filled_ellipse(mrb_state *mrb, mrb_value self)
{
  mrb_float cx;
  mrb_float cy;
  mrb_float rx;
  mrb_float ry;
  mrb_value c;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ffffo", &cx, &cy, &rx, &ry, &c);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_filled_ellipse(cx, cy, rx, ry, *ac);
  return mrb_nil_value();
}

static mrb_value
draw_spline(mrb_state *mrb, mrb_value self)
{
  mrb_float f[8];
  mrb_value c;
  mrb_float thickness;
  float points[8];
  ALLEGRO_COLOR *ac;
  size_t i;
  mrb_get_args(mrb, "ffffffffof", &f[0], &f[1], &f[2], &f[3], &f[4], &f[5], &f[6], &f[7], &c, &thickness);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  for (i = 0; i < 8; ++i) {
    points[i] = f[i];
  }
  al_draw_spline(points, *ac, thickness);
  return mrb_nil_value();
}

void
mruby_allegro_primitives_init(mrb_state *mrb)
{
  struct RClass *am = ALLEGRO_MODULE;
  mrb_define_module_function(mrb, am, "draw_line", draw_line, ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_triangle", draw_triangle, ARGS_REQ(8));
  mrb_define_module_function(mrb, am, "draw_filled_triangle", draw_filled_triangle, ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_rectangle", draw_rectangle, ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_filled_rectangle", draw_filled_rectangle, ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_rounded_rectangle", draw_rounded_rectangle, ARGS_REQ(8));
  mrb_define_module_function(mrb, am, "draw_filled_rounded_rectangle", draw_filled_rounded_rectangle, ARGS_REQ(7));
  mrb_define_module_function(mrb, am, "draw_circle", draw_circle, ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_filled_circle", draw_filled_circle, ARGS_REQ(4));
  mrb_define_module_function(mrb, am, "draw_ellipse", draw_ellipse, ARGS_REQ(6));
  mrb_define_module_function(mrb, am, "draw_filled_ellipse", draw_filled_ellipse, ARGS_REQ(5));
  mrb_define_module_function(mrb, am, "draw_spline", draw_spline, ARGS_REQ(10));
}
