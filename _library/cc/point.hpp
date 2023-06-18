#ifndef POINT_HPP
#define POINT_HPP

#include <complex>
#include <iostream>
#include <tuple>

namespace geom {
template <typename T> struct point {
public:
  T x, y;
  point() : x(0), y(0) {}
  point(T x_, T y_) : x(x_), y(y_) {}
  template <typename U> explicit point(const point<U> &p) : x(p.x), y(p.y) {}
  point(const std::pair<T, T> &p) : x(p.first), y(p.second) {}
  point(const std::complex<T> &p) : x(real(p)), y(imag(p)) {}
  explicit operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }
  explicit operator std::complex<T>() const { return std::complex<T>(x, y); }

  friend std::ostream &operator<<(std::ostream &o, const point &p) {
    return o << '(' << p.x << ',' << p.y << ')';
  }
  friend std::istream &operator>>(std::istream &i, point &p) {
    return i >> p.x >> p.y;
  }
  friend bool operator==(const point &a, const point &b) {
    return a.x == b.x && a.y == b.y;
  }
  friend bool operator!=(const point &a, const point &b) { return !(a == b); }

  point operator+() const { return point(+x, +y); }
  point operator-() const { return point(-x, -y); }

  point &operator+=(const point &p) {
    x += p.x, y += p.y;
    return *this;
  }
  point &operator-=(const point &p) {
    x -= p.x, y -= p.y;
    return *this;
  }
  point &operator*=(const T &t) {
    x *= t, y *= t;
    return *this;
  }
  point &operator/=(const T &t) {
    x /= t, y /= t;
    return *this;
  }

  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator*(const point &a, const T &t) {
    return point(a.x * t, a.y * t);
  }
  friend point operator*(const T &t, const point &a) {
    return point(t * a.x, t * a.y);
  }
  friend point operator/(const point &a, const T &t) {
    return point(a.x / t, a.y / t);
  }

  T dist2() const { return x * x + y * y; }
  auto dist() const { return std::sqrt(dist2()); }
  point unit() const { return *this / this->dist(); }
  auto angle() const { return std::atan2(y, x); }

  T int_norm() const { return __gcd(x, y); }
  point int_unit() const {
    if (!x && !y)
      return *this;
    return *this / this->int_norm();
  }

  // Convenient free-functions, mostly for generic interop
  friend auto norm(const point &a) { return a.dist2(); }
  friend auto abs(const point &a) { return a.dist(); }
  friend auto unit(const point &a) { return a.unit(); }
  friend auto arg(const point &a) { return a.angle(); }
  friend auto int_norm(const point &a) { return a.int_norm(); }
  friend auto int_unit(const point &a) { return a.int_unit(); }

  point perp_cw() const { return point(y, -x); }
  point perp_ccw() const { return point(-y, x); }

  friend T dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }
  friend T cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend T cross3(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
  }

  // Complex numbers and rotation
  friend point conj(const point &a) { return point(a.x, -a.y); }

  // Returns conj(a) * b
  friend point dot_cross(const point &a, const point &b) {
    return point(dot(a, b), cross(a, b));
  }
  friend point cmul(const point &a, const point &b) {
    return dot_cross(conj(a), b);
  }
  friend point cdiv(const point &a, const point &b) {
    return dot_cross(b, a) / b.norm();
  }

  // Must be a unit vector; otherwise multiplies the result by abs(u)
  point rotate(const point &u) const { return dot_cross(conj(u), *this); }
  point unrotate(const point &u) const { return dot_cross(u, *this); }

  friend bool lex_less(const point &a, const point &b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
  }

  friend bool same_dir(const point &a, const point &b) {
    return cross(a, b) == 0 && dot(a, b) > 0;
  }

  // check if 180 <= s..t < 360
  friend bool is_reflex(const point &a, const point &b) {
    auto c = cross(a, b);
    return c ? (c < 0) : (dot(a, b) < 0);
  }

  // operator < (s,t) for angles in [base,base+2pi)
  friend bool angle_less(const point &base, const point &s, const point &t) {
    int r = is_reflex(base, s) - is_reflex(base, t);
    return r ? (r < 0) : (0 < cross(s, t));
  }

  friend auto angle_cmp(const point &base) {
    return [base](const point &s, const point &t) {
      return angle_less(base, s, t);
    };
  }
  friend auto angle_cmp_center(const point &center, const point &dir) {
    return [center, dir](const point &s, const point &t) -> bool {
      return angle_less(dir, s - center, t - center);
    };
  }

  // is p in [s,t] taken ccw? 1/0/-1 for in/border/out
  friend int angle_between(const point &s, const point &t, const point &p) {
    if (same_dir(p, s) || same_dir(p, t))
      return 0;
    return angle_less(s, p, t) ? 1 : -1;
  }
};

