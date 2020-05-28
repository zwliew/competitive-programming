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

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

bool dfs(vector<vi> &adj, vi &state, int u) {
  state[u] = 1;
  for (auto v : adj[u]) {
    if (state[v] == 1) return true;
    if (state[v] == 0) {
      if (dfs(adj, state, v)) return true;
    }
  }
  state[u] = 2;
  return false;
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
  vector<vi> adj(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      if (x) {
        adj[i].eb(j);
      }
    }
  }

  vi state(n + 1);
  for (int u = 1; u <= n; ++u) {
    if (!state[u] && dfs(adj, state, u)) {
      cout << 1;
      return 0;
    }
  }

  cout << 0;
}
