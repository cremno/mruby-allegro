#ifndef MRUBY_ALLEGRO_H
#define MRUBY_ALLEGRO_H

#ifndef mrb_bool_value
#define mrb_bool_value(val) ((val) ? mrb_true_value() : mrb_false_value())
#endif

#define ALLEGRO_MODULE  (mrb_class_obj_get(mrb, "Al"))
#define E_ALLEGRO_ERROR (mrb_class_obj_get(mrb, "AllegroError"))

extern struct mrb_data_type color_data_type;
extern struct mrb_data_type display_data_type;
extern struct mrb_data_type font_data_type;

uint8_t clamp_u8(mrb_int);
int clamp_int(mrb_int);

#endif
