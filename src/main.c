#include <stdio.h>
#include <stdlib.h>
#include <mruby.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

static void
quit(const char *s)
{
  fputs(s, stderr);
  exit(EXIT_FAILURE);
}

void
mrb_mruby_allegro_gem_init(mrb_state* mrb)
{
  extern void mruby_allegro_display_init(mrb_state *);
  extern void mruby_allegro_events_init(mrb_state *);
  extern void mruby_allegro_graphics_init(mrb_state *);
  extern void mruby_allegro_keyboard_init(mrb_state *);
  extern void mruby_allegro_mouse_init(mrb_state *);
  extern void mruby_allegro_system_init(mrb_state *);
  extern void mruby_allegro_time_init(mrb_state *);
  extern void mruby_allegro_timer_init(mrb_state *);
  extern void mruby_allegro_font_init(mrb_state *);
  extern void mruby_allegro_image_init(mrb_state *);
  extern void mruby_allegro_dialog_init(mrb_state *);
  extern void mruby_allegro_primitives_init(mrb_state *);
  extern void consts_init(mrb_state *);
  int ai = mrb_gc_arena_save(mrb);
  mrb_define_module(mrb, "Al");
  mrb_define_class(mrb, "AllegroError", mrb->eStandardError_class);
  mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_display_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_events_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_graphics_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_keyboard_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_mouse_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_system_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_time_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_timer_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_font_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_image_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_dialog_init(mrb); mrb_gc_arena_restore(mrb, ai);
  mruby_allegro_primitives_init(mrb); mrb_gc_arena_restore(mrb, ai);
  consts_init(mrb); mrb_gc_arena_restore(mrb, ai);
#ifdef INIT_AT_START
  if (!al_init()) {
    quit("failed to initialize allegro!\n");
  }
  if (!al_install_keyboard()) {
    quit("failed to install a keyboard driver!\n");
  }
  if (!al_install_mouse()) {
    quit("failed to install a mouse driver!\n");
  }
  al_init_font_addon();
  if (!al_init_ttf_addon()) {
    quit("failed to initialize allegro ttf addon!\n");
  }
  if (!al_init_image_addon()) {
    quit("failed to initialize allegro image addon!\n");
  }
  if (!al_init_primitives_addon()){
    quit("failed to initialize allegro primitives addon!\n");
  }
#endif
}

void
mrb_mruby_allegro_gem_final(mrb_state* mrb)
{
}
