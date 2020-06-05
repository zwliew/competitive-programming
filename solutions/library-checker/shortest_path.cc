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

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vpi> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].eb(v, w);
  }

  vi parent(n, -1);
  vll dist(n, 1e18);
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      q;
  q.emplace(0, s);
  while (q.size()) {
    auto [c, u] = q.top();
    q.pop();

    if (u == t) {
      vpi edges;
      int cur = t;
      while (parent[cur] != -1) {
        edges.eb(parent[cur], cur);
        cur = parent[cur];
      }
      cout << c << ' ' << edges.size() << '\n';
      for (int i = (int)edges.size() - 1; ~i; --i) {
        cout << edges[i].f << ' ' << edges[i].s << '\n';
      }
      return 0;
    }

    if (c > dist[u])
      continue;

    for (auto &[v, w] : adj[u]) {
      ll ndist = c + w;
      if (ndist >= dist[v])
        continue;
      dist[v] = ndist;
      parent[v] = u;
      q.emplace(ndist, v);
    }
  }

  cout << -1;
}
