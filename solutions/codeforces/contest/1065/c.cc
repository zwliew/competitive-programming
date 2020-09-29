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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "feast"
#endif

struct FenwickTree {
  vector<int> t;
  int n;
  FenwickTree(int _n) {
    n = _n + 1;
    t.resize(n);
  }

  void add(int l, int r, int x) {
    add(l, x);
    add(r, -x);
  }

  void add(int i, int x) {
    for (++i; i < n; i += i & -i) {
      t[i] += x;
    }
  }

  int get(int i) {
    int res = 0;
    for (++i; i; i -= i & -i) {
      res += t[i];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;

  FenwickTree t(2e5 + 1);
  int minHeight = 2e5 + 1;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    t.add(1, h + 1, 1);
    minHeight = min(minHeight, h);
  }

  int cnt = 0;
  int curSum = 0;
  for (int i = 2e5; i > minHeight; --i) {
    int nxt = t.get(i);
    if (curSum + nxt > k) {
      curSum = 0;
      ++cnt;
    }
    curSum += nxt;
  }
  if (curSum) {
    ++cnt;
  }
  cout << cnt;
}
