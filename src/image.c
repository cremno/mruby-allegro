#include <mruby.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "mruby-allegro.h"

static mrb_value
init(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(al_init_image_addon());
}

static mrb_value
shutdown_addon(mrb_state *mrb, mrb_value self)
{
  al_shutdown_image_addon();
  return mrb_nil_value();
}

static mrb_value
version(mrb_state *mrb, mrb_value self)
{
  return mrbal_version_to_hash(mrb, al_get_allegro_image_version());
}

void
mruby_allegro_image_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  mrb_define_class_method(mrb, am, "init_image_addon", init, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, am, "shutdown_image_addon", shutdown_addon, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, am, "image_version", version, MRB_ARGS_NONE());
}
