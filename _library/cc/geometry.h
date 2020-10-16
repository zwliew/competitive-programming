bool rectCircleIntersect(long double rad,
                         long double cx,
                         long double cy,
                         long double x1,
                         long double y1,
                         long double x2,
                         long double y2) {
  long double x, y;
  if (cx < x1)
    x = x1;
  else if (cx > x2)
    x = x2;
  else
    x = cx;

  if (cy < y1)
    y = y1;
  else if (cy > y2)
    y = y2;
  else
    y = cy;

  return ((cy - y) * (cy - y)) + ((cx - x) * (cx - x)) <= rad * rad;
}
