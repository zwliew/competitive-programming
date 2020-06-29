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

  const int64_t m = 1000000007;
  const int MAXN = 2000000;
  vector<int64_t> mem(MAXN + 1);
  for (int n = 3; n <= MAXN; ++n) {
    mem[n] = mem[n - 2] * 2 + mem[n - 1] + (n % 3);
    mem[n] %= m;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << mem[n] * 4 % m << '\n';
  }
}
