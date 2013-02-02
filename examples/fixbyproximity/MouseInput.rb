width, height = 640, 480
done, draw = false, true
pos_x, pos_y = width / 2, height / 2
color = Al::Color.rgb 255, 0, 255
display = Al::Display.new width, height
event_queue = Al::EventQueue.new
event_queue.register Al::Mouse.event_source
event_queue.register display.event_source
display.hide_mouse_cursor
until done
  ev = event_queue.wait_for_event
  case ev.type
  when ALLEGRO_EVENT_DISPLAY_CLOSE
    done = true
  when ALLEGRO_EVENT_MOUSE_BUTTON_DOWN
    case ev.button
    when 1
      draw = !draw
    when 2
      done = true
    end
  when ALLEGRO_EVENT_MOUSE_AXES
    pos_x, pos_y = ev.x, ev.y
  end
  if draw 
    Al.draw_filled_rectangle pos_x, pos_y, pos_x + 30, pos_y + 30, color
  end
  Al::Display.flip
  Al.clear_to_color
end
