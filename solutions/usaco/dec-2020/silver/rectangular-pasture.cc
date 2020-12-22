#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/numeric>
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
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<array<int, 2>> pos(N);
  for (int i = 0; i < N; ++i) {
    cin >> pos[i][0] >> pos[i][1];
  }
  sort(pos.begin(), pos.end());

  int64_t ans = N + 1;
  for (int i = 0; i < N; ++i) {
    order_statistic_set<pair<int, int>> seen;
    int oi = INT_MIN;
    for (int j = i + 1; j < N; ++j) {
      int upper =
          seen.size() - seen.order_of_key({max(pos[j][1], pos[i][1]) + 1, 0});
      int lower = seen.order_of_key({min(pos[j][1], pos[i][1]), 0});
      ans += (lower + 1) * (upper + 1);
      seen.insert({pos[j][1], oi++});
    }
  }
  cout << ans;
}
