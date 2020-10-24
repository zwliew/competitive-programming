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

  int n;
  cin >> n;
  set<tuple<int, int, int>> ranges;
  ranges.emplace(1, n, 0);
  int64_t c = 0;
  while (n--) {
    int x;
    cin >> x;
    auto it = ranges.lower_bound({x + 1, 0, 0});
    it = prev(it);
    auto [l, r, d] = *it;
    ranges.erase(it);
    c += d;
    if (x > l) {
      ranges.emplace(l, x - 1, d + 1);
    }
    if (x < r) {
      ranges.emplace(x + 1, r, d + 1);
    }
    cout << c << "\n";
  }
}
