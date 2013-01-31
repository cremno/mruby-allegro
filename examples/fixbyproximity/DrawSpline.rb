width, height = 640, 480
Al::Display.create width, height
Al.draw_spline 0, 0, 400, 100, 50, 200, width, height, Al::Color.rgb(255, 0, 255), 0
Al.draw_spline 0, height, 200, 100, 400, 200, width, height, Al::Color.rgb(0, 0, 255), 3
Al::Display.flip
Al.rest 4.0
