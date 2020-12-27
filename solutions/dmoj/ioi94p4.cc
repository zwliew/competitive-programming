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

  array<int, 9> state;
  for (int i = 0; i < 9; ++i) {
    cin >> state[i];
    state[i] /= 3;
    state[i] %= 4;
  }

  vector<vector<int>> moves = {
      {0, 1, 3, 4}, {0, 1, 2},    {1, 2, 4, 5}, {0, 3, 6},    {1, 3, 4, 5, 7},
      {2, 5, 8},    {3, 4, 6, 7}, {6, 7, 8},    {4, 5, 7, 8},
  };

  vector<int> best;
  vector<int> cur;
  auto recurse = [&](auto& self, int d) {
    if (d == 9) {
      if (any_of(state.begin(), state.end(), [](int x) { return x; }))
        return;
      if (best.empty() || cur.size() < best.size() ||
          (cur.size() == best.size() && best < cur)) {
        best = cur;
      }
      return;
    }

    for (int i = 0; i < 4; ++i) {
      for (int x : moves[d]) {
        state[x] = (state[x] + i) % 4;
      }
      for (int j = 0; j < i; ++j) {
        cur.push_back(d + 1);
      }
      self(self, d + 1);
      for (int j = 0; j < i; ++j) {
        cur.pop_back();
      }
      for (int x : moves[d]) {
        state[x] = (state[x] - i + 4) % 4;
      }
    }
  };

  recurse(recurse, 0);
  for (int x : best) {
    cout << x << " ";
  }
}
