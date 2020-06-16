/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

template <class T>
using Tree =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  Tree<pair<int, int>> t;
  for (int i = 0; i < n; ++i) {
    t.insert({a[i], i});
    if (i >= k) {
      t.erase({a[i - k], i - k});
    }
    if (i >= k - 1) {
      cout << t.find_by_order((k - 1) / 2)->first << ' ';
    }
  }
}
