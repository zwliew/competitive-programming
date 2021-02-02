#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  vector<vector<int>> states(8);
  auto generateStates = [&](auto&& self, int target, int cur, int i) {
    if (i == 3) {
      states[target].push_back(cur);
      return;
    }

    if (target & (1 << i)) {
      self(self, target, cur & ~(1 << i), i + 1);
    } else {
      self(self, target, cur, i + 1);
    }

    if (i < 2 && (target & (1 << i)) && (target & (1 << (i + 1)))) {
      self(self, target, cur, i + 2);
    }
  };
  for (int i = 0; i < 8; ++i) {
    generateStates(generateStates, i, 7, 0);
  }

  int N;
  while (cin >> N && N != -1) {
    vector<vector<int>> dp(2, vector<int>(8));
    dp[0][7] = 1;
    int cur = 0;
    for (int i = 0; i < N; ++i) {
      int nxt = cur ^ 1;
      fill(dp[nxt].begin(), dp[nxt].end(), 0);
      for (int j = 0; j < 8; ++j) {
        for (int state : states[j]) {
          dp[nxt][j] += dp[cur][state];
        }
      }
      cur = nxt;
    }
    cout << dp[cur][7] << "\n";
  }
}
