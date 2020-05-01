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
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

// void dfs(vector<vi> &adj, vector<bool> &vis, int u) {
//   for (int v : adj[u]) {
//     if (vis[v]) continue;
//     vis[v] = 1;
//     dfs(adj, vis, v);
//   }
// }

int find(vi &p, int a) { return (p[a] == a ? a : (p[a] = find(p, p[a]))); }
void join(vi &p, int a, int b) { p[find(p, a)] = find(p, b); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Number of roads needed to be built == number of connected components - 1.
  // Can use DFS/BFS to count the connected components.
  // Alternatively, use disjoint sets.
  int v, e;
  cin >> v >> e;

  // Primary solution using DFS.
  // vector<vi> adj(v);
  // for (int i = 0; i < e; ++i) {
  //   int a, b;
  //   cin >> a >> b;
  //   --a, --b;
  //   adj[a].emplace_back(b);
  //   adj[b].emplace_back(a);
  // }

  // vector<bool> vis(v);
  // vi sources;
  // for (int i = 0; i < v; ++i) {
  //   if (vis[i]) continue;
  //   vis[i] = 1;
  //   dfs(adj, vis, i);
  //   sources.emplace_back(i);
  // }

  // cout << sources.size() - 1 << '\n';
  // for (int i = 1; i < sources.size(); ++i) {
  //   cout << sources[i - 1] + 1 << ' ' << sources[i] + 1 << '\n';
  // }

  // Alternative solution using disjoint sets.
  vi parents(v);
  iota(parents.begin(), parents.end(), 0);

  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    join(parents, a, b);
  }

  for (int i = 0; i < v; ++i) {
    find(parents, i);
  }

  unordered_set<int> sources(parents.begin(), parents.end());
  cout << sources.size() - 1 << '\n';
  int prev = -1;
  for (int s : sources) {
    if (prev != -1) {
      cout << prev + 1 << ' ' << s + 1 << '\n';
    }
    prev = s;
  }
}
