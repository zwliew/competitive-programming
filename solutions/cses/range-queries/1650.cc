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

void build(vector<int>& a, vector<int>& t, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = tl + (tr - tl) / 2;
    build(a, t, v * 2, tl, tm);
    build(a, t, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] ^ t[v * 2 + 1];
  }
}

int query(vector<int>& t, int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = tl + (tr - tl) / 2;
  return query(t, v * 2, tl, tm, l, min(tm, r)) ^
         query(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Range XOR queries on a static array
  // Use a standard segment tree for this
  // int n, q;
  // cin >> n >> q;
  // vector<int> x(n), t(n * 4);
  // for (int& i : x)
  //   cin >> i;
  // build(x, t, 1, 0, n - 1);
  // while (q--) {
  //   int l, r;
  //   cin >> l >> r;
  //   cout << query(t, 1, 0, n - 1, l - 1, r - 1) << '\n';
  // }

  // Since this is a static array, we can simply use a prefix XOR array.
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  partial_sum(a.begin(), a.end(), a.begin(),
              [&](auto& a, auto& b) { return a ^ b; });

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (a[r] ^ a[l - 1]) << '\n';
  }
}
