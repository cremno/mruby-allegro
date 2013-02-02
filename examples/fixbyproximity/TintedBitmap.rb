width, height = 640, 480
done = false
scale = 2
Al::Display.create width, height
image = Al::Bitmap.load 'selbstgemalt.JPG'
image_width, image_height = image.width, image.height
x, y = width / 2 - image_width / 2, height / 2 - image_height / 2
color = Al::Color.rgba 255, 0, 0, 51
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
      y -= 10
    when ALLEGRO_KEY_DOWN
      y += 10
    when ALLEGRO_KEY_LEFT
      x -= 10
    when ALLEGRO_KEY_RIGHT
      x += 10
    end
  end
  image.draw width / 2 - image_width / 2, height / 2 - image_height / 2
  image.draw_tinted color, x, y
  Al::Display.flip
  Al.clear_to_color
end
