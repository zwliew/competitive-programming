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
#define FILE "hps"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  unordered_map<char, int> ctoi = {
      {'H', 0},
      {'P', 1},
      {'S', 2},
  };

  int n;
  cin >> n;
  array<vector<int>, 3> wins;
  for (int i = 0; i < 3; ++i) {
    wins[i].assign(n + 1, 0);
  }
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    int idx = (ctoi[c] + 1) % 3;
    wins[idx][i]++;
  }
  for (int i = 0; i < 3; ++i) {
    partial_sum(wins[i].begin(), wins[i].end(), wins[i].begin());
  }

  int best = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        best = max(best, wins[j][i] + wins[k][n] - wins[k][i]);
      }
    }
  }
  cout << best;
}
