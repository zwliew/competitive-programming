#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const int MXN = 1e6;
  vector<bool> prime(MXN + 1, true);
  prime[0] = prime[1] = false;
  for (int d = 2; d * d <= MXN; ++d) {
    if (prime[d]) {
      for (int j = d * d; j <= MXN; j += d) {
        prime[j] = false;
      }
    }
  }
  vector<int> primes = {2};
  for (int d = 3; d <= MXN; d += 2) {
    if (prime[d]) {
      primes.push_back(d);
    }
  }

  // x = a * b
  // factors: 1, a, b, a * b
  // b - a >= d
  // a - 1 >= d
  // b * (a - 1) >= d
  int T;
  cin >> T;
  while (T--) {
    int D;
    cin >> D;
    int a = *lower_bound(primes.begin(), primes.end(), D + 1);
    int b = *lower_bound(primes.begin(), primes.end(), max(D + a, (D + a - 2) / (a - 1)));
    cout << a * b << "\n";
  }
}