template <typename T> struct point3d {
  using P = point3d;

  T x, y, z;
  point3d() : x(0), y(0), z(0) {}
  point3d(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}

  template <typename U>
  explicit point3d(const point3d<U> &p) : x(T(p.x)), y(T(p.y)), z(T(p.z)) {}

  friend std::istream &operator>>(std::istream &i, P &p) {
    return i >> p.x >> p.y >> p.z;
  }
  friend std::ostream &operator<<(std::ostream &o, const P &p) {
    return o << "(" << p.x << "," << p.y << "," << p.z << ")";
  }

  friend bool operator==(const P &a, const P &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
  }
  friend bool operator!=(const P &a, const P &b) {
    return a.x != b.x || a.y != b.y || a.z != b.z;
  }

  P &operator+=(const P &o) {
    x += o.x, y += o.y, z += o.z;
    return *this;
  }
  P &operator-=(const P &o) {
    x -= o.x, y -= o.y, z -= o.z;
    return *this;
  }
  friend P operator+(const P &a, const P &b) { return P(a) += b; }
  friend P operator-(const P &a, const P &b) { return P(a) -= b; }

  P &operator*=(const T &t) {
    x *= t, y *= t, z *= t;
    return *this;
  }
  P &operator/=(const T &t) {
    x /= t, y /= t, z /= t;
    return *this;
  }
  friend P operator*(const P &p, const T &t) { return P(p) *= t; }
  friend P operator*(const T &t, const P &p) { return P(p) *= t; }
  friend P operator/(const P &a, const T &t) { return P(a) /= t; }

  friend P operator+(const P &a) { return P(+a.x, +a.y, +a.z); }
  friend P operator-(const P &a) { return P(-a.x, -a.y, -a.z); }

  friend T dot(const P &a, const P &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }
  friend T norm(const P &a) { return dot(a, a); }
  friend P cross(const P &a, const P &b) {
    return P(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
             a.x * b.y - a.y * b.x);
  }

  friend T int_norm(const P &p) {
    return gcd(gcd(abs(p.x), abs(p.y)), abs(p.z));
  }
  friend P int_unit(const P &p) {
    T g = int_norm(p);
    return g ? p / g : p;
  }

  friend T abs(const P &a) { return sqrt(std::max(T(0), norm(a))); }
  friend P unit(const P &a) { return a / abs(a); }

  friend T vol(const P &a, const P &b, const P &c, const P &d) {
    return dot(cross(b - a, c - a), d - a);
  }

  friend bool lexLess(const P &a, const P &b) {
    return tie(a.x, a.y, a.z) < tie(b.x, b.y, b.z);
  }

  friend bool parallelSame(const P &a, const P &b) {
    assert(a != P());
    assert(b != P());
    return lexLess(a, P()) == lexLess(b, P());
  }
};

template <class T>
std::vector<point<T>> convex_hull(std::vector<point<T>> pts) {
  if (sz(pts) <= 1)
    return pts;
  sort(all(pts));
  std::vector<point<T>> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (auto p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
        t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

} // namespace geom
#endif // POINT_HPP
