#include <numeric>
#include <vector>

// Computes Euler's totient function for a specific N.
// Time complexity: O(sqrt(N)).
//
// Uses integer factorization.
template <typename T>
T phi(const T n) {
  T res = n;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      n /= 2;
    }
    res -= res / 2;
  }
  for (T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      res -= res / i;
    }
  }
  if (n > 1)
    res -= res / n;
  return res;
}

// Computes Euler's totient function for all integers from 1 to N.
// Time complexity: O(nlogn).
//
// Uses the divisor sum property:
// Sum of totient functions of all divisors of N = N.
template <typename T>
std::vector<T> phi1ToNDivisorSum(const T n) {
  std::vector<T> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  std::iota(phi.begin() + 2, phi.end(), 1);

  for (T i = 2; i * 2 <= n; ++i) {
    for (T j = 2 * i; j <= n; j += i) {
      phi[j] -= phi[i];
    }
  }

  return phi;
}

// Computes Euler's totient function for all integers from 1 to N.
// Time complexity: O(nloglogn).
//
// Uses an idea similar to the Sieve of Eratosthenes.
template <typename T>
std::vector<T> phi1ToNSieve(const T n) {
  std::vector<T> phi(n + 1);
  std::iota(phi.begin(), phi.end(), 0);

  for (T i = 2; i <= n; i += 2) {
    phi[i] -= phi[i] / 2;
  }
  for (T i = 3; i <= n; i += 2) {
    if (phi[i] == i) {
      for (T j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }

  return phi;
}
