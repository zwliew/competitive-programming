#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Find the max weight w of the new edge (u,v) such that dist(0, n - 1) >
  // min(dist(0, u) + dist(n - 1, v), dist(0, v) + dist(n - 1, u)) + w.
  int n, e;
  cin >> n >> e;
  vector<vii> adj(n);
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  vi sdist(n, 1e9);
  sdist[0] = 0;
  priority_queue<ii, vii, greater<ii>> q;
  q.emplace(0, 0);
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (d > sdist[u]) continue;
    for (auto &[v, w] : adj[u]) {
      if (w + d < sdist[v]) {
        sdist[v] = w + d;
        q.emplace(w + d, v);
      }
    }
  }

  vi ddist(n, 1e9);
  ddist[n - 1] = 0;
  q.emplace(0, n - 1);
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (d > ddist[u]) continue;
    for (auto [v, w] : adj[u]) {
      if (w + d < ddist[v]) {
        ddist[v] = w + d;
        q.emplace(w + d, v);
      }
    }
  }

  int k;
  cin >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    int cur = min(sdist[u] + ddist[v], sdist[v] + ddist[u]);
    int delta = sdist[n - 1] - cur - 1;
    if (delta < 0) {
      cout << -1;
    } else {
      cout << delta;
    }
    cout << '\n';
  }
}
