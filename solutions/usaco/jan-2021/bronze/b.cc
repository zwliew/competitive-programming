#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  array<int, 2> cnt = {0, 0};
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    ++cnt[x % 2];
  }

  int ans = min(cnt[0], cnt[1]);
  cnt[0] -= ans;
  cnt[1] -= ans;
  ans *= 2;

  if (cnt[0]) {
    ++ans;
  } else {
    ans += cnt[1] / 3 * 2;
    cnt[1] %= 3;
    if (cnt[1] == 2) {
      ++ans;
    } else if (cnt[1] == 1) {
      --ans;
    }
  }
  cout << ans;
}
