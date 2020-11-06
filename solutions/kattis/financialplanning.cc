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
  vector<pair<int, int>> investments(n);
  for (auto& [p, c] : investments)
    cin >> p >> c;

  int l = 0;
  int r = 2e9 + 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    int64_t total = 0;
    for (auto& [p, c] : investments) {
      int64_t earnings = (int64_t)mid * p - c;
      int64_t diff = min(earnings, m - total);
      if (diff > 0) {
        total += diff;
        if (total >= m) {
          break;
        }
      }
    }
    if (total >= m) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r;
}
