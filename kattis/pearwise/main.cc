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

void dfs(unordered_set<int> &vis, vector<vector<int>> &pairs, int u) {
  for (int v = 0; v < pairs[u].size(); ++v) {
    if (pairs[u][v] > 0 && !vis.count(v)) {
      vis.emplace(v);
      dfs(vis, pairs, v);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Construct a directed, unweighted graph where u->v iff u beats v in a pair.
  // We can do this by precomputing the result of every pair (u, v) and store
  // them in an adjacency matrix.  Traverse the graph from any u. If we visit
  // all other vertices, it means that there is an agenda that u wins.
  int v, m;
  cin >> v >> m;
  vector<vector<int>> pairs(v, vector<int>(v));
  for (int i = 0; i < m; ++i) {
    int p;
    cin >> p;
    string b;
    cin >> b;
    for (int j = 0; j < v; ++j) {
      for (int k = j + 1; k < v; ++k) {
        pairs[b[j] - 'A'][b[k] - 'A'] += p;
        pairs[b[k] - 'A'][b[j] - 'A'] -= p;
      }
    }
  }

  for (int s = 0; s < v; ++s) {
    unordered_set<int> vis;
    vis.emplace(s);
    dfs(vis, pairs, s);
    cout << (char)(s + 'A') << ": ";
    if (vis.size() == v) {
      cout << "can win\n";
    } else {
      cout << "can't win\n";
    }
  }
}
