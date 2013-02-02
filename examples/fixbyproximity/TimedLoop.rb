# INFO: You have to kill/terminate the process because done is never set to true.
width, height = 640, 480
done = false
count = 0
color = Al::Color.rgb 255, 255, 255
display = Al::Display.new width, height
font18 = Al::Font.new 'arial.ttf', 18
timer = Al::Timer.new 1 / 60
event_queue = Al::EventQueue.new
event_queue.register timer.event_source
timer.start
until done
  ev = event_queue.wait_for_event
  count += 1
  Al.draw_text font18, color, width / 2, height / 2, "Frames: #{count}", :center
  Al::Display.flip
  Al.clear_to_color
end
