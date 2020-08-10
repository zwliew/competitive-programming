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
#define FILE "mowing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  map<pair<int, int>, int> prev;

  int row = 1000, col = 1000;
  int time = 0;
  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    char c;
    int d;
    cin >> c >> d;
    for (int j = 0; j < d; ++j) {
      ++time;
      if (c == 'N') {
        --row;
      } else if (c == 'S') {
        ++row;
      } else if (c == 'W') {
        --col;
      } else {
        ++col;
      }

      if (prev.find({row, col}) != prev.end()) {
        ans = min(ans, time - prev[{row, col}]);
      }
      prev[{row, col}] = time;
    }
  }
  cout << (ans == INT_MAX ? -1 : ans);
}
