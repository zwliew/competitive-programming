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
#define FILE ""
#endif

vector<int> comp, h;
int len;

int getMinIdx(int l, int r) {
  int res = l;
  for (int i = l; i <= r;) {
    if (i % len == 0 && i + len - 1 <= r) {
      if (h[comp[i / len]] < h[res]) {
        res = comp[i / len];
      }
      i += len;
    } else {
      if (h[i] < h[res]) {
        res = i;
      }
      ++i;
    }
  }
  return res;
}

int getMaxArea(int l, int r) {
  if (l > r)
    return 0;
  int minIdx = getMinIdx(l, r);
  return max({getMaxArea(l, minIdx - 1), getMaxArea(minIdx + 1, r),
              (r - l + 1) * h[minIdx]});
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Find the largest rectangular area in a histogram.
  // Solution based on:
  // https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
  //
  // General idea is to use D&C principles:
  // Let A(l, r) = max area in the range [l, r]
  // Also let i denote the index of the min value in the range [l, r]
  // Then, A(l, r) = max((r - l + 1) * i, A(l, i - 1), A(i + 1, r))
  //
  // Use sqrt decomposition to semi-efficiently find the minimum value in the
  // range.
  int n;
  cin >> n;
  h.resize(n);
  for (auto& x : h)
    cin >> x;
  int ans = 0;

  len = (int)sqrt(n) + 1;
  comp.assign(len, -1);
  for (int i = 0; i < n; ++i) {
    if (comp[i / len] == -1 || h[i] < h[comp[i / len]]) {
      comp[i / len] = i;
    }
  }
  ans = getMaxArea(0, n - 1);

  // O(n) time solution using a stack
  // Reference: http://www.informatik.uni-ulm.de/acm/Locals/2003/html/judge.html
  // http://www.informatik.uni-ulm.de/acm/Locals/2003/html/histogram.html
  //
  // stack<int> s;
  // for (int i = 0; i < n; ++i) {
  //   while (s.size() && h[s.top()] > a[i]) {
  //     int hi = s.top();
  //     s.pop();
  //     ans = max(ans, h[hi] * (i - (s.empty() ? 0 : s.top() + 1)));
  //   }
  //   s.push(i);
  // }
  // while (s.size()) {
  //   int hi = s.top();
  //   s.pop();
  //   ans = max(ans, h[hi] * (n - (s.empty() ? 0 : s.top() + 1)));
  // }
  // cout << ans;
}