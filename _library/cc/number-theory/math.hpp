#include <utility>

// Note: use C++17 gcd() or GNU __gcd() instead.
template <typename T>
T gcd(T a, T& b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

template <typename T>
std::tuple<T, int, int> egcd(T a, T b) {
  int x = 1, y = 0, x1 = 0, y1 = 0;
  T a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    std::tie(x, x1) = {x1, x - q * x1};
    std::tie(y, y1) = {y1, y - q * y1};
    std::tie(a, b) = {b, a % b};
  }
  return {a1, x, y};
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

// Note: use GNU __gnu_cxx::power() instead if there is no need for modular
// arithmetic.
template <typename T>
T mexp(T a, T b, T m) {
  T res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

// Only works if m is prime since phi(m) = m - 1 for all prime m.
template <typename T>
T modinv(T x, T m) {
  return mexp(x, m - 2, m);
}
