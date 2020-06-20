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

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i - 1] = {x, i};
  }
  sort(a.begin(), a.end());

  vector<int> ans;
  for (int i = 0; i < n && k >= a[i].first; ++i) {
    k -= a[i].first;
    ans.emplace_back(a[i].second);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
}
