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

  // Range update point sum queries (RUPQ) on a dynamic array
  // Use a slightly modified version of a binary-indexed tree
  int n, q;
  cin >> n >> q;
  vector<ll> bit(n + 1);
  auto update = [&](int idx, int x) {
    for (++idx; idx <= n; idx += idx & -idx) {
      bit[idx] += x;
    }
  };
  auto query = [&](int idx) {
    ll res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += bit[idx];
    }
    return res;
  };
  auto rUpdate = [&](int l, int r, int x) {
    update(l, x);
    update(r + 1, -x);
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    rUpdate(i, i, x);
  }
  while (q--) {
    int a, b, c, d;
    cin >> a >> b;
    if (a == 1) {
      cin >> c >> d;
      rUpdate(b - 1, c - 1, d);
    } else {
      cout << query(b - 1) << '\n';
    }
  }
}
