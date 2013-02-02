#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/hash.h>
#include <mruby/variable.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

void *
safe_malloc(mrb_state *mrb, size_t n)
{
  void *p = mrb_malloc(mrb, n);
  if (!p) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "memory allocation failed");
  }
  return p;
}

struct RClass *
get_allegro_const(mrb_state *mrb, const char *name, int len)
{
  return mrb_class_ptr(mrb_const_get(mrb, mrb_obj_value(M_ALLEGRO), mrb_intern2(mrb, name, len)));
}

mrb_value
version_to_hash(mrb_state *mrb, uint32_t v)
{
  mrb_value h = mrb_hash_new_capa(mrb, 4);
  mrb_hash_set(mrb, h, mrb_symbol_value(mrb_intern2(mrb, "major",    5)), mrb_fixnum_value((v >> 24) & 0xff));
  mrb_hash_set(mrb, h, mrb_symbol_value(mrb_intern2(mrb, "minor",    5)), mrb_fixnum_value((v >> 16) & 0xff));
  mrb_hash_set(mrb, h, mrb_symbol_value(mrb_intern2(mrb, "revision", 8)), mrb_fixnum_value((v >>  8) & 0xff));
  mrb_hash_set(mrb, h, mrb_symbol_value(mrb_intern2(mrb, "release",  7)), mrb_fixnum_value((v >>  0) & 0xff));
  return h;
}

unsigned char
clamp_uc(mrb_int i)
{
  if (i > UCHAR_MAX) {
    return UCHAR_MAX;
  } else if (i < 0) {
    return 0;
  } else {
    return i;
  }
}

int
clamp_int(mrb_int i)
{
  if (sizeof(int) <= sizeof(mrb_int)) {
  	return i;
  } else {
    if (i > INT_MAX) {
      return INT_MAX;
    } else if (i < INT_MIN) {
      return INT_MIN;
    } else {
      return i;
    }
  }
}

float
clamp_f(mrb_float i)
{
  if (i > 1.f) {
    return 1.f;
  } else if (i < 0.f) {
    return 0.f;
  } else {
    return (float)i;
  }
}

int
bitmap_get_flags(mrb_state *mrb, unsigned argc, mrb_sym s1, mrb_sym s2) 
{
  mrb_sym fh = mrb_intern2(mrb, "flip_horizontal", 15);
  mrb_sym fv = mrb_intern2(mrb, "flip_vertical", 13);
  int flags = 0;
  switch (argc) {
  case 2:
    if (s2 == fh) {
      flags |= ALLEGRO_FLIP_HORIZONTAL;
    } else if (s2 == fv) {
      flags |= ALLEGRO_FLIP_VERTICAL;
    }
    // FALL TROUGH
  case 1:
    if (s1 == fh) {
      flags |= ALLEGRO_FLIP_HORIZONTAL;
    } else if (s1 == fv) {
      flags |= ALLEGRO_FLIP_VERTICAL;
    }
    break;
  default:
    break;
  }
  return flags;
}
