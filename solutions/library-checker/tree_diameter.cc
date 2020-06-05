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

vi actualPath;
void dfs2(vector<vpi> &adj, vi &path, int u, int p, int t) {
  path.eb(u);
  if (u == t) {
    actualPath = path;
    return;
  }
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      dfs2(adj, path, v, u, t);
    }
  }
  path.pop_back();
}

pair<int, ll> dfs(vector<vpi> &adj, int p, int u, ll c) {
  pair<int, ll> best = {u, c};
  for (auto &[v, w] : adj[u]) {
    if (v == p)
      continue;
    auto [candidate, cdist] = dfs(adj, u, v, c + w);
    if (cdist > best.s) {
      best = {candidate, cdist};
    }
  }
  return best;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n;
  cin >> n;
  vector<vpi> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].eb(v, w);
    adj[v].eb(u, w);
  }

  auto [furthest, dist] = dfs(adj, -1, 0, 0);
  auto [actual, adist] = dfs(adj, -1, furthest, 0);
  vi path;
  dfs2(adj, path, furthest, -1, actual);

  cout << adist << ' ' << actualPath.size() << '\n';
  for (int x : actualPath) {
    cout << x << ' ';
  }
}
