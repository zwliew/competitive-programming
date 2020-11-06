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

  int W, vh, N;
  cin >> W >> vh >> N;
  vector<pair<int, int>> pos(N);
  for (auto& [x, y] : pos)
    cin >> x >> y;
  int S;
  cin >> S;
  vector<int> skis(S);
  for (auto& x : skis)
    cin >> x;
  sort(skis.begin(), skis.end());

  auto ok = [&](int m) {
    double xmin = pos[0].first;
    double xmax = xmin + W;
    for (int i = 1; i < N && xmin <= xmax; ++i) {
      double t = (double)(pos[i].second - pos[i - 1].second) / m;
      double d = vh * t;
      xmin = max<double>(xmin - d, pos[i].first);
      xmax = min<double>(xmax + d, pos[i].first + W);
    }
    return xmin <= xmax;
  };

  int l = 1;
  int r = 1e6 + 1;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (ok(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  auto it = upper_bound(skis.begin(), skis.end(), l);
  if (it == skis.begin() || !ok(l)) {
    cout << "IMPOSSIBLE";
  } else {
    cout << *prev(it);
  }
}
