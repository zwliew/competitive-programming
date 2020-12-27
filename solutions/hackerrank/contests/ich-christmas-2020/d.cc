#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> bound(M, INT_MIN);
  for (int i = 0; i < N; ++i) {
    int& x = A[i];
    cin >> x;
    --x;
    bound[x] = max(bound[x], i);
  }

  int ans = 0;
  int mx = INT_MIN;
  unordered_set<int> joined;
  for (int i = 0; i < N; ++i) {
    if (mx < i) {
      joined.clear();
    } else if (!joined.count(A[i])) {
      ++ans;
    }
    joined.insert(A[i]);
    mx = max(mx, bound[A[i]]);
  }
  cout << ans;
}
