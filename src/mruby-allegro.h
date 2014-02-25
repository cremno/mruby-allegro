#ifndef MRUBY_ALLEGRO_H
#define MRUBY_ALLEGRO_H

#define M_ALLEGRO (mrb_module_get(mrb, "Al"))
#define E_ALLEGRO_ERROR (mrb_class_get(mrb, "AllegroError"))
#define C_ALLEGRO_BITMAP (get_allegro_const(mrb, "Bitmap"))
#define C_ALLEGRO_COLOR (get_allegro_const(mrb, "Color"))
#define C_ALLEGRO_CONFIG (get_allegro_const(mrb, "Config"))
#define C_ALLEGRO_DISPLAY (get_allegro_const(mrb, "Display"))
#define C_ALLEGRO_EVENT (get_allegro_const(mrb, "Event"))
#define C_ALLEGRO_EVENTSOURCE (get_allegro_const(mrb, "EventSource"))
#define C_ALLEGRO_EVENTQUEUE (get_allegro_const(mrb, "EventQueue"))
#define C_ALLEGRO_FONT (get_allegro_const(mrb, "Font"))

#define Check_Destroyed(mrb, obj, t, sval) do {\
  Data_Get_Struct(mrb, obj, & t ## _data_type, sval);\
  if (!sval) {\
    mrb_raise(mrb, E_ALLEGRO_ERROR, #t " is destroyed");\
  }\
} while(0)

#define Destroyed(o) (mrb_bool_value(!DATA_PTR(o)))

extern struct mrb_data_type const bitmap_data_type;
extern struct mrb_data_type const config_data_type;
extern struct mrb_data_type const color_data_type;
extern struct mrb_data_type const display_data_type;
extern struct mrb_data_type const event_data_type;
extern struct mrb_data_type const eventsource_data_type;
extern struct mrb_data_type const eventqueue_data_type;
extern struct mrb_data_type const font_data_type;

#include <mruby/class.h>
#include <mruby/variable.h>
static inline struct RClass *
get_allegro_const(mrb_state *mrb, char const *name)
{
  return mrb_class_ptr(mrb_const_get(mrb, mrb_obj_value(M_ALLEGRO), mrb_intern(mrb, name, strlen(name))));
}

mrb_value version_to_hash(mrb_state *, uint32_t);
unsigned char clamp_uc(mrb_int);
int clamp_int(mrb_int);
float clamp_f(mrb_float);
int bitmap_get_flags(mrb_state *, unsigned, mrb_sym, mrb_sym);

#endif
