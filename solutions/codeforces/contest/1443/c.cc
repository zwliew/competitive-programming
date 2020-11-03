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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> vals(n);
    for (auto& [a, _] : vals)
      cin >> a;
    for (auto& [_, b] : vals)
      cin >> b;
    sort(vals.begin(), vals.end());
    int64_t apre = 0;
    int64_t bsuf = accumulate(vals.begin(), vals.end(), (int64_t)0,
                              [&](auto& x, auto& y) { return x + y.second; });
    int64_t best = bsuf;
    for (int i = 0; i < n; ++i) {
      apre = max(apre, vals[i].first);
      bsuf -= vals[i].second;
      best = min(best, max(apre, bsuf));
    }
    cout << best << "\n";
  }
}
