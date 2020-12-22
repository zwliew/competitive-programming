#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, S;
  cin >> N >> M >> S;
  --S;
  queue<int> q;
  vector<vector<int>> adj(N);
  vector<int64_t> d(N, 1e18);
  d[S] = 0;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
  }
  q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }

  for (auto x : d) {
    if (x == 1e18) {
      cout << -1;
    } else {
      cout << x;
    }
    cout << " ";
  }
}
