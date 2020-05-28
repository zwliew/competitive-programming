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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Find all the vertices with _no_ pair of neighbours (v1, v2) that are
  // neighbours of each other.
  int n;
  while (cin >> n && n != -1) {
    vector<unordered_set<int>> adj(n);
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        bool w;
        cin >> w;
        if (u != v && w) {
          adj[u].emplace(v);
        }
      }
    }

    for (int u = 0; u < n; ++u) {
      bool ok = 1;
      for (int v1 : adj[u]) {
        for (int v2 : adj[u]) {
          if (adj[v1].count(v2)) {
            ok = 0;
            break;
          }
        }
        if (!ok) break;
      }

      if (ok) {
        cout << u << ' ';
      }
    }

    cout << '\n';
  }
}
