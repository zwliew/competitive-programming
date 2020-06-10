/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

const vector<vector<int>> adj = {
    {}, {2, 4}, {3, 5}, {6}, {5, 7}, {6, 8}, {9}, {8}, {9, 0}, {},
};
int best = 0;
int k;
void backtrack(int u, int cur) {
  if (abs(cur - k) < abs(best - k)) {
    best = cur;
  }

  if (cur >= k) return;

  if (cur || u) backtrack(u, cur * 10 + u);
  for (int v : adj[u]) {
    backtrack(v, cur);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  while (t--) {
    cin >> k;
    best = 0;
    backtrack(1, 0);
    cout << best << '\n';
  }
}
