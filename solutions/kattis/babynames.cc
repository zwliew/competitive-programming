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

  array<OrderStatisticTree<string>, 2> t;
  auto computePlacing = [&](int idx, string& start, string& end) {
    return t[idx].order_of_key(end) - t[idx].order_of_key(start);
  };

  int op;
  while (cin >> op && op) {
    if (op == 1) {
      string name;
      int gender;
      cin >> name >> gender;
      --gender;
      t[gender].insert(name);
    } else if (op == 2) {
      string name;
      cin >> name;
      t[0].erase(name);
      t[1].erase(name);
    } else {
      string start, end;
      int gender;
      cin >> start >> end >> gender;
      --gender;
      start.back()--;
      while (start.size() < 30) {
        start += 'Z';
      }
      if (gender == -1) {
        cout << computePlacing(0, start, end) + computePlacing(1, start, end)
             << "\n";
      } else {
        cout << computePlacing(gender, start, end) << "\n";
      }
    }
  }
}
