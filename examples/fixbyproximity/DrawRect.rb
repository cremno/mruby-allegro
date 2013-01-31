width, height = 640, 480
Al::Display.create width, height
Al.draw_rectangle 10, 10, 250, 250, Al::Color.rgb(255, 0, 255), 5
Al.draw_rounded_rectangle width - 200, 10, width - 10, 50, 5, 5, Al::Color.rgb(0, 0, 255), 15
Al.draw_filled_rectangle 10, 280, 250, height - 10, Al::Color.rgb(255, 255, 255)
Al.draw_filled_rounded_rectangle width - 200, 180, width - 10, height - 10, 10, 10, Al::Color.rgb(0, 255, 0)
Al::Display.flip
Al.rest 4.0
