#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<char>> grid(N, vector<char>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
    }
  }

  auto for_each_row = [=](auto&& doThis) {
    for (int r = 0; r < N; ++r) {
      doThis(r);
    }
  };

  vector<bool> colored(K);
  int ans = 0;
  for (int c = 0; c < M; ++c) {
    bool done = false;
    for_each_row([&](int r) {
      if (colored[grid[r][c] - 'A']) {
        done = true;
      }
    });

    if (!done) {
      ++ans;
    }
    for_each_row([&](int r) { colored[grid[r][c] - 'A'] = true; });
  }

  cout << ans;
}
