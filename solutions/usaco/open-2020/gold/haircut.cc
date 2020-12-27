#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
#define FILE "haircut"

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

  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& x : A)
    cin >> x;

  vector<int64_t> delta(N + 1);
  order_statistic_set<pair<int, int>> ost;
  for (int i = 0; i < N; ++i) {
    delta[A[i]] += i - ost.order_of_key({A[i], i});
    ost.insert({A[i], i});
  }

  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    cout << ans << "\n";
    ans += delta[i];
  }
}
