#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "mruby-allegro.h"

static mrb_value
font_addon_init(mrb_state *mrb, mrb_value self)
{
  al_init_font_addon();
  return mrb_nil_value();
}

static mrb_value
font_addon_shutdown(mrb_state *mrb, mrb_value self)
{
  al_shutdown_font_addon();
  return mrb_nil_value();
}

static void
font_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_font(p);
  }
}

struct mrb_data_type const mrbal_font_data_type = { "allegro/font", font_free };

static mrb_value
initialize(mrb_state *mrb, mrb_value self)
{
  char *s;
  mrb_int i;
  ALLEGRO_FONT *f;
  mrb_get_args(mrb, "zi", &s, &i);
  f = al_load_font(s, mrbal_clamp_int(i), 0);
  if (!f) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not load font");
  }
  DATA_TYPE(self) = &mrbal_font_data_type;
  DATA_PTR(self) = f;
  return self;
}

static mrb_value
destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_FONT *f;
  f = DATA_PTR(self);
  if (f) {
    al_destroy_font(f);
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
line_height(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_FONT *f;
  Check_Destroyed(mrb, self, font, f);
  return mrb_fixnum_value(al_get_font_line_height(f));
}

static mrb_value
ascent(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_FONT *f;
  Check_Destroyed(mrb, self, font, f);
  return mrb_fixnum_value(al_get_font_ascent(f));
}

static mrb_value
descent(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_FONT *f;
  Check_Destroyed(mrb, self, font, f);
  return mrb_fixnum_value(al_get_font_descent(f));
}

static mrb_value
text_width(mrb_state *mrb, mrb_value self)
{
  mrb_value o;
  ALLEGRO_FONT *f;
  mrb_get_args(mrb, "o", &o);
  Check_Destroyed(mrb, o, font, f);
  return mrb_fixnum_value(al_get_text_width(f, RSTRING_PTR(self)));
}

static mrb_value
draw_text(mrb_state *mrb, mrb_value self)
{
  mrb_value of;
  mrb_value oc;
  mrb_float x;
  mrb_float y;
  char *s;
  mrb_sym alignment;
  mrb_sym integer;
  ALLEGRO_FONT *f;
  ALLEGRO_COLOR *c;
  int flags = 0;
  switch (mrb_get_args(mrb, "ooffz|nn", &of, &oc, &x, &y, &s, &alignment, &integer)) {
  case 6:
    if (integer == mrb_intern_lit(mrb, "integer")) {
      flags |= ALLEGRO_ALIGN_INTEGER;
    }
    // FALL TROUGH
  case 5:
    if (alignment == mrb_intern_lit(mrb, "center")) {
      flags |= ALLEGRO_ALIGN_CENTER;
    }
    else if (alignment == mrb_intern_lit(mrb, "right")) {
      flags |= ALLEGRO_ALIGN_RIGHT;
    }
    else if (alignment == mrb_intern_lit(mrb, "left")) {
      flags |= ALLEGRO_ALIGN_LEFT;
    }
    break;
  default:
    break;
  }
  Check_Destroyed(mrb, of, font, f);
  Data_Get_Struct(mrb, oc, &mrbal_color_data_type, c);
  al_draw_text(f, *c, x, y, flags, s);
  return mrb_nil_value();
}

static mrb_value
draw_justified_text(mrb_state *mrb, mrb_value self)
{
  mrb_value of;
  mrb_value oc;
  mrb_float x1;
  mrb_float x2;
  mrb_float y;
  mrb_float diff;
  char *s;
  mrb_sym integer;
  ALLEGRO_FONT *f;
  ALLEGRO_COLOR *c;
  int flags = 0;
  if (mrb_get_args(mrb, "ooffffz|n", &of, &oc, &x1, &x2, &y, &diff, &s, &integer) == 7) {
    if (integer == mrb_intern_lit(mrb, "integer")) {
      flags |= ALLEGRO_ALIGN_INTEGER;
    }
  }
  Check_Destroyed(mrb, of, font, f);
  Data_Get_Struct(mrb, oc, &mrbal_color_data_type, c);
  al_draw_justified_text(f, *c, x1, x2, y, diff, flags, s);
  return mrb_nil_value();
}

static mrb_value
font_addon_version(mrb_state *mrb, mrb_value self)
{
  return mrbal_version_to_hash(mrb, al_get_allegro_font_version());
}

static mrb_value
load_bitmap(mrb_state *mrb, mrb_value self)
{
  char *s;
  ALLEGRO_FONT *f;
  mrb_get_args(mrb, "z", &s);
  f = al_load_bitmap_font(s);
  if (!f) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not load bitmap font");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &mrbal_font_data_type, f));
}

static mrb_value
create_builtin(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_FONT *f;
  f = al_create_builtin_font();
  if (!f) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not create builtin font");
  }
  return mrb_obj_value(Data_Wrap_Struct(mrb, mrb_class_ptr(self), &mrbal_font_data_type, f));
}

static mrb_value
ttf_addon_init(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_init_ttf_addon());
}

static mrb_value
ttf_addon_shutdown(mrb_state *mrb, mrb_value self)
{
  al_shutdown_ttf_addon();
  return mrb_nil_value();
}

static mrb_value
ttf_addon_version(mrb_state *mrb, mrb_value self)
{
  return mrbal_version_to_hash(mrb, al_get_allegro_ttf_version());
}

void
mruby_allegro_font_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *fc = mrb_define_class_under(mrb, am, "Font", mrb->object_class);
  MRB_SET_INSTANCE_TT(fc, MRB_TT_DATA);
  mrb_define_module_function(mrb, am, "init_font_addon", font_addon_init, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "shutdown_font_addon", font_addon_shutdown, MRB_ARGS_NONE());
  mrb_define_alias(mrb, fc->c, "load", "new");
  mrb_define_method(mrb, fc, "initialize", initialize, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, fc, "destroy", destroy, MRB_ARGS_NONE());
  mrb_define_method(mrb, fc, "destroyed?", destroyed, MRB_ARGS_NONE());
  mrb_define_method(mrb, fc, "line_height", line_height, MRB_ARGS_NONE());
  mrb_define_method(mrb, fc, "ascent", ascent, MRB_ARGS_NONE());
  mrb_define_method(mrb, fc, "descent", descent, MRB_ARGS_NONE());
  mrb_define_method(mrb, mrb->string_class, "text_width", text_width, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, am, "draw_text", draw_text, MRB_ARGS_REQ(5) | MRB_ARGS_OPT(2));
  mrb_define_module_function(mrb, am, "draw_justified_text", draw_justified_text, MRB_ARGS_REQ(7) | MRB_ARGS_OPT(1));
  mrb_define_module_function(mrb, am, "font_addon_version", font_addon_version, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, fc, "load_bitmap_font", load_bitmap, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, fc, "create_builtin_font", create_builtin, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "ttf_addon_init", ttf_addon_init, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "ttf_addon_shutdown", ttf_addon_shutdown, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "ttf_addon_version", ttf_addon_version, MRB_ARGS_NONE());
}
