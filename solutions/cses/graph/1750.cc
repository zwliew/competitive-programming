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
#define FILE "mootube"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Use binary lifting to compute the nodes we end up on for every 2^k
  // distance.
  int n, q;
  cin >> n >> q;
  vector<vector<int>> up(n, vector<int>(30));
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    --t;
    up[i][0] = t;
  }

  for (int i = 1; i < 30; ++i) {
    for (int j = 0; j < n; ++j) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }

  while (q--) {
    int x, k;
    cin >> x >> k;
    --x;
    int i = 0;
    while (k) {
      if (k & 1) {
        x = up[x][i];
      }
      k >>= 1;
      ++i;
    }
    cout << x + 1 << '\n';
  }
}
