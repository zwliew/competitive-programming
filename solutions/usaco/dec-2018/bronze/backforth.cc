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
#define FILE "backforth"
#endif

void backtrack(bitset<2001>& pos,
               array<array<int, 101>, 2>& b,
               int amt,
               int rem) {
  if (!rem) {
    pos[amt] = true;
    return;
  }

  for (int i = 1; i <= 100; ++i) {
    if (b[rem % 2][i]) {
      --b[rem % 2][i];
      ++b[1 - (rem % 2)][i];
      backtrack(pos, b, amt + (rem % 2 ? -i : i), rem - 1);
      ++b[rem % 2][i];
      --b[1 - (rem % 2)][i];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<array<int, 101>, 2> b = {0};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 10; ++j) {
      int x;
      cin >> x;
      ++b[i][x];
    }
  }

  bitset<2001> pos;
  backtrack(pos, b, 1000, 4);

  cout << pos.count();
}
