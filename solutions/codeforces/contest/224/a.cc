/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<int> x(3);
  cin >> x[0] >> x[1] >> x[2];
  sort(x.begin(), x.end());
  for (int i = 1; i * i <= x[0]; ++i) {
    if (x[0] % i) continue;
    int j = x[0] / i;
    if (j < i || x[2] % j) continue;
    int k = x[2] / j;
    if (k >= i && k >= j && i * k == x[1]) {
      cout << 4 * (i + j + k);
      return 0;
    }
  }
}
