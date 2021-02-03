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

  int N, M, D;
  cin >> N >> M >> D;
  unordered_map<string, int> deg;
  for (int i = 0; i < N; ++i) {
    string s;
    int cnt;
    cin >> s >> cnt;
    deg[s] = cnt;
  }

  unordered_map<string, vector<string>> adj;
  for (int i = 0; i < M; ++i) {
    string u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  string S;
  cin >> S;
  queue<pair<string, int>> q;
  q.emplace(S, 1);
  unordered_set<string> told;
  while (q.size()) {
    auto [u, d] = q.front();
    q.pop();
    if (d > D)
      continue;
    for (auto& v : adj[u]) {
      --deg[v];
      told.insert(v);
      if (!deg[v]) {
        q.emplace(v, d + 1);
      }
    }
  }
  cout << told.size() - told.count(S);
}
