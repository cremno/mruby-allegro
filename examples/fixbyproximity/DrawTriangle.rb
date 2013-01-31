width = 640
height = 480
Al::Display.create width, height
Al.draw_triangle 10, 200, 100, 10, 190, 200, Al::Color.rgb(255, 0, 255), 5
Al.draw_filled_triangle 300, 400, 400, 200, 500, 400, Al::Color.rgb(0, 0, 255)
Al::Display.flip
Al.rest 4.0
