#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Point updates and range sum queries (PURQ) on a dynamic array.
  // Use the simplest implementation of a binary-indexed tree.
  int n, q;
  cin >> n >> q;
  vector<ll> bit(n + 1);
  auto update = [&](int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx) {
      bit[idx] += val;
    }
  };
  auto query = [&](int idx) {
    ll res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += bit[idx];
    }
    return res;
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    update(i, x);
  }
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      int orig = query(b - 1) - (b >= 2 ? query(b - 2) : 0);
      update(b - 1, -orig + c);
    } else {
      cout << query(c - 1) - (b >= 2 ? query(b - 2) : 0) << '\n';
    }
  }
}
