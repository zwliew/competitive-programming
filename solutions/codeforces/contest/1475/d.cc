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

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    array<vector<int>, 2> apps;
    int64_t total = 0;
    vector<int> A(N);
    for (auto& x : A) {
      cin >> x;
      if (total < M) {
        total += x;
      }
    }

    for (int i = 0; i < N; ++i) {
      int b;
      cin >> b;
      apps[b - 1].push_back(A[i]);
    }

    if (total < M) {
      cout << "-1\n";
      continue;
    }

    for (int i = 0; i < 2; ++i) {
      sort(apps[i].begin(), apps[i].end());
    }

    int ans = 0;
    while (M > 0) {
      int fsz = apps[0].size();
      int ssz = apps[1].size();
      if (fsz && (!ssz || apps[0].back() >= M ||
                  (apps[0][fsz - 1] + (fsz == 1 ? 0 : apps[0][fsz - 2]) >=
                   apps[1].back()))) {
        M -= apps[0].back();
        apps[0].pop_back();
        ++ans;
      } else {
        M -= apps[1].back();
        apps[1].pop_back();
        ans += 2;
      }
    }
    cout << ans << "\n";
  }
}
