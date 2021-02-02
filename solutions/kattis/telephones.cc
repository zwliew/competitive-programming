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

  int N, M;
  while (cin >> N >> M && N) {
    vector<array<int, 2>> calls(N);
    for (int i = 0; i < N; ++i) {
      int start, dur;
      cin >> start >> start >> start >> dur;
      calls[i] = {start, start + dur};
    }
    for (int i = 0; i < M; ++i) {
      int start, dur;
      cin >> start >> dur;
      int ans = 0;
      for (auto& [s, e] : calls) {
        if (start < e && start + dur > s) {
          ++ans;
        }
      }
      cout << ans << "\n";
    }
  }
}
