width, height = 640, 480
done = false
image_rad = 20
display = Al::Display.create width, height
image = Al::Bitmap.create image_rad * 2, image_rad * 2
Al.target = image
Al.clear_to_color Al::Color.rgb(127, 127, 127)
Al.draw_filled_rectangle image_rad, image_rad - 9, image_rad + 10, image_rad - 7, Al::Color.rgb(255, 0, 0)
Al.draw_filled_rectangle image_rad, image_rad + 9, image_rad + 10, image_rad + 7, Al::Color.rgb(255, 0, 0)
Al.draw_filled_triangle image_rad - 12, image_rad - 17, image_rad + 12, image_rad, image_rad - 12, image_rad + 17, Al::Color.rgb(0, 255, 0)
Al.draw_filled_rectangle image_rad - 12, image_rad - 2, image_rad + 15, image_rad + 2, Al::Color.rgb(0, 0, 255)
Al.target = display
event_queue = Al::EventQueue.create
event_queue.register Al::Keyboard.event_source
until done
  ev = event_queue.wait_for_event
  case ev.type
  when ALLEGRO_EVENT_KEY_DOWN
    case ev.keycode
    when ALLEGRO_KEY_ESCAPE
      done = true
    end
  end
  image.draw width / 2, height / 2
  Al::Display.flip
  Al.clear_to_color
end
