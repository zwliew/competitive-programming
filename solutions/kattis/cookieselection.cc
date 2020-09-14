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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
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

  // Use an order statistic tree to efficiently query the median.
  string c;
  int cnt = 0;
  OrderStatisticTree<pair<int, int>> t;
  while (cin >> c) {
    if (c == "#") {
      auto it = t.find_by_order(t.size() / 2);
      cout << it->first << '\n';
      t.erase(it);
    } else {
      int x = stoi(c);
      t.insert({x, cnt++});
    }
  }

  // Alternative: split the elements into 2 heaps to keep track of the median.
  // priority_queue<int> maxq;
  // priority_queue<int, vector<int>, greater<int>> minq;
  // string c;
  // while (cin >> c) {
  //   if (c == "#") {
  //     cout << minq.top() << '\n';
  //     minq.pop();
  //     if (minq.size() < maxq.size()) {
  //       minq.push(maxq.top());
  //       maxq.pop();
  //     }
  //   } else {
  //     int x = stoi(c);
  //     if (minq.empty() || x >= minq.top()) {
  //       minq.push(x);
  //     } else {
  //       maxq.push(x);
  //     }
  //     if (minq.size() < maxq.size()) {
  //       minq.push(maxq.top());
  //       maxq.pop();
  //     } else if (minq.size() > maxq.size() + 1) {
  //       maxq.push(minq.top());
  //       minq.pop();
  //     }
  //   }
  // }
}
