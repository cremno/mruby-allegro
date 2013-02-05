#include <stdio.h>
#include <mruby.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static const ALLEGRO_COLOR black = { 0.f, 0.f, 0.f, 1.f };

static void
color_free(mrb_state *mrb, void *p)
{
  if (p) {
    mrb_free(mrb, p);
  }
}

struct mrb_data_type color_data_type = { "allegro/color", color_free };

static void
bitmap_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_bitmap(p);
  }
}

struct mrb_data_type bitmap_data_type = { "allegro/bitmap", bitmap_free };

static mrb_value
color_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  int argc;
  ALLEGRO_COLOR *oc;
  ALLEGRO_COLOR *c;
  argc = mrb_get_args(mrb, "|o", &o);
  if (argc) {
    Data_Get_Struct(mrb, o, &color_data_type, oc);
  }
  c = safe_malloc(mrb, sizeof(*c));
  *c = !argc ? black : *oc;
  DATA_TYPE(self) = &color_data_type;
  DATA_PTR(self) = c;
  return self;
}

static mrb_value
color_map_rgb(mrb_state *mrb, mrb_value self)
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
color_map_rgba(mrb_state *mrb, mrb_value self)
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
color_map_rgb_f(mrb_state *mrb, mrb_value self)
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
color_map_rgba_f(mrb_state *mrb, mrb_value self)
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
color_unmap_rgb(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_COLOR *c;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  mrb_value ary;
  Data_Get_Struct(mrb, self, &color_data_type, c);
  al_unmap_rgb(*c, &r, &g, &b);
  ary = mrb_ary_new_capa(mrb, 3);
  mrb_ary_push(mrb, ary, mrb_fixnum_value(r));
  mrb_ary_push(mrb, ary, mrb_fixnum_value(g));
  mrb_ary_push(mrb, ary, mrb_fixnum_value(b));
  return ary;
}

static mrb_value
color_unmap_rgb_f(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_COLOR *c;
  float r;
  float g;
  float b;
  mrb_value ary;
  Data_Get_Struct(mrb, self, &color_data_type, c);
  al_unmap_rgb_f(*c, &r, &g, &b);
  ary = mrb_ary_new_capa(mrb, 3);
  mrb_ary_push(mrb, ary, mrb_float_value(r));
  mrb_ary_push(mrb, ary, mrb_float_value(g));
  mrb_ary_push(mrb, ary, mrb_float_value(b));
  return ary;
}

static mrb_value
color_unmap_rgba(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_COLOR *c;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
  mrb_value ary;
  Data_Get_Struct(mrb, self, &color_data_type, c);
  al_unmap_rgba(*c, &r, &g, &b, &a);
  ary = mrb_ary_new_capa(mrb, 4);
  mrb_ary_push(mrb, ary, mrb_fixnum_value(r));
  mrb_ary_push(mrb, ary, mrb_fixnum_value(g));
  mrb_ary_push(mrb, ary, mrb_fixnum_value(b));
  mrb_ary_push(mrb, ary, mrb_fixnum_value(a));
  return ary;
}

static mrb_value
color_unmap_rgba_f(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_COLOR *c;
  float r;
  float g;
  float b;
  float a;
  mrb_value ary;
  Data_Get_Struct(mrb, self, &color_data_type, c);
  al_unmap_rgba_f(*c, &r, &g, &b, &a);
  ary = mrb_ary_new_capa(mrb, 4);
  mrb_ary_push(mrb, ary, mrb_float_value(r));
  mrb_ary_push(mrb, ary, mrb_float_value(g));
  mrb_ary_push(mrb, ary, mrb_float_value(b));
  mrb_ary_push(mrb, ary, mrb_float_value(a));
  return ary;
}

static mrb_value
color_inspect(mrb_state *mrb, mrb_value self)
{
  char buf[128];
  ALLEGRO_COLOR *c;
  const char *s;
  int len;
  Data_Get_Struct(mrb, self, &color_data_type, c);
  s = mrb_obj_classname(mrb, self);
  len = snprintf(buf, sizeof(buf), "#<%s: r=%f, g=%f, b=%f, a=%f>", s, c->r, c->g, c->b, c->a);
  return mrb_str_new(mrb, buf, len);
}

