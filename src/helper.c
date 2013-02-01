#include <limits.h>
#include <stdint.h>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/hash.h>
#include <mruby/variable.h>
#include "mruby-allegro.h"

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
