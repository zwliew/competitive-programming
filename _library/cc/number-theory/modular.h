#include <vector>

// Computes the modular inverse of an integer a given its phi.
// Uses binary exponentiation.
// Time complexity: O(log(phi))
template <typename T>
T modinv(T a, T phi, const T m) {
  T res = 1;
  --phi;
  while (phi) {
    if (phi & 1) {
      res *= a;
      res %= m;
    }
    a *= a;
    a %= m;
    phi >>= 1;
  }
  return res;
}

// Computes the modular inverse of every integer from 1 to M.
// Time complexity: O(M)
template <typename T>
std::vector<T> modinv1ToM(const T m) {
  std::vector<T> inv(m);
  inv[1] = 1;
  for (T i = 2; i < m; ++i) {
    inv[i] = m - m / i * inv[m % i] % m;
  }
  return inv;
}
