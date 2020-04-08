#include <utility>

long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long mexp(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

long long modinv(long long x, long long m) { return mexp(x, m - 2, m); }