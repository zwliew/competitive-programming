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
  vector<char> V(N);
  for (auto& x : V)
    cin >> x;

  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (V[i] == V[i + 1])
      ++ans;
  }
  cout << ans;
}
