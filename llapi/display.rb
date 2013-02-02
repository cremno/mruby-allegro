def al_create_display(w, h)
  Al::Display.new(w, h)
end

def al_destroy_display(d)
  d.destroy
end

def al_flip_display
  Al::Display.flip
end

def al_get_display_height(d)
  d.height
end

def al_get_display_width(d)
  d.width
end

def al_get_window_position(d)
  d.window_position
end

def al_inhibit_screensaver(b)
  Al.inhibit_screensaver = b
end

def al_resize_display(d, w, h)
  d.resize(w, h)
end

def al_set_window_title(d, t)
  d.window_title = t
end

def al_set_window_position(d, x, y)
  d.window_position = [x, y]
end

def al_wait_for_vsync
  Al.wait_for_vsync
end
