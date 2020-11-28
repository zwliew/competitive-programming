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

  int N, sx, sy, ex, ey;
  cin >> N >> sx >> sy >> ex >> ey;

  if (sx > ex) {
    swap(sx, ex);
    swap(sy, ey);
  }
  bool dec = sy > ey;

  vector<pair<int, int>> pos;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    if (x >= sx && x <= ex) {
      if (dec && y >= ey && y <= sy) {
        pos.emplace_back(x, -y);
      } else if (!dec && y >= sy && y <= ey) {
        pos.emplace_back(x, y);
      }
    }
  }
  sort(pos.begin(), pos.end());

  vector<int> dp;
  for (auto& [x, y] : pos) {
    auto it = upper_bound(dp.begin(), dp.end(), y);
    if (it == dp.end()) {
      dp.push_back(y);
    } else {
      *it = y;
    }
  }
  cout << dp.size();
}
