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

  int y, k, n;
  cin >> y >> k >> n;
  int rem = (k - y % k) % k;
  int x = (n - y) / k * k + rem;
  while (x > n - y) {
    x -= k;
  }

  vector<int> ans;
  while (x >= 1) {
    ans.emplace_back(x);
    x -= k;
  }

  if (ans.empty()) {
    cout << -1;
    return 0;
  }

  reverse(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << ' ';
  }
}
