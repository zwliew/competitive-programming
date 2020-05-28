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

bool dfs(vector<unordered_set<int>> &adj, vi &color, int u, int col) {
  color[u] = col;
  for (auto v : adj[u]) {
    if (color[v] == col) {
      return false;
    }
    if (!color[v]) {
      dfs(adj, color, v, col == 1 ? 2 : 1);
    }
  }
  return true;
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
  vector<unordered_set<int>> adj(n + 1);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].emplace(b);
    adj[b].emplace(a);
  }

  int k;
  cin >> k;

  vi color(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!color[i] && !dfs(adj, color, i, 1)) {
      cout << 0;
      return 0;
    }
  }

  vi first, second, extra;
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 1) {
      first.eb(i);
    } else if (color[i] == 2) {
      second.eb(i);
    } else {
      extra.eb(i);
    }
  }

  if (first.size() + extra.size() >= k) {
    for (int i = 0; i < min((int)first.size(), k); ++i) {
      cout << first[i] << ' ';
    }
    for (int i = min((int)first.size(), k); i < k - min((int)first.size(), k);
         ++i) {
      cout << extra[i] << ' ';
    }
  } else if (second.size() + extra.size() >= k) {
    for (int i = 0; i < min((int)second.size(), k); ++i) {
      cout << second[i] << ' ';
    }
    for (int i = min((int)second.size(), k); i < k - min((int)second.size(), k);
         ++i) {
      cout << extra[i] << ' ';
    }

  } else {
    cout << 0;
  }
}
