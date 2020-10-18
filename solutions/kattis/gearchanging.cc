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

  int n, m, p;
  cin >> n >> m >> p;
  vector<int> crank(n), wheel(m);
  for (auto& x : crank)
    cin >> x;
  for (auto& x : wheel)
    cin >> x;

  vector<pair<int64_t, int64_t>> cadences(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cadences[i * m + j] = {wheel[j], crank[i]};
    }
  }
  sort(cadences.begin(), cadences.end(), [](auto& x, auto& y) {
    return x.first * y.second < y.first * x.second;
  });

  for (int i = 1; i < n * m; ++i) {
    if (cadences[i].first * cadences[i - 1].second * 100 >
        (100 + p) * cadences[i].second * cadences[i - 1].first) {
      cout << "Time to change gears!";
      return 0;
    }
  }
  cout << "Ride on!";
}
