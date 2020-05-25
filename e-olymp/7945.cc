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

bool dfs(unordered_map<string, vector<string>> &adj,
         unordered_map<string, int> &state, string u) {
  state[u] = 1;
  for (auto v : adj[u]) {
    if (!state.count(v)) {
      if (dfs(adj, state, v)) {
        return true;
      }
    } else if (state[v] == 1) {
      return true;
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
  unordered_map<string, vector<string>> adj;
  unordered_set<string> names;
  for (int i = 0; i < n; ++i) {
    string a, b, c;
    cin >> a >> c >> b;
    names.emplace(a);
    names.emplace(b);
    if (c == ">") {
      adj[a].eb(b);
    } else {
      adj[b].eb(a);
    }
  }

  unordered_map<string, int> state;
  for (auto &u : names) {
    if (!state.count(u) && dfs(adj, state, u)) {
      cout << "impossible";
      return 0;
    }
  }
  cout << "possible";
}
