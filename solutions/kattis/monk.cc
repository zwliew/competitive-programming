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

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> asc, desc;
  int totalHeight = 0;
  int totalTime = 0;
  for (int i = 0; i < n; ++i) {
    int h, t;
    cin >> h >> t;
    asc.emplace_back(h, t);
    totalHeight += h;
    totalTime += t;
  }
  for (int i = 0; i < m; ++i) {
    int h, t;
    cin >> h >> t;
    desc.emplace_back(h, t);
  }

  double l = 0;
  double r = totalTime;
  for (int i = 0; i < 100; ++i) {
    double mid = (l + r) / 2;
    double up = 0;
    double down = totalHeight;
    double rem = mid;
    for (int j = 0; j < n && rem; ++j) {
      double dur = min<double>(rem, asc[j].second);
      rem -= dur;
      up += dur / asc[j].second * asc[j].first;
    }
    rem = mid;
    for (int j = 0; j < m && rem; ++j) {
      double dur = min<double>(rem, desc[j].second);
      rem -= dur;
      down -= dur / desc[j].second * desc[j].first;
    }
    if (up >= down) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(5) << r;
}
