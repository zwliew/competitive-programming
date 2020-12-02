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
#include <random>
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

  const int INF = 1e9;
  int N, M, Q;
  while (cin >> N >> M >> Q && (N || M || Q)) {
    vector<vector<int>> d(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) {
      d[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      d[u][v] = min(d[u][v], w);
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (d[i][k] < INF && d[k][j] < INF) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          if (d[i][k] < INF && d[k][j] < INF && d[k][k] < 0) {
            d[i][j] = -INF;
          }
        }
      }
    }

    while (Q--) {
      int u, v;
      cin >> u >> v;
      if (d[u][v] == INF) {
        cout << "Impossible";
      } else if (d[u][v] == -INF) {
        cout << "-Infinity";
      } else {
        cout << d[u][v];
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
