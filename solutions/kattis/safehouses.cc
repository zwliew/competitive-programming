#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  vector<array<int, 2>> houses, spies;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c == 'S') {
        spies.push_back({i, j});
      } else if (c == 'H') {
        houses.push_back({i, j});
      }
    }
  }

  int mx = 0;
  for (auto& [si, sj] : spies) {
    int cur = INT_MAX;
    for (auto& [hi, hj] : houses) {
      cur = min(cur, abs(hi - si) + abs(hj - sj));
    }
    mx = max(mx, cur);
  }
  cout << mx;
}
