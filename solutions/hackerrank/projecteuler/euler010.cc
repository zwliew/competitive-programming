#include <bits/stdc++.h>
using namespace std;


int main() {
  const int MAX = 1000000;
  bitset<MAX + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 4; i <= MAX; i += 2) {
    isPrime[i] = 0;
  }
  for (int64_t i = 3; i * i <= MAX; i += 2) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= MAX; j += i) {
      isPrime[j] = 0;
    }
  }

  vector<int> primes = {2};
  vector<int64_t> prefixSums = {0, 2};
  for (int i = 3; i <= MAX; i += 2) {
    if (isPrime[i]) {
      primes.emplace_back(i);
      prefixSums.emplace_back(prefixSums.back() + i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto it = --upper_bound(primes.begin(), primes.end(), n);
    cout << prefixSums[it - primes.begin() + 1] << '\n';
  }
}

