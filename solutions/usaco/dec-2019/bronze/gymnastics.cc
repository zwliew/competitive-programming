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
#define FILE "gymnastics"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int k, n;
  cin >> k >> n;
  vector<vector<int>> order(k, vector<int>(n));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      --x;
      order[i][x] = j;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int fcnt = 0, scnt = 0;
      for (int l = 0; l < k; ++l) {
        if (order[l][i] > order[l][j]) {
          ++fcnt;
        } else if (order[l][j] > order[l][i]) {
          ++scnt;
        }
      }

      if (!fcnt || !scnt) {
        ++cnt;
      }
    }
  }

  cout << cnt;
}
