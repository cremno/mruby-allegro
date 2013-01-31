width, height = 640, 480
Al::Display.create width, height
Al.draw_ellipse 150, 100, 100, 50, Al::Color.rgb(127, 3, 34), 7
Al.draw_filled_ellipse 400, 250, 100, 200, Al::Color.rgb(0, 255, 255)
Al::Display.flip
Al.rest 4.0
