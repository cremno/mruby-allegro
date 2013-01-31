width, height = 640, 480
Al::Display.create width, height
Al.draw_circle 100, 100, 50, Al::Color.rgb(255, 255, 0), 7
Al.draw_filled_circle 400, 400, 70, Al::Color.rgb(255, 255, 255)
Al::Display.flip
Al.rest 4.0
