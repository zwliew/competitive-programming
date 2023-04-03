#ifndef MATH_HPP
#define MATH_HPP

#include <cassert>
#include <cstdint>
#include <utility>

// [math]: internal
namespace math {
namespace internal {
constexpr std::int64_t safe_mod(std::int64_t x, std::int64_t m) {
  assert(1 <= m);
  x %= m;
  if (x < 0)
    x += m;
  return x;
}

constexpr std::int64_t pow_mod_constexpr(std::int64_t x, std::int64_t n,
                                         int m) {
  if (m == 1)
    return 0;
  unsigned int _m = (unsigned int)(m);
  std::uint64_t r = 1;
  std::uint64_t y = safe_mod(x, m);
  while (n) {
    if (n & 1)
      r = (r * y) % _m;
    y = (y * y) % _m;
    n >>= 1;
  }
  return r;
}

constexpr bool is_prime_constexpr(int n) {
  if (n <= 1)
    return false;
  if (n == 2 || n == 7 || n == 61)
    return true;
  if (n % 2 == 0)
    return false;
  std::int64_t d = n - 1;
  while (d % 2 == 0)
    d /= 2;
  constexpr std::int64_t bases[3] = {2, 7, 61};
  for (std::int64_t a : bases) {
    std::int64_t t = d;
    std::int64_t y = pow_mod_constexpr(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<std::int64_t, std::int64_t> inv_gcd(std::int64_t a,
                                                        std::int64_t b) {
  a = safe_mod(a, b);
  if (a == 0)
    return {b, 0};
  std::int64_t s = b, t = a;
  std::int64_t m0 = 0, m1 = 1;
  while (t) {
    std::int64_t u = s / t;
    s -= t * u;
    m0 -= m1 * u;
    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0)
    m0 += b / s;
  return {s, m0};
}
} // namespace internal
} // namespace math

// [math]: number theory
namespace math {
// Returns x^n (mod m)
std::int64_t pow_mod(std::int64_t x, std::int64_t n, int m) {
  assert(0 <= n && 1 <= m);
  if (m == 1)
    return 0;
  unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
  while (n) {
    if (n & 1)
      r = (std::int64_t(r) * y) % m;
    y = (std::int64_t(y) * y) % m;
    n >>= 1;
  }
  return r;
}

// Returns y s.t. 0 <= y < m and xy = 1 (mod m)
std::int64_t inv_mod(std::int64_t x, std::int64_t m) {
  assert(1 <= m);
  auto z = internal::inv_gcd(x, m);
  assert(z.first == 1);
  return z.second;
}
} // namespace math
#endif
