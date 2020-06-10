#include <numeric>
#include <vector>

template <typename T>
std::vector<T> phiFrom1ToN(T n) {
  std::vector<T> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  std::iota(phi.begin() + 2, phi.end(), 1);

  for (T i = 2; i <= n; ++i) {
    for (T j = 2 * i; j <= n; j += i) {
      phi[j] -= phi[i];
    }
  }

  return phi;
}