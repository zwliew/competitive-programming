#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "measurement"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m, d;
  cin >> n >> m >> d;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].emplace_back(v, c);
  }

  vector<int> p(n + 1);
  int l = -1, r = 1e9 + 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;

    vector<int> cp(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    queue<int> q;
    q.emplace(1);
    while (q.size()) {
      int u = q.front();
      q.pop();
      if (u == n) {
        break;
      }

      for (auto& [v, c] : adj[u]) {
        if (c <= mid && dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          cp[v] = u;
          q.emplace(v);
        }
      }
    }

    if (dist[n] <= d) {
      r = mid;
      p = cp;
    } else {
      l = mid;
    }
  }

  if (r == 1e9 + 1) {
    cout << -1;
  } else {
    vector<int> path;
    int u = n;
    while (u) {
      path.emplace_back(u);
      u = p[u];
    }
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << '\n';
    for (int x : path) {
      cout << x << ' ';
    }
  }
}
