#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

// Source:
// https://github.com/ecnerwala/cp-book/blob/master/src/order_statistic.hpp

// Supports
// auto iterator = order_statistic_set().find_by_order(idx); // 0-indexed
// int num_strictly_smaller = order_statistic_set().order_of_key(key);

#include <ext/pb_ds/assoc_container.hpp>

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map =
    __gnu_pbds::tree<K,
                     V,
                     Comp,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int64_t ans = 0;
    order_statistic_set<int> ost;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      ans += i - ost.order_of_key(x);
      ost.insert(x);
    }
    cout << ans << "\n";
  }
}
