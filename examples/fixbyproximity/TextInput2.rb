width, height = 640, 480
done = false
pos_x, pos_y = width / 2, height / 2
keys = { up: false, down: false, left: false, right: false }
display = Al::Display.create width, height
event_queue = Al::EventQueue.create
event_queue.register Al::Keyboard.event_source
event_queue.register display.event_source
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
  end
  pos_y -= 10 if keys[:up]
  pos_y += 10 if keys[:down]
  pos_x -= 10 if keys[:left]
  pos_x += 10 if keys[:right]
  Al.draw_filled_rectangle pos_x, pos_y, pos_x + 30, pos_y + 30, Al::Color.rgb(255, 0, 255)
  Al::Display.flip
  Al.clear_to_color
end