#define ATTR(attr) static mrb_value \
color_ ## attr ## _getter(mrb_state *mrb, mrb_value self)\
{\
  ALLEGRO_COLOR *c;\
  Data_Get_Struct(mrb, self, &color_data_type, c);\
  return mrb_float_value(c->attr);\
}\
static mrb_value \
color_ ## attr ## _setter(mrb_state *mrb, mrb_value self)\
{\
  ALLEGRO_COLOR *c;\
  mrb_float f;\
  Data_Get_Struct(mrb, self, &color_data_type, c);\
  mrb_get_args(mrb, "f", &f);\
  c->attr = clamp_f(f);\
  return mrb_float_value(f);\
}

ATTR(r)
ATTR(g)
ATTR(b)
ATTR(a)

#undef ATTR

static mrb_value
bitmap_unlock(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, bitmap, b);
  al_unlock_bitmap(b);
  return mrb_nil_value();
}

static mrb_value
bitmap_create(mrb_state *mrb, mrb_value self)
{
  mrb_int w;
  mrb_int h;
  ALLEGRO_BITMAP *b;
  mrb_get_args(mrb, "ii", &w, &h);
  b = al_create_bitmap(clamp_int(w), clamp_int(h));
  if (!b) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "creating bitmap failed");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &bitmap_data_type, b));
}

static mrb_value
bitmap_destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b = DATA_PTR(self);
  if (b) {
    al_destroy_bitmap(b);
    DATA_PTR(self) = NULL;
  }
  return mrb_nil_value();
}

static mrb_value
bitmap_destroyed(mrb_state *mrb, mrb_value self)
{
  return Destroyed(self);
}

static mrb_value
bitmap_height(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, bitmap, b);
  return mrb_fixnum_value(al_get_bitmap_height(b));
}

static mrb_value
bitmap_width(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, bitmap, b);
  return mrb_fixnum_value(al_get_bitmap_width(b));
}

static mrb_value
bitmap_get_pixel(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_int x;
  mrb_int y;
  ALLEGRO_COLOR *c;
  Check_Destroyed(mrb, self, bitmap, b);
  mrb_get_args(mrb, "ii", &x, &y);
  c = safe_malloc(mrb, sizeof(*c));
  *c = al_get_pixel(b, clamp_int(x), clamp_int(y));
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_COLOR, &color_data_type, c));
}

static mrb_value
bitmap_locked(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, bitmap, b);
  return mrb_bool_value(al_is_bitmap_locked(b));
}

static mrb_value
bitmap_compatible(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  Check_Destroyed(mrb, self, bitmap, b);
  return mrb_bool_value(al_is_compatible_bitmap(b));
}

static mrb_value
clear_to_color(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  if (!mrb_get_args(mrb, "|o", &o)) {
    al_clear_to_color(black);
  } else {
    ALLEGRO_COLOR *c;
    Data_Get_Struct(mrb, o, &color_data_type, c);
    al_clear_to_color(*c);
  }
  return mrb_nil_value();
}

