def al_draw_line(x1, y1, x2, y2, color, thickness)
  Al.draw_line(x1, y1, x2, y2, color, thickness)
end

def al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness)
  Al.draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness)
end

def al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color)
  Al.draw_filled_triangle(x1, y1, x2, y2, x3, y3, color)
end

def al_draw_rectangle(x1, y1, x2, y2, color, thickness)
  Al.draw_rectangle(x1, y1, x2, y2, color, thickness)
end

def al_draw_filled_rectangle(x1, y1, x2, y2, color)
  Al.draw_filled_rectangle(x1, y1, x2, y2, color)
end

def al_draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, color, thickness)
  Al.draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, color, thickness)
end

def al_draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, color)
  Al.draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, color)
end

def al_draw_ellipse(cx, cy, rx, ry, color, thickness)
  Al.draw_ellipse(cx, cy, rx, ry, color, thickness)
end

def al_draw_filled_ellipse(cx, cy, rx, ry, color)
  Al.draw_filled_ellipse(cx, cy, rx, ry, color)
end

def al_draw_circle(cx, cy, r, color, thickness)
  Al.draw_circle(cx, cy, r, color, thickness)
end

def al_draw_filled_circle(cx, cy, r, color)
  Al.draw_filled_circle(cx, cy, r, color)
end

def al_draw_spline(points, color, thickness)
  Al.draw_spline(*points, color, thickness)
end
