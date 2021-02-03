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

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> room(N);
    for (auto& x : room) {
      cin >> x;
      --x;
    }
    vector<vector<int>> adj(N);
    vector<int> indeg(N);
    for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      ++indeg[v];
    }

    vector<vector<int>> q(2);
    for (int i = 0; i < N; ++i) {
      if (!indeg[i])
        q[room[i]].push_back(i);
    }

    int ans = INT_MAX;
    for (int start = 0; start < 2; ++start) {
      int cur = 0;
      int prev = start;
      auto curindeg = indeg;
      auto curq = q;
      while (curq[0].size() || curq[1].size()) {
        if (curq[prev].empty()) {
          prev = !prev;
          ++cur;
        }
        int u = curq[prev].back();
        curq[prev].pop_back();
        for (int v : adj[u]) {
          --curindeg[v];
          if (!curindeg[v]) {
            curq[room[v]].push_back(v);
          }
        }
      }
      ans = min(ans, cur);
    }
    cout << ans << "\n";
  }
}
