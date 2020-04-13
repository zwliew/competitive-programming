#include <bitset>

// Size is usually maximally 1e8 (maybe 1e9 depending on time limit?)
// https://codeforces.com/blog/entry/75852
template <std::size_t N>
void sieveOfEratosthenes(std::bitset<N + 1> bs) {
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i = 4; i <= N; i += 2) {
    bs[i] = 0;
  }
  for (int i = 3; i * i <= N; i += 2) {
    if (bs[i]) {
      for (int j = i * i; j <= N; j += i) {
        bs[j] = 0;
      }
    }
  }

  std::vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (bs[i]) {
      primes.push_back(i);
    }
  }

  // Faster alternative if using G++
  // Uses bitset._Find_first() and bitset._Find_next(idx)
  // for (int i = bs._Find_first(); i <= N; i = bs._Find_next(i)) {
  //   primes.push_back(i);
  // }
}
