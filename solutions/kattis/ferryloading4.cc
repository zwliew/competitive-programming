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

struct cmp {
  bool operator()(const pair<int64_t, string>& x,
                  const pair<int64_t, string>& y) const {
    if (x.first == y.first)
      return x.second < y.second;
    return x.first > y.first;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Simulate the loading process with queues
  int t;
  cin >> t;
  while (t--) {
    int l, m;
    cin >> l >> m;
    l *= 100;
    bool side = true;
    array<queue<int>, 2> cars;
    while (m--) {
      int len;
      string s;
      cin >> len >> s;
      cars[s == "left"].push(len);
    }
      
    int cnt = 0;
    while (cars[0].size() || cars[1].size()) {
      int left = l;
      while (cars[side].size() && left >= cars[side].front()) {
        left -= cars[side].front();
        cars[side].pop();
      }
      ++cnt;
      side = !side;
    }

    cout << cnt << "\n";
  }
}
