#include <bits/stdc++.h>

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

  int N;
  cin >> N;
  // Runs in ~2200 ms. Use the __gnu_pbds hash map to run in ~400ms.
  unordered_map<int, int> cnt;
  int64_t ans = 0;
  while (N--) {
    int x;
    cin >> x;
    for (int i = 0; i < 32; ++i) {
      ans += cnt[(1 << i) - x];
    }
    ++cnt[x];
  }
  cout << ans;
}
