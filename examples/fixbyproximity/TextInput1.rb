width, height = 640, 480
done = false
pos_x, pos_y = width / 2, height / 2
Al::Display.create width, height
event_queue = Al::EventQueue.create
event_queue.register Al::Keyboard.event_source
until done
  ev = event_queue.wait_for_event#return KeyboardEvent instead of Event?
  case ev.type
  when ALLEGRO_EVENT_KEY_DOWN
    case ev.keycode
    when ALLEGRO_KEY_UP
      pos_y -= 10
    when ALLEGRO_KEY_DOWN
      pos_y += 10
    when ALLEGRO_KEY_RIGHT
      pos_x += 10
    when ALLEGRO_KEY_LEFT
      pos_x -= 10
    end
  when ALLEGRO_EVENT_KEY_UP
    done = ev.keycode == ALLEGRO_KEY_ESCAPE
  end
  Al.draw_filled_rectangle pos_x, pos_y, pos_x + 30, pos_y + 30, Al::Color.rgb(255, 0, 255)
  Al::Display.flip
  Al.clear_to_color
end
