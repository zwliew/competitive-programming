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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k, x;
  cin >> n >> k >> x;
  vector<int> c(n);
  for (auto& x : c)
    cin >> x;

  auto leftSeg = [&](int r) {
    int cur = r;
    for (; cur >= 0 && c[cur] == c[r]; --cur)
      ;
    return r - cur;
  };
  auto rightSeg = [&](int l) {
    int cur = l;
    for (; cur < n && c[cur] == c[l]; ++cur)
      ;
    return cur - l;
  };
  auto contigSegLen = [&](int i) {
    int l = leftSeg(i);
    int r = rightSeg(i);
    return r + l - 1;
  };

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (x != c[i])
      continue;
    int cur = contigSegLen(i);
    if (cur < 2)
      continue;
    int l = i - leftSeg(i), r = i + rightSeg(i);
    while (l >= 0 && r < n && c[l] == c[r] && leftSeg(l) + rightSeg(r) >= 3) {
      int nl = leftSeg(l);
      int nr = rightSeg(r);
      cur += nl + nr;
      r += nr;
      l -= nl;
    }
    ans = max(ans, cur);
  }
  cout << ans;
}
