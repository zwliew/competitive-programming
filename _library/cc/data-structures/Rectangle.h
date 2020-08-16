template <typename T>
struct Rectangle {
  T x1;
  T x2;
  T y1;
  T y2;

  T area() { return max(0, x2 - x1) * max(0, y2 - y1); }

  Rectangle intersection(Rectangle& other) {
    Rectangle rect;
    rect.x1 = max(x1, other.x1);
    rect.x2 = min(x2, other.x2);
    rect.y1 = max(y1, other.y1);
    rect.y2 = min(y2, other.y2);
    return rect;
  }
};