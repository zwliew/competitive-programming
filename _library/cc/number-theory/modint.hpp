#ifndef MODINT_HPP
#define MODINT_HPP

#include <cassert>
#include <numeric>
#include <type_traits>

// [math]: modint
namespace math {
namespace internal {
template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  is_signed_int128<T>::value ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_signed<T>::value) ||
                                  is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
} // namespace internal

template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
struct static_modint : internal::static_modint_base {
  using mint = static_modint;

public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  static_modint() : _v(0) {}
  template <class T, internal::is_signed_int_t<T> * = nullptr>
  static_modint(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0)
      x += umod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T> * = nullptr>
  static_modint(T v) {
    _v = (unsigned int)(v % umod());
  }

  unsigned int val() const { return _v; }

  mint &operator++() {
    _v++;
    if (_v == umod())
      _v = 0;
    return *this;
  }
  mint &operator--() {
    if (_v == 0)
      _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }

  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod())
      _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v -= rhs._v;
    if (_v >= umod())
      _v += umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1)
        r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    if (prime) {
      assert(_v);
      return pow(umod() - 2);
    } else {
      auto eg = internal::inv_gcd(_v, m);
      assert(eg.first == 1);
      return eg.second;
    }
  }

  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }

private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
  static constexpr bool prime = internal::is_prime<m>;
};
} // namespace math

#endif MODINT_HPP
