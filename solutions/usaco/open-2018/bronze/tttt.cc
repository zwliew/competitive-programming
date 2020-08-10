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
#define FILE "tttt"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<char, 9> grid;
  for (int i = 0; i < 9; ++i) {
    cin >> grid[i];
  }

  vector<array<int, 3>> conditions = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
      {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6},
  };

  unordered_set<char> indiv;
  set<vector<char>> paired;
  for (int i = 0; i < conditions.size(); ++i) {
    set<char> needed;
    for (int j = 0; j < 3; ++j) {
      needed.emplace(grid[conditions[i][j]]);
    }
    if (needed.size() == 1) {
      indiv.emplace(*needed.begin());
    } else if (needed.size() == 2) {
      vector<char> conv(needed.begin(), needed.end());
      paired.emplace(conv);
    }
  }
  cout << indiv.size() << '\n' << paired.size();
}
