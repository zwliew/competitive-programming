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
#define FILE "div7"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  array<int, 7> rem;
  rem[0] = 0;
  for (int i = 1; i < 7; ++i) {
    rem[i] = -1;
  }

  int cur = 0;
  int best = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    cur += x;
    cur %= 7;
    if (rem[cur] != -1) {
      best = max(best, i - rem[cur]);
    } else {
      rem[cur] = i;
    }
  }
  cout << best;
}
