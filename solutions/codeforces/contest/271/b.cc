/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  const int MAX_PRIMES = 200000;
  bitset<MAX_PRIMES + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 4; i <= MAX_PRIMES; i += 2) {
    isPrime[i] = 0;
  }
  for (long long i = 3; i * i <= MAX_PRIMES; i += 2) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= MAX_PRIMES; j += i) {
      isPrime[j] = 0;
    }
  }
  vector<int> primes = {2};
  for (int i = 3; i <= MAX_PRIMES; i += 2) {
    if (isPrime[i]) primes.emplace_back(i);
  }

  int n, m;
  cin >> n >> m;

  int best = INT_MAX;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      auto it = lower_bound(primes.begin(), primes.end(), x);
      grid[i][j] = *it - x;
      sum += grid[i][j];
    }
    best = min(best, sum);
  }

  for (int j = 0; j < m; ++j) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += grid[i][j];
    }
    best = min(sum, best);
  }

  cout << best;
}
