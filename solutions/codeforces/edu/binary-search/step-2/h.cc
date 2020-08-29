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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s;
  cin >> s;
  array<int, 3> needed{};
  for (char c : s) {
    if (c == 'B') {
      needed[0]++;
    } else if (c == 'S') {
      needed[1]++;
    } else {
      needed[2]++;
    }
  }

  array<int, 3> has, prices;
  cin >> has[0] >> has[1] >> has[2] >> prices[0] >> prices[1] >> prices[2];

  int64_t rubles;
  cin >> rubles;

  int64_t l = 0, r = 1e15;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    int64_t total = 0;
    for (int i = 0; i < 3; ++i) {
      total += max((int64_t)0, (int64_t)needed[i] * m - has[i]) * prices[i];
    }
    if (total <= rubles) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
}
