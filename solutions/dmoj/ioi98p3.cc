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

  int N, C;
  cin >> N >> C;
  vector<int> state(N, -1);
  for (int i = 0; i < 2; ++i) {
    int x;
    cin >> x;
    while (x != -1) {
      state[x - 1] = !i;
      cin >> x;
    }
  }

  unordered_set<string> found;
  for (int i = 0; i < 16; ++i) {
    int odd = __builtin_popcount(i);
    if (odd > C || (C - odd) % 2)
      continue;

    vector<bool> cur(N, true);
    bool ok = true;
    for (int j = 0; j < N && ok; ++j) {
      if (i & 1) {
        cur[j] = !cur[j];
      }
      if ((i & 2) && j % 2 == 0) {
        cur[j] = !cur[j];
      }
      if ((i & 4) && j % 2) {
        cur[j] = !cur[j];
      }
      if ((i & 8) && j % 3 == 0) {
        cur[j] = !cur[j];
      }

      if (state[j] != -1 && state[j] != cur[j]) {
        ok = false;
      }
    }

    if (ok) {
      string ans;
      for (int x : cur) {
        ans += to_string(x);
      }
      found.insert(ans);
    }
  }

  if (found.empty()) {
    cout << "IMPOSSIBLE";
  } else {
    for (auto& s : found) {
      cout << s << "\n";
    }
  }
}
