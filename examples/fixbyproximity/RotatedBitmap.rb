width, height = 640, 480
done = false
degree = 0
Al::Display.create width, height
image = Al::Bitmap.load 'selbstgemalt.JPG'
image_width, image_height = image.width, image.height
event_queue = Al::EventQueue.create
event_queue.register Al::Keyboard.event_source
until done
  ev = event_queue.wait_for_event
  case ev.type
  when ALLEGRO_EVENT_KEY_DOWN
    case ev.keycode
    when ALLEGRO_KEY_ESCAPE
      done = true
    when ALLEGRO_KEY_LEFT
      degree -= 10
      degree = 360 if degree <= 0
    when ALLEGRO_KEY_RIGHT
      degree += 10
      degree = 0 if degree >= 360
    end
  end
  image.draw_rotated image_width / 2, image_height / 2, width / 2, height / 2, degree * Math::PI / 180
  Al::Display.flip
  Al.clear_to_color
end
