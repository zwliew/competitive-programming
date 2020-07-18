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

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, m;
  cin >> n >> m;
  vector<vpi> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].eb(v, w);
    adj[v].eb(u, w);
  }

  vi parent(n + 1);
  vll dist(n + 1, 1e18);
  dist[1] = 0;
  set<pair<ll, int>> q;
  // priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,
  // int>>>
  //    q;
  q.emplace(0, 1);
  while (q.size()) {
    auto [c, u] = *q.begin();
    q.erase(q.begin());
    // auto [c, u] = q.top();
    // q.pop();

    if (u == n) {
      int cur = n;
      vi path;
      while (cur) {
        path.eb(cur);
        cur = parent[cur];
      }
      for (int i = (int)path.size() - 1; ~i; --i) {
        cout << path[i] << ' ';
      }
      return 0;
    }

    // if (dist[u] != c)
    // continue;

    for (auto &[v, w] : adj[u]) {
      ll nc = w + c;
      if (nc >= dist[v])
        continue;
      q.erase({dist[v], v});
      dist[v] = nc;
      parent[v] = u;
      q.emplace(nc, v);
    }
  }

  cout << -1;
}
