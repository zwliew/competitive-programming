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

  int k, n, m;
  cin >> k >> n >> m;
  vector<vector<array<int, 3>>> flights(n);
  for (int i = 0; i < m; ++i) {
    int u, v, d, c;
    cin >> u >> v >> d >> c;
    flights[d - 1].push_back({u - 1, v - 1, c});
  }

  vector<vector<int>> customers(n + 1, vector<int>(k));
  for (int i = 0; i < k * n; ++i) {
    int u, d, c;
    cin >> u >> d >> c;
    customers[d - 1][u - 1] = c;
  }

  vector<int> waiting(k + 1);
  for (int i = 0; i < n; ++i) {
    vector<int> addend(k);
    for (auto& f : flights[i]) {
      if (customers[i][f[0]] < f[2]) {
        cout << "suboptimal";
        return 0;
      }
      customers[i][f[0]] -= f[2];
      addend[f[1]] += f[2];
    }
    for (int j = 0; j < k; ++j) {
      customers[i + 1][j] += addend[j] + customers[i][j];
    }
  }
  cout << "optimal";
}
