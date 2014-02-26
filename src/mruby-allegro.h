#ifndef MRUBY_ALLEGRO_H
#define MRUBY_ALLEGRO_H

#ifdef MRB_INT16
#error "MRB_INT16 is not supported"
#endif

#define M_ALLEGRO             (mrb_module_get(mrb, "Al"))
#define E_ALLEGRO_ERROR       (mrb_class_get(mrb, "AllegroError"))
#define C_ALLEGRO_BITMAP      (mrbal_get_const(mrb, "Bitmap"))
#define C_ALLEGRO_COLOR       (mrbal_get_const(mrb, "Color"))
#define C_ALLEGRO_CONFIG      (mrbal_get_const(mrb, "Config"))
#define C_ALLEGRO_DISPLAY     (mrbal_get_const(mrb, "Display"))
#define C_ALLEGRO_EVENT       (mrbal_get_const(mrb, "Event"))
#define C_ALLEGRO_EVENTSOURCE (mrbal_get_const(mrb, "EventSource"))
#define C_ALLEGRO_EVENTQUEUE  (mrbal_get_const(mrb, "EventQueue"))
#define C_ALLEGRO_FONT        (mrbal_get_const(mrb, "Font"))
#define C_ALLEGRO_TIMEOUT     (mrbal_get_const(mrb, "Timeout"))

#define Check_Destroyed(mrb, obj, t, sval) do {                \
  Data_Get_Struct(mrb, obj, &mrbal_ ## t ## _data_type, sval); \
  if (!sval) {                                                 \
    mrb_raise(mrb, E_ALLEGRO_ERROR, #t " is destroyed");       \
  }                                                            \
} while(0)

#define Check_Destroyed2(mrb, t, sval) do {              \
  if (!sval) {                                           \
    mrb_raise(mrb, E_ALLEGRO_ERROR, #t " is destroyed"); \
  }                                                      \
} while(0)

#define Destroyed(o) (mrb_bool_value(!DATA_PTR(o)))

extern struct mrb_data_type const mrbal_bitmap_data_type;
extern struct mrb_data_type const mrbal_config_data_type;
extern struct mrb_data_type const mrbal_color_data_type;
extern struct mrb_data_type const mrbal_display_data_type;
extern struct mrb_data_type const mrbal_event_data_type;
extern struct mrb_data_type const mrbal_eventsource_data_type;
extern struct mrb_data_type const mrbal_eventqueue_data_type;
extern struct mrb_data_type const mrbal_font_data_type;
extern struct mrb_data_type const mrbal_timeout_data_type;

struct RClass *mrbal_get_const(mrb_state *, char const *);
mrb_value mrbal_version_to_hash(mrb_state *, uint32_t);
unsigned char mrbal_clamp_uc(mrb_int);
int mrbal_clamp_int(mrb_int);
#ifndef MRB_INT64
#define mrbal_clamp_int(i) (i)
#endif
float mrbal_clamp_f(mrb_float);
int mrbal_bitmap_get_flags(mrb_state *, unsigned, mrb_sym, mrb_sym);

#endif
