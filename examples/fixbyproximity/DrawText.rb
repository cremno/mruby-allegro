display = Al::Display.create 640, 480
font24 = Al::Font.load 'arial.ttf', 24
font36 = Al::Font.load 'arial.ttf', 36
font18 = Al::Font.load 'arial.ttf', 18
Al.clear_to_color
Al.draw_text font24, Al::Color.rgb(255, 0, 255), 50, 50, 'Hello World, this is 24 point'
Al.draw_text font36, Al::Color.rgb(255, 127, 127), 640 / 2, 480 / 2, 'This is Centered and 36 point', :center
Al.draw_text font18, Al::Color.rgb(15, 240, 18), 620, 350, 'This is right aligned and 18 point', :right
screen_w, screen_h = display.width, display.height
Al.draw_text font18, Al::Color.rgb(255, 255, 255), screen_w / 2, 400, "TEXT with variable output (textf): Screen width and height = #{screen_w} / #{screen_h}", :center
Al::Display.flip
Al.rest 5.0
