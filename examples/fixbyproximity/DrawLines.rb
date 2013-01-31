width = 640
height = 480
Al::Display.create width, height
Al.draw_line 100, 100, width - 100, 100, Al::Color.rgb(255, 0, 0), 1
Al.draw_line 50, 200, width - 50, 200, Al::Color.rgb(0, 0, 255), 5
Al.draw_line 0, 300, width, 300, Al::Color.rgb(255, 0, 255), 10
Al.draw_line 50, 50, 50, 400, Al::Color.rgb(0, 255, 0), 3
Al.draw_line 50, 200, width - 50, 400, Al::Color.rgb(0, 0, 255), 5
Al::Display.flip
Al.rest 4.0
