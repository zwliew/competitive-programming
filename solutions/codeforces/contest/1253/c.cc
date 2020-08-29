/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "balancing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.begin(), a.end());

  vector<int64_t> modSum(m);
  int64_t cost = 0;
  for (int i = 0; i < n; ++i) {
    cost += a[i] + modSum[i % m];
    modSum[i % m] += a[i];
    cout << cost << ' ';
  }
}
