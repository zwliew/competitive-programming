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
#define FILE "badmilk"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m, d, s;
  cin >> n >> m >> d >> s;
  vector<pair<int, int>> sick(s);
  vector<vector<pair<int, int>>> drunk(n + 1);
  for (int i = 0; i < d; ++i) {
    int p, cm, t;
    cin >> p >> cm >> t;
    drunk[p].emplace_back(t, cm);
  }
  for (int i = 1; i <= n; ++i) {
    sort(drunk[i].begin(), drunk[i].end());
  }
  for (int i = 0; i < s; ++i) {
    cin >> sick[i].first >> sick[i].second;
  }

  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    bool possible = true;
    for (int j = 0; j < s && possible; ++j) {
      possible = false;
      for (int k = 0;
           k < drunk[sick[j].first].size() &&
           drunk[sick[j].first][k].first < sick[j].second && !possible;
           ++k) {
        if (drunk[sick[j].first][k].second == i) {
          possible = true;
        }
      }
    }

    if (!possible) {
      continue;
    }

    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k < drunk[j].size(); ++k) {
        if (drunk[j][k].second == i) {
          ++cnt;
          break;
        }
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans;
}
