#include <utility>

template <typename T>
T gcd(T a, T &b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

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

template <typename T>
T modinv(T x, T m) {
  return mexp(x, m - 2, m);
}