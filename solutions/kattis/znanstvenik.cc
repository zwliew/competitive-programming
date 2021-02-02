#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int H, W;
  cin >> H >> W;
  vector<string> cols(W, string(H, '0'));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> cols[j][i];
    }
  }
  for (auto& x : cols) {
    reverse(x.begin(), x.end());
  }
  sort(cols.begin(), cols.end());

  int ans = 0;
  for (int i = 0; i < W - 1; ++i) {
    for (int j = 0; j < H; ++j) {
      if (cols[i][j] != cols[i + 1][j]) {
        ans = max(ans, j);
        break;
      }
    }
  }
  cout << H - ans - 1;
}
