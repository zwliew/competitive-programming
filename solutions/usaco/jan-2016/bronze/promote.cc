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
#define FILE "promote"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<pair<int, int>> v(4);
  for (int i = 0; i < 4; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  vector<int> ans;
  int promoted = v[3].second - v[3].first;
  ans.emplace_back(promoted);

  v[2].second += promoted;
  promoted = v[2].second - v[2].first;
  ans.emplace_back(promoted);

  v[1].second += promoted;
  promoted = v[1].second - v[1].first;
  ans.emplace_back(promoted);

  for (int i = 2; i >= 0; --i) {
    cout << ans[i] << '\n';
  }
}
