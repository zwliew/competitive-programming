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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int d, sumTime;
  cin >> d >> sumTime;
  vector<pair<int, int>> v(d);
  vector<int> ans;
  for (auto& [mn, mx] : v) {
    cin >> mn >> mx;
    sumTime -= mn;
    ans.emplace_back(mn);
  }

  if (sumTime < 0) {
    cout << "NO";
    return 0;
  }

  for (int i = 0; i < d && sumTime; ++i) {
    int diff = min(v[i].second - v[i].first, sumTime);
    ans[i] += diff;
    sumTime -= diff;
  }

  if (sumTime) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  for (auto x : ans) {
    cout << x << ' ';
  }
}
