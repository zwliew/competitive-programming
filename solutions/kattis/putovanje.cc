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

  int N, C;
  cin >> N >> C;
  vector<int> V(N);
  for (auto& x : V)
    cin >> x;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int eaten = 0;
    int curAns = 0;
    for (int j = i; j < N; ++j) {
      if (V[j] + eaten <= C) {
        eaten += V[j];
        ++curAns;
      }
    }
    ans = max(ans, curAns);
  }
  cout << ans;
}
