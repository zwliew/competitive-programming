/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "revegetate"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> color(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  color[1] = 1;
  cout << 1;
  for (int i = 2; i <= n; ++i) {
    bitset<5> ok;
    ok.set();
    for (int j = 0; j < adj[i].size(); ++j) {
      ok[color[adj[i][j]]] = false;
    }

    for (int j = 1; j <= 4; ++j) {
      if (ok[j]) {
        color[i] = j;
        break;
      }
    }

    cout << color[i];
  }
}