static mrb_value
bitmap_draw(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float dx;
  mrb_float dy;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "ff|nn", &dx, &dy, &flag1, &flag2) - 2;
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_bitmap(b, dx, dy, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  mrb_float dx;
  mrb_float dy;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "off|nn", &o, &dx, &dy, &flag1, &flag2) - 3;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_bitmap(b, *tint, dx, dy, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_region(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float sx;
  mrb_float sy;
  mrb_float sw;
  mrb_float sh;
  mrb_float dx;
  mrb_float dy;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "ffffff|nn", &sx, &sy, &sw, &sh, &dx, &dy, &flag1, &flag2) - 6;
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_bitmap_region(b, sx, sy, sw, sh, dx, dy, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted_region(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  mrb_float sx;
  mrb_float sy;
  mrb_float sw;
  mrb_float sh;
  mrb_float dx;
  mrb_float dy;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "offffff|nn", &o, &sx, &sy, &sw, &sh, &dx, &dy, &flag1, &flag2) - 7;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_bitmap_region(b, *tint, sx, sy, sw, sh, dx, dy, flags);
  return mrb_nil_value();
}

static mrb_value
draw_pixel(mrb_state *mrb, mrb_value self)
{
  mrb_float x;
  mrb_float y;
  mrb_value o;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "ffo", &x, &y, &o);
  Data_Get_Struct(mrb, o, &color_data_type, c);
  al_draw_pixel(x, y, *c);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_rotated(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float cx;
  mrb_float cy;
  mrb_float dx;
  mrb_float dy;
  mrb_float angle;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "fffff|nn", &cx, &cy, &dx, &dy, &angle, &flag1, &flag2) - 5;
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_rotated_bitmap(b, cx, cy, dx, dy, angle, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted_rotated(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  mrb_float cx;
  mrb_float cy;
  mrb_float dx;
  mrb_float dy;
  mrb_float angle;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "cfffff|nn", &o, &cx, &cy, &dx, &dy, &angle, &flag1, &flag2) - 6;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_rotated_bitmap(b, *tint, cx, cy, dx, dy, angle, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_scaled_rotated(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float cx;
  mrb_float cy;
  mrb_float dx;
  mrb_float dy;
  mrb_float xscale;
  mrb_float yscale;
  mrb_float angle;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "fffffff|nn", &cx, &cy, &dx, &dy, &xscale, &yscale, &angle, &flag1, &flag2) - 7;
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_scaled_rotated_bitmap(b, cx, cy, dx, dy, xscale, yscale, angle, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted_scaled_rotated(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  mrb_float cx;
  mrb_float cy;
  mrb_float dx;
  mrb_float dy;
  mrb_float xscale;
  mrb_float yscale;
  mrb_float angle;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "offfffff|nn", &o, &cx, &cy, &dx, &dy, &xscale, &yscale, &angle, &flag1, &flag2) - 8;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_scaled_rotated_bitmap(b, *tint, cx, cy, dx, dy, xscale, yscale, angle, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted_scaled_rotated_region(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float sx;
  mrb_float sy;
  mrb_float sw;
  mrb_float sh;
  mrb_value o;
  mrb_float cx;
  mrb_float cy;
  mrb_float dx;
  mrb_float dy;
  mrb_float xscale;
  mrb_float yscale;
  mrb_float angle;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "ffffofffffff|nn", &sx, &sy, &sw, &sh, &o, &cx, &cy, &dx, &dy, &xscale, &yscale, &angle, &flag1, &flag2) - 12;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_scaled_rotated_bitmap_region(b, sx, sy, sw, sh, *tint, cx, cy, dx, dy, xscale, yscale, angle, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_scaled(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_float sx;
  mrb_float sy;
  mrb_float sw;
  mrb_float sh;
  mrb_float dx;
  mrb_float dy;
  mrb_float dw;
  mrb_float dh;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "ffffffff|nn", &sx, &sy, &sw, &sh, &dx, &dy, &dw, &dh, &flag1, &flag2) - 8;
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_scaled_bitmap(b, sx, sy, sw, sh, dx, dy, dw, dh, flags);
  return mrb_nil_value();
}

static mrb_value
bitmap_draw_tinted_scaled(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  mrb_float sx;
  mrb_float sy;
  mrb_float sw;
  mrb_float sh;
  mrb_float dx;
  mrb_float dy;
  mrb_float dw;
  mrb_float dh;
  mrb_sym flag1;
  mrb_sym flag2;
  int argc;
  ALLEGRO_COLOR *tint;
  int flags;
  Check_Destroyed(mrb, self, bitmap, b);
  argc = mrb_get_args(mrb, "offffffff|nn", &o, &sx, &sy, &sw, &sh, &dx, &dy, &dw, &dh, &flag1, &flag2) - 9;
  Data_Get_Struct(mrb, o, &color_data_type, tint);
  flags = argc > 0 ? bitmap_get_flags(mrb, argc, flag1, flag2) : 0;
  al_draw_tinted_scaled_bitmap(b, *tint, sx, sy, sw, sh, dx, dy, dw, dh, flags);
  return mrb_nil_value();
}

static mrb_value
put_pixel(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  mrb_value o;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "iio", &x, &y, &o);
  Data_Get_Struct(mrb, o, &color_data_type, c);
  al_put_pixel(clamp_int(x), clamp_int(y), *c);
  return mrb_nil_value();
}

static mrb_value
put_blended_pixel(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  mrb_value o;
  ALLEGRO_COLOR *c;
  mrb_get_args(mrb, "iio", &x, &y, &o);
  Data_Get_Struct(mrb, o, &color_data_type, c);
  al_put_blended_pixel(clamp_int(x), clamp_int(y), *c);
  return mrb_nil_value();
}

static mrb_value
target_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  if (mrb_type(o) != MRB_TT_DATA) {
    goto type_error;
  }
  if (DATA_TYPE(o) == &bitmap_data_type) {
    ALLEGRO_BITMAP *b;
    Check_Destroyed(mrb, o, bitmap, b);
    al_set_target_bitmap(b);
  } else if (DATA_TYPE(o) == &display_data_type) {
    ALLEGRO_DISPLAY *d;
    Check_Destroyed(mrb, o, display, d);
    al_set_target_backbuffer(d);
  } else {
type_error:
    mrb_raisef(mrb, E_TYPE_ERROR, "expected %s or %s", bitmap_data_type.struct_name, display_data_type.struct_name);
  }
  return o;
}

static mrb_value
display_current(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_DISPLAY *d;
  d = al_get_current_display();
  // if (!d) {
  //   mrb_raise(E_ALLEGRO_ERROR, "none current display for the calling thread");
  // }
  return mrb_obj_value(Data_Wrap_Struct(mrb, C_ALLEGRO_DISPLAY, &display_data_type, d));
}

static mrb_value
blender_getter(mrb_state *mrb, mrb_value self)
{
  int op;
  int src;
  int dst;
  mrb_value a;
  al_get_blender(&op, &src, &dst);
  a = mrb_ary_new_capa(mrb, 3);
  mrb_ary_push(mrb, a, mrb_fixnum_value(op));
  mrb_ary_push(mrb, a, mrb_fixnum_value(src));
  mrb_ary_push(mrb, a, mrb_fixnum_value(dst));
  return a;
}

static mrb_value
separate_blender_getter(mrb_state *mrb, mrb_value self)
{
  int op;
  int src;
  int dst;
  int alpha_op;
  int alpha_src;
  int alpha_dst;
  mrb_value a;
  al_get_separate_blender(&op, &src, &dst, &alpha_op, &alpha_src, &alpha_dst);
  a = mrb_ary_new_capa(mrb, 6);
  mrb_ary_push(mrb, a, mrb_fixnum_value(op));
  mrb_ary_push(mrb, a, mrb_fixnum_value(src));
  mrb_ary_push(mrb, a, mrb_fixnum_value(dst));
  mrb_ary_push(mrb, a, mrb_fixnum_value(alpha_op));
  mrb_ary_push(mrb, a, mrb_fixnum_value(alpha_src));
  mrb_ary_push(mrb, a, mrb_fixnum_value(alpha_dst));
  return a;
}

static mrb_value
blender_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value a;
  mrb_value *e;
  mrb_get_args(mrb, "A", &a);
  if (RARRAY_LEN(a) != 3) {
    goto invalid;
  }
  e = RARRAY_PTR(a);
  if (mrb_fixnum_p(e[0]) && mrb_fixnum_p(e[1]) && mrb_fixnum_p(e[2])) {
    al_set_blender(mrb_fixnum(e[0]), mrb_fixnum(e[1]), mrb_fixnum(e[2]));
    return a;
  }
invalid:
  mrb_raise(mrb, E_ALLEGRO_ERROR, "invalid blending mode");
  return mrb_nil_value();  // unreachable
}

static mrb_value
separate_blender_setter(mrb_state *mrb, mrb_value self)
{
  mrb_value a;
  mrb_value *e;
  mrb_get_args(mrb, "A", &a);
  if (RARRAY_LEN(a) != 6) {
    goto invalid;
  }
  e = RARRAY_PTR(a);
  if (mrb_fixnum_p(e[0]) && mrb_fixnum_p(e[1]) && mrb_fixnum_p(e[2]) &&
      mrb_fixnum_p(e[3]) && mrb_fixnum_p(e[4]) && mrb_fixnum_p(e[5])) {
    al_set_separate_blender(mrb_fixnum(e[0]), mrb_fixnum(e[1]), mrb_fixnum(e[2]),
      mrb_fixnum(e[3]), mrb_fixnum(e[4]), mrb_fixnum(e[5]));
    return a;
  }
invalid:
  mrb_raise(mrb, E_ALLEGRO_ERROR, "invalid blending mode");
  return mrb_nil_value();  // unreachable
}

static mrb_value
convert_mask_to_alpha(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  mrb_value o;
  ALLEGRO_COLOR *c;
  Check_Destroyed(mrb, self, bitmap, b);
  mrb_get_args(mrb, "o", &o);
  Data_Get_Struct(mrb, o, &color_data_type, c);
  al_convert_mask_to_alpha(b, *c);
  return mrb_nil_value();
}

static mrb_value
hold_drawing(mrb_state *mrb, mrb_value self)
{
  int b;
  mrb_get_args(mrb, "b", &b);
  al_hold_bitmap_drawing(b);
  return mrb_nil_value();
}

static mrb_value
drawing_held(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_is_bitmap_drawing_held());
}

static mrb_value
bitmap_load(mrb_state *mrb, mrb_value self)
{
  char *s;
  ALLEGRO_BITMAP *b;
  mrb_get_args(mrb, "z", &s);
  b = al_load_bitmap(s);
  if (!b) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "loading bitmap failed");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &bitmap_data_type, b));
}

