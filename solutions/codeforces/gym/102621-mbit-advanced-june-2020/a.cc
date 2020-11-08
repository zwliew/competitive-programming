#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<int> h(N);
  for (auto& x : h)
    cin >> x;

  // vector<vector<int>> adj(N);
  vector<vector<int>> from(N);
  for (int i = 0; i < N - 1; ++i) {
    int dy = 0, dx = 0;
    for (int j = i + 1; j < N; ++j) {
      int cdy = h[j] - h[i];
      int cdx = j - i;
      if (j == i + 1 || cdy * dx >= dy * cdx) {
        // adj[i].push_back(j);
        from[j].push_back(i);
        dy = cdy;
        dx = cdx;
      }
    }
  }

  // BFS SSSP solution
  // vector<int> dist(N, INT_MAX);
  // dist[0] = 1;
  // queue<int> q;
  // q.push(0);
  // while (q.size()) {
  //   int u = q.front();
  //   q.pop();
  //   for (int v : adj[u]) {
  //     if (dist[v] > dist[u] + 1) {
  //       dist[v] = dist[u] + 1;
  //       q.push(v);
  //     }
  //   }
  // }
  // cout << dist[N - 1];

  // DP solution
  vector<int> dp(N, INT_MAX);
  dp[0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j : from[i]) {
      dp[i] = min(dp[i], dp[j]);
    }
    ++dp[i];
  }
  cout << dp[N - 1];
}
