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

  // Use order statistic trees to find the number of elements strictly smaller
  // than a[i]
  int n;
  cin >> n;
  vector<int64_t> a(n);
  int cnt = 0;
  OrderStatisticTree<pair<int64_t, int>> sufTree;
  for (auto& x : a) {
    cin >> x;
    sufTree.insert({x, cnt++});
  }

  int64_t total = 0;
  OrderStatisticTree<pair<int64_t, int>> preTree;
  preTree.insert({a[0], cnt++});
  sufTree.erase(sufTree.lower_bound({a[0], INT_MIN}));
  for (int i = 1; i < n - 1; ++i) {
    sufTree.erase(sufTree.lower_bound({a[i], INT_MIN}));
    int l = preTree.order_of_key(make_pair(a[i], INT_MIN));
    int r = sufTree.order_of_key(make_pair(a[i], INT_MIN));
    total += (int64_t)r * l;
    preTree.insert({a[i], cnt++});
  }
  cout << total;
}
