#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static void
config_free(mrb_state *mrb, void *p)
{
  if (p) {
    al_destroy_config(p);
  }
}

struct mrb_data_type const mrbal_config_data_type = { "allegro/config", config_free };

static mrb_value
config_create(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  struct RData *data;

  cfg = al_create_config();
  if (!cfg) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not create config");
  }
  data = mrb_data_object_alloc(mrb, mrb_class_ptr(self), cfg, &mrbal_config_data_type);
  return mrb_obj_value(data);
}

static mrb_value
config_destroy(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;

  cfg = DATA_PTR(self);
  if (cfg) {
    al_destroy_config(cfg);
    DATA_PTR(self) = NULL;
  }
  return mrb_nil_value();
}

static mrb_value
config_destroyed(mrb_state *mrb, mrb_value self)
{
  return Destroyed(self);
}

static mrb_value
config_load_file(mrb_state *mrb, mrb_value self)
{
  char *filename;
  ALLEGRO_CONFIG *cfg;
  struct RData *data;

  mrb_get_args(mrb, "z", &filename);
  cfg = al_load_config_file(filename);
  if (!cfg) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not load config");
  }
  data = mrb_data_object_alloc(mrb, mrb_class_ptr(self), cfg, &mrbal_config_data_type);
  return mrb_obj_value(data);
}

static mrb_value
config_save_file(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  char *filename;

  Check_Destroyed(mrb, self, config, cfg);
  mrb_get_args(mrb, "z", &filename);
  if (!al_save_config_file(filename, cfg)) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "could not save config to file");
    return mrb_false_value();
  }
  return mrb_true_value();
}

static mrb_value
config_add_section(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  char *name;

  Check_Destroyed(mrb, self, config, cfg);
  mrb_get_args(mrb, "z", &name);
  al_add_config_section(cfg, name);
  return mrb_nil_value();
}

static mrb_value
config_add_comment(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  char *section;
  char *comment;

  Check_Destroyed(mrb, self, config, cfg);
  mrb_get_args(mrb, "zz", &section, &comment);
  al_add_config_comment(cfg, section, comment);
  return mrb_nil_value();
}

static mrb_value
config_get_value(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  char *section;
  char *key;
  const char *value;

  Check_Destroyed(mrb, self, config, cfg);
  mrb_get_args(mrb, "zz", &section, &key);
  value = al_get_config_value(cfg, section, key);
  if (!value) {
    mrb_raise(mrb, E_ALLEGRO_ERROR, "section or key do not exist");
  }
  return mrb_str_new_cstr(mrb, value);
}

static mrb_value
config_set_value(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg;
  char *section;
  char *key;
  char *value;

  Check_Destroyed(mrb, self, config, cfg);
  mrb_get_args(mrb, "zzz", &section, &key, &value);
  al_set_config_value(cfg, section, key, value);
  return mrb_nil_value();
}

static mrb_value
config_merge(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *cfg1;
  mrb_value o;
  ALLEGRO_CONFIG *cfg2;
  ALLEGRO_CONFIG *cfg_new;
  struct RData *data;

  Check_Destroyed(mrb, self, config, cfg1);
  mrb_get_args(mrb, "o", &o);
  Check_Destroyed(mrb, o, config, cfg2);
  cfg_new = al_merge_config(cfg1, cfg2);
  data = mrb_data_object_alloc(mrb, mrb_obj_class(mrb, self), cfg_new, &mrbal_config_data_type);
  return mrb_obj_value(data);
}

static mrb_value
config_merge_into(mrb_state *mrb, mrb_value self)
{
  ALLEGRO_CONFIG *master;
  mrb_value o;
  ALLEGRO_CONFIG *add;

  Check_Destroyed(mrb, self, config, master);
  mrb_get_args(mrb, "o", &o);
  Check_Destroyed(mrb, o, config, add);
  al_merge_config_into(master, add);
  return self;
}

void
mruby_allegro_config_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  struct RClass *cc = mrb_define_class_under(mrb, am, "Config", mrb->object_class);
  MRB_SET_INSTANCE_TT(cc, MRB_TT_DATA);
  mrb_define_class_method(mrb, cc, "create", config_create, MRB_ARGS_NONE());
  mrb_define_alias(mrb, cc->c, "new", "create");
  mrb_define_method(mrb, cc, "destroy", config_destroy, MRB_ARGS_NONE());
  mrb_define_method(mrb, cc, "destroyed?", config_destroyed, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, cc, "load_file", config_load_file, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cc, "save_file", config_save_file, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cc, "add_section", config_add_section, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cc, "add_comment", config_add_comment, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, cc, "get_value", config_get_value, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, cc, "set_value", config_set_value, MRB_ARGS_REQ(3));
  mrb_define_method(mrb, cc, "merge", config_merge, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cc, "merge_into", config_merge_into, MRB_ARGS_REQ(1));
  mrb_define_alias(mrb, cc, "merge!", "merge_into");
}
