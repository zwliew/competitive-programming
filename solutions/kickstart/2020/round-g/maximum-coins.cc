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

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> grid[i][j];
      }
    }

    int64_t best = LLONG_MIN;
    for (int i = 0; i < N; ++i) {
      int64_t f = 0, s = 0;
      for (int j = 0; i + j < N; ++j) {
        f += grid[i + j][j];
        s += grid[j][i + j];
      }
      best = max({best, f, s});
    }

    cout << "Case #" << t << ": " << best << "\n";
  }
}
