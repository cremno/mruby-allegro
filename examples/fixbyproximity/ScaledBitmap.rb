width, height = 640, 480
done = false
scale = 2
Al::Display.create width, height
image = Al::Bitmap.load 'selbstgemalt.JPG'
image_width, image_height = image.width, image.height
x, y = width / 2 - image_width / 2, height / 2 - image_height / 2
event_queue = Al::EventQueue.create
event_queue.register Al::Keyboard.event_source
until done
  ev = event_queue.wait_for_event
  case ev.type
  when ALLEGRO_EVENT_KEY_DOWN
    case ev.keycode
    when ALLEGRO_KEY_ESCAPE
      done = true
    when ALLEGRO_KEY_UP
      scale += 0.5
    when ALLEGRO_KEY_DOWN
      scale -= 0.5
    end
  end
  image.draw_scaled 0, 0, image_width, image_height, x, y, image_width * scale, image_height * scale
  Al::Display.flip
  Al.clear_to_color
end
