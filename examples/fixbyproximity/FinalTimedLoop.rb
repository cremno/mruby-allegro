width, height = 640, 480
done, redraw = false, true
pos_x, pos_y = width / 2, height / 2
keys = { up: false, down: false, left: false, right: false }
color = Al::Color.rgb 255, 0, 255
display = Al::Display.new width, height
timer = Al::Timer.new 1 / 60
event_queue = Al::EventQueue.new
event_queue.register Al::Keyboard.event_source
event_queue.register display.event_source
event_queue.register timer.event_source
timer.start
until done
  ev = event_queue.wait_for_event
  case ev.type
  when ALLEGRO_EVENT_KEY_DOWN
    case ev.keycode
    when ALLEGRO_KEY_UP
      keys[:up] = true
    when ALLEGRO_KEY_DOWN
      keys[:down] = true
    when ALLEGRO_KEY_RIGHT
      keys[:right] = true
    when ALLEGRO_KEY_LEFT
      keys[:left] = true
    end
  when ALLEGRO_EVENT_KEY_UP
    case ev.keycode
    when ALLEGRO_KEY_UP
      keys[:up] = false
    when ALLEGRO_KEY_DOWN
      keys[:down] = false
    when ALLEGRO_KEY_RIGHT
      keys[:right] = false
    when ALLEGRO_KEY_LEFT
      keys[:left] = false
    when ALLEGRO_KEY_ESCAPE
      done = true
    end
  when ALLEGRO_EVENT_DISPLAY_CLOSE
  	done = true
  when ALLEGRO_EVENT_TIMER
  	pos_y -= 10 if keys[:up]
    pos_y += 10 if keys[:down]
    pos_x -= 10 if keys[:left]
    pos_x += 10 if keys[:right]
  	redraw = true
  end
  if redraw && event_queue.empty?
    redraw = false
    Al.draw_filled_rectangle pos_x, pos_y, pos_x + 30, pos_y + 30, color
    Al::Display.flip
    Al.clear_to_color
  end
end
