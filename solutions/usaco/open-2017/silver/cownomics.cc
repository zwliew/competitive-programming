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
#define FILE "cownomics"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> cows(2, vector<vector<int>>(n, vector<int>(m)));
  unordered_map<char, int> mp = {
      {'A', 0},
      {'C', 1},
      {'G', 2},
      {'T', 3},
  };
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    for (int j = 0; j < m; ++j) {
      cows[0][i][j] = mp[x[j]];
    }
  }
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    for (int j = 0; j < m; ++j) {
      cows[1][i][j] = mp[x[j]];
    }
  }

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        unordered_set<int> seen;
        for (int l = 0; l < n; ++l) {
          int cur = 16 * cows[0][l][i] + 4 * cows[0][l][j] + cows[0][l][k];
          seen.emplace(cur);
        }

        bool ok = true;
        for (int l = 0; l < n; ++l) {
          int cur = 16 * cows[1][l][i] + 4 * cows[1][l][j] + cows[1][l][k];
          if (seen.count(cur)) {
            ok = false;
            break;
          }
        }

        if (ok) {
          ++ans;
        }
      }
    }
  }

  cout << ans;
}
