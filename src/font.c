#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "mruby-allegro.h"

static void
font_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_font(p);
  }
}

struct mrb_data_type font_data_type = { "allegro/font", font_free };

static mrb_value
initialize(mrb_state *mrb, mrb_value self)
{
  mrb_value s;
  mrb_int i;
  mrb_value *rv;
  mrb_int rc;
  ALLEGRO_FONT *f;
  DATA_TYPE(self) = &font_data_type;
  DATA_PTR(self) = NULL;
  mrb_get_args(mrb, "Si|*", &s, &i, &rv, &rc);
  f = al_load_font(mrb_string_value_cstr(mrb, &s), i, 0);
  if (!f) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "failed to load font");
  }
  DATA_PTR(self) = f;
  return self;
}

static mrb_value
draw_text(mrb_state *mrb, mrb_value self)
{
  mrb_value f;
  mrb_value c;
  mrb_float x;
  mrb_float y;
  mrb_value s;
  mrb_value *rv;
  mrb_int rc;
  ALLEGRO_FONT *af;
  ALLEGRO_COLOR *ac;
  mrb_get_args(mrb, "ooffS|*", &f, &c, &x, &y, &s, &rv, &rc);
  Data_Get_Struct(mrb, f, &font_data_type, af);
  Data_Get_Struct(mrb, c, &color_data_type, ac);
  al_draw_text(af, *ac, x, y, 0, mrb_string_value_cstr(mrb, &s));
  return mrb_nil_value();
}

void
mruby_allegro_font_init(mrb_state *mrb)
{
  struct RClass *am = ALLEGRO_MODULE;
  struct RClass *fc = mrb_define_class_under(mrb, am, "Font", mrb->object_class);
  MRB_SET_INSTANCE_TT(fc, MRB_TT_DATA);
  mrb_define_alias(mrb, fc->c, "load", "new");
  mrb_define_method(mrb, fc, "initialize", initialize, ARGS_REQ(2) | ARGS_REST());
  mrb_define_class_method(mrb, am, "draw_text", draw_text, ARGS_REQ(5) | ARGS_OPT(1));
}