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

vector<string> best;
bool found;

int backtrack(set<pair<int, string>> &colors,
              unordered_map<string, unordered_set<string>> &adj,
              vector<string> &painting, int left) {
  if (!left) {
    if (!found) {
      found = true;
      best = painting;
    }
    return 1;
  }

  int count = 0;
  vector<pair<int, string>> copiedColors(colors.begin(), colors.end());
  for (auto &x : copiedColors) {
    auto &[k, v] = x;
    if (painting.empty() || !adj[painting.back()].count(v)) {
      colors.erase(x);
      painting.emplace_back(v);
      count += backtrack(colors, adj, painting, left - 1);
      painting.pop_back();
      colors.emplace(x);
    }
  }
  return count;
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
    int n, m;
    cin >> n;
    set<pair<int, string>> colors;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      colors.emplace(i, s);
    }
    cin >> m;
    unordered_map<string, unordered_set<string>> adj;
    for (int i = 0; i < m; ++i) {
      string u, v;
      cin >> u >> v;
      adj[u].emplace(v);
      adj[v].emplace(u);
    }

    found = false;

    vector<string> painting;
    int count = backtrack(colors, adj, painting, n);
    cout << count << '\n';
    for (auto &x : best) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
