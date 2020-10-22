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

  vector<pair<int, int>> deltas;
  for (int x = 0; x <= 2018; ++x) {
    int y = 4072324 - x * x;
    int rt = sqrt(y);
    if (rt * rt == y) {
      deltas.emplace_back(x, rt);
    }
  }

  int n;
  cin >> n;
  set<pair<int, int>> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    for (auto& [dx, dy] : deltas) {
      cnt += s.count({x + dx, y + dy});
      if (dx)
        cnt += s.count({x - dx, y + dy});
      if (dy)
        cnt += s.count({x + dx, y - dy});
      if (dx && dy)
        cnt += s.count({x - dx, y - dy});
    }
    s.emplace(x, y);
  }
  cout << cnt;
}