static mrb_value
bitmap_save(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_BITMAP *b;
  char *s;
  Check_Destroyed(mrb, self, bitmap, b);
  mrb_get_args(mrb, "z", &s);
  if (!al_save_bitmap(s, b)) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "saving bitmap failed");
  }
  return mrb_nil_value();
}

void
mruby_allegro_graphics_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *cc = mrb_define_class_under(mrb, am, "Color", mrb->object_class);
  struct RClass *bc = mrb_define_class_under(mrb, am, "Bitmap", mrb->object_class);
  MRB_SET_INSTANCE_TT(cc, MRB_TT_DATA);
  MRB_SET_INSTANCE_TT(bc, MRB_TT_DATA);
  mrb_define_method(mrb, cc, "initialize", color_initialize, ARGS_OPT(1));
  mrb_define_class_method(mrb, cc, "rgb", color_map_rgb, ARGS_REQ(3));
  mrb_define_class_method(mrb, cc, "rgba", color_map_rgba, ARGS_REQ(4));
  mrb_define_class_method(mrb, cc, "rgb_f", color_map_rgb_f, ARGS_REQ(3));
  mrb_define_class_method(mrb, cc, "rgba_f", color_map_rgba_f, ARGS_REQ(4));
  mrb_define_method(mrb, cc, "rgb", color_unmap_rgb, ARGS_NONE());
  mrb_define_method(mrb, cc, "rgb_f", color_unmap_rgb_f, ARGS_NONE());
  mrb_define_method(mrb, cc, "rgba", color_unmap_rgba, ARGS_NONE());
  mrb_define_method(mrb, cc, "rgba_f", color_unmap_rgba_f, ARGS_NONE());
  mrb_define_method(mrb, cc, "inspect", color_inspect, ARGS_NONE());
  mrb_define_method(mrb, cc, "r", color_r_getter, ARGS_NONE());
  mrb_define_method(mrb, cc, "g", color_g_getter, ARGS_NONE());
  mrb_define_method(mrb, cc, "b", color_b_getter, ARGS_NONE());
  mrb_define_method(mrb, cc, "a", color_a_getter, ARGS_NONE());
  mrb_define_method(mrb, cc, "r=", color_r_setter, ARGS_REQ(1));
  mrb_define_method(mrb, cc, "g=", color_g_setter, ARGS_REQ(1));
  mrb_define_method(mrb, cc, "b=", color_b_setter, ARGS_REQ(1));
  mrb_define_method(mrb, cc, "a=", color_a_setter, ARGS_REQ(1));
  mrb_define_method(mrb, bc, "unlock", bitmap_unlock, ARGS_NONE());
  mrb_undef_class_method(mrb, bc, "new");
  mrb_define_class_method(mrb, bc, "create", bitmap_create, ARGS_REQ(2));
  mrb_define_method(mrb, bc, "destroy", bitmap_destroy, ARGS_NONE());
  mrb_define_method(mrb, bc, "destroyed?", bitmap_destroyed, ARGS_NONE());
  mrb_define_method(mrb, bc, "height", bitmap_height, ARGS_NONE());
  mrb_define_method(mrb, bc, "width", bitmap_width, ARGS_NONE());
  mrb_define_method(mrb, bc, "get_pixel", bitmap_get_pixel, ARGS_REQ(2));
  mrb_define_method(mrb, bc, "locked?", bitmap_locked, ARGS_NONE());
  mrb_define_method(mrb, bc, "compatible?", bitmap_compatible, ARGS_NONE());
  mrb_define_class_method(mrb, am, "clear_to_color", clear_to_color, ARGS_OPT(1));
  mrb_define_method(mrb, bc, "draw", bitmap_draw, ARGS_REQ(2) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted", bitmap_draw_tinted, ARGS_REQ(3) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_region", bitmap_draw_region, ARGS_REQ(6) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted_region", bitmap_draw_tinted_region, ARGS_REQ(7) | ARGS_OPT(2));
  mrb_define_class_method(mrb, am, "draw_pixel", draw_pixel, ARGS_REQ(3));
  mrb_define_method(mrb, bc, "draw_rotated", bitmap_draw_rotated, ARGS_REQ(5) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted_rotated", bitmap_draw_tinted_rotated, ARGS_REQ(6) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_scaled_rotated", bitmap_draw_scaled_rotated, ARGS_REQ(7) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted_scaled_rotated", bitmap_draw_tinted_scaled_rotated, ARGS_REQ(8) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted_scaled_rotated_region", bitmap_draw_tinted_scaled_rotated_region, ARGS_REQ(12) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_scaled", bitmap_draw_scaled, ARGS_REQ(8) | ARGS_OPT(2));
  mrb_define_method(mrb, bc, "draw_tinted_scaled", bitmap_draw_tinted_scaled, ARGS_REQ(9) | ARGS_OPT(2));
  mrb_define_class_method(mrb, am, "put_pixel", put_pixel, ARGS_REQ(3));
  mrb_define_class_method(mrb, am, "put_blended_pixel", put_blended_pixel, ARGS_REQ(3));
  mrb_define_class_method(mrb, am, "target=", target_setter, ARGS_REQ(1));
  mrb_define_class_method(mrb, C_ALLEGRO_DISPLAY, "current", display_current, ARGS_NONE());
  mrb_define_class_method(mrb, am, "blender", blender_getter, ARGS_NONE());
  mrb_define_class_method(mrb, am, "separate_blender", separate_blender_getter, ARGS_NONE());
  mrb_define_class_method(mrb, am, "blender=", blender_setter, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "separate_blender=", separate_blender_setter, ARGS_REQ(1));
  mrb_define_method(mrb, bc, "convert_mask_to_alpha", convert_mask_to_alpha, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "hold_drawing", hold_drawing, ARGS_REQ(1));
  mrb_define_class_method(mrb, am, "drawing_held?", drawing_held, ARGS_NONE());
  mrb_define_class_method(mrb, bc, "load", bitmap_load, ARGS_REQ(1));
  mrb_define_method(mrb, bc, "save", bitmap_save, ARGS_REQ(1));
}
