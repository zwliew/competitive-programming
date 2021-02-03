#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

bool isCyclic(unordered_map<string, vector<string>>& adj,
              unordered_map<string, int>& state,
              string u) {
  state[u] = 1;
  for (auto& v : adj[u]) {
    if (!state[v] && isCyclic(adj, state, v)) {
      return true;
    }
    if (state[v] == 1) {
      return true;
    }
  }
  state[u] = 2;
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  while (cin >> N && N) {
    string line;
    getline(cin, line);
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> indeg;
    for (int i = 0; i < N; ++i) {
      getline(cin, line);
      istringstream ss(line);
      string name;
      ss >> name;
      indeg[name] = 0;
      while (ss >> line) {
        adj[line].push_back(name);
        ++indeg[name];
      }
    }

    unordered_map<string, int> state;
    bool cyclic = false;
    for (auto& [k, _] : adj) {
      if (!state[k] && isCyclic(adj, state, k)) {
        cyclic = true;
        break;
      }
    }

    if (cyclic) {
      cout << "cannot be ordered\n\n";
      continue;
    }

    priority_queue<string, vector<string>, greater<string>> q;
    for (auto& [k, v] : indeg) {
      if (!v) {
        q.push(k);
      }
    }

    vector<string> order;
    while (q.size()) {
      auto u = q.top();
      q.pop();
      order.push_back(u);
      for (auto& v : adj[u]) {
        --indeg[v];
        if (!indeg[v]) {
          q.push(v);
        }
      }
    }

    for (auto& x : order) {
      cout << x << "\n";
    }
    cout << "\n";
  }
}
