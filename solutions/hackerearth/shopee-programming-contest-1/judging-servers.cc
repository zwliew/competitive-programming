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

int64_t dp(vector<vector<int64_t>> &mem, vector<int64_t> &p, int n, int idx) {
  if (n <= 0) {
    return 0;
  }
  if (idx >= (int)p.size()) {
    return 1e17;
  }

  if (mem[n][idx] != -1) {
    return mem[n][idx];
  }

  int64_t ans = dp(mem, p, n, idx + 1);
  ans = min(ans, dp(mem, p, n - 1, idx + 1) + p[idx]);
  if (idx < (int)p.size() - 1) {
    ans = min(ans, dp(mem, p, n - 2, idx + 2) + min(p[idx], p[idx + 1]));
  }
  return mem[n][idx] = ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int s, n;
    cin >> s >> n;
    vector<int64_t> p(s);
    for (auto &x : p)
      cin >> x;

    vector<vector<int64_t>> mem(n + 1, vector<int64_t>(s + 1, -1));
    cout << "Case " << tt << ": " << dp(mem, p, n, 0) << '\n';
  }
}
