#include <stdio.h>
#include <stdlib.h>
#include <mruby.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

void
mrb_mruby_allegro_gem_init(mrb_state* mrb)
{
  extern void mruby_allegro_display_init(mrb_state *);
  extern void mruby_allegro_events_init(mrb_state *);
  extern void mruby_allegro_graphics_init(mrb_state *);
  extern void mruby_allegro_keyboard_init(mrb_state *);
  extern void mruby_allegro_system_init(mrb_state *);
  extern void mruby_allegro_time_init(mrb_state *);
  extern void mruby_allegro_font_init(mrb_state *);
  extern void mruby_allegro_primitives_init(mrb_state *);
  extern void consts_init(mrb_state *);
  mrb_define_module(mrb, "Al");
  mrb_define_class(mrb, "AllegroError", mrb->eStandardError_class);
  mruby_allegro_display_init(mrb);
  mruby_allegro_events_init(mrb);
  mruby_allegro_graphics_init(mrb);
  mruby_allegro_keyboard_init(mrb);
  mruby_allegro_system_init(mrb);
  mruby_allegro_time_init(mrb);
  mruby_allegro_font_init(mrb);
  mruby_allegro_primitives_init(mrb);
  consts_init(mrb);
#ifdef INIT_AT_START
  if (!al_init()) {
    fputs("failed to initialize allegro!\n", stderr);
    exit(EXIT_FAILURE);
  }
  if (!al_install_keyboard()) {
    fputs("failed to install a keyboard driver!\n", stderr);
    exit(EXIT_FAILURE);
  }
  al_init_font_addon();
  if (!al_init_ttf_addon()) {
    fputs("failed to initialize allegro ttf addon!\n", stderr);
    exit(EXIT_FAILURE);
  }
  if (!al_init_primitives_addon()){
    fputs("failed to initialize allegro primitives addon!\n", stderr);
    exit(EXIT_FAILURE);
  }
#endif
}

void
mrb_mruby_allegro_gem_final(mrb_state* mrb)
{
}
