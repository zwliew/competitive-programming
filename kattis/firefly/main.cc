#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Try every height and binary search for the number of
  // stalagmites/stalactites that collide with the firefly at that height.
  int n, h;
  cin >> n >> h;
  vector<int> bottom, top;
  for (int i = 0; i < n; ++i) {
    int length;
    cin >> length;
    if (i & 1) {
      top.emplace_back(length);
    } else {
      bottom.emplace_back(length);
    }
  }
  sort(top.begin(), top.end());
  sort(bottom.begin(), bottom.end());

  int ans = 1e9;
  int cnt = 0;
  for (int height = 1; height <= h; ++height) {
    int topHeight = h - height + 1;
    int cur =
        distance(lower_bound(bottom.begin(), bottom.end(), height),
                 bottom.end()) +
        distance(lower_bound(top.begin(), top.end(), topHeight), top.end());
    if (cur < ans) {
      ans = cur;
      cnt = 1;
    } else if (cur == ans) {
      ++cnt;
    }
  }

  cout << ans << ' ' << cnt;

  // Alternative solution using binary-indexed trees to update the number of
  // obstacles within a range of heights
  // int n, h;
  // cin >> n >> h;

  // vector<int> bit(h + 1);
  // auto add = [&](int idx, int val) {
  //   for (; idx <= h; idx += idx & -idx) {
  //     bit[idx] += val;
  //   }
  // };
  // auto query = [&](int idx) {
  //   int res = 0;
  //   for (; idx; idx -= idx & -idx) {
  //     res += bit[idx];
  //   }
  //   return res;
  // };
  // auto radd = [&](int l, int r, int val) {
  //   add(l, val);
  //   add(r + 1, -val);
  // };

  // for (int i = 0; i < n; ++i) {
  //   int length;
  //   cin >> length;

  //   int lo, hi;
  //   if (i & 1) {
  //     lo = h - length + 1;
  //     hi = h;
  //   } else {
  //     lo = 1;
  //     hi = length;
  //   }

  //   radd(lo, hi, 1);
  // }

  // int ans = 1e9;
  // int cnt = 0;
  // for (int height = 1; height <= h; ++height) {
  //   int cur = query(height);
  //   if (cur < ans) {
  //     ans = cur;
  //     cnt = 1;
  //   } else if (cur == ans) {
  //     ++cnt;
  //   }
  // }

  // cout << ans << ' ' << cnt;
}
