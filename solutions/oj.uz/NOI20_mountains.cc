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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <class T>
using OrderStatisticTree =
    __gnu_pbds::tree<T,
                     __gnu_pbds::null_type,
                     less<T>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Iterate through each possible middle mountain, and count the number of
  // mountains shorter than the middle mountain on both sides.
  // Do the counting efficiently using an order statistic tree.
  int n;
  cin >> n;
  vector<int64_t> h(n);
  OrderStatisticTree<pair<int64_t, int>> left, right;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    right.insert({h[i], i});
  }

  int64_t ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    right.erase(right.lower_bound({h[i], 0}));
    ans +=
        (int64_t)left.order_of_key({h[i], 0}) * right.order_of_key({h[i], 0});
    left.insert({h[i], i});
  }
  cout << ans;
}
