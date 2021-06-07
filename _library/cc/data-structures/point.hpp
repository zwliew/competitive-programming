#include <tuple>

template <typename T> class point {
public:
  T x, y;
  point() : x(0), y(0) {}
  point(T _x, T _y) : x(_x), y(_y) {}
  bool operator<(const point<T> &p) const {
    return std::tie(x, y) < std::tie(p.x, p.y);
  }
};
