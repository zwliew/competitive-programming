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

void build(vector<int> &a, vector<int> &t, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl - 1];
  } else {
    int tm = tl + (tr - tl) / 2;
    build(a, t, v * 2, tl, tm);
    build(a, t, v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

void update(vector<int> &t, int v, int tl, int tr, int idx, int x) {
  if (tl == tr) {
    t[v] = x;
  } else {
    int tm = tl + (tr - tl) / 2;
    if (idx <= tm) {
      update(t, v * 2, tl, tm, idx, x);
    } else {
      update(t, v * 2 + 1, tm + 1, tr, idx, x);
    }
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int query(vector<int> &t, int v, int tl, int tr, int l, int r) {
  if (l > r) return 1e9 + 1;
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = tl + (tr - tl) / 2;
  return min(query(t, v * 2, tl, tm, l, min(tm, r)),
             query(t, v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Point update range min query (PURQ) on a dynamic array
  // Use a standard segment tree
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int &i : x) cin >> i;
  vector<int> t(n * 4);
  build(x, t, 1, 1, n);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(t, 1, 1, n, b, c);
    } else {
      cout << query(t, 1, 1, n, b, c) << '\n';
    }
  }
}
