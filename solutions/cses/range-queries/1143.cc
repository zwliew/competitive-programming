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

void update(vector<int> &t, int v, int tl, int tr, int pos, int x) {
  if (tl == tr) {
    t[v] = x;
  } else {
    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
      update(t, v << 1, tl, tm, pos, x);
    } else {
      update(t, v * 2 + 1, tm + 1, tr, pos, x);
    }
    t[v] = max(t[v << 1], t[v * 2 + 1]);
  }
}

int query(vector<int> &t, int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return -1e9;
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = tl + (tr - tl) / 2;
  return max(query(t, v << 1, tl, tm, l, min(tm, r)),
             query(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int getFirstGreater(vector<int> &t, int v, int tl, int tr, int l, int r,
                    int x) {
  if (tl == tr) {
    return t[v] >= x ? l : -1;
  }
  int tm = tl + (tr - tl) / 2;
  int cur = query(t, v << 1, tl, tm, l, min(tm, r));
  if (cur >= x) {
    return getFirstGreater(t, v << 1, tl, tm, l, min(tm, r), x);
  }
  return getFirstGreater(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Point update range queries on a dynamic array
  // Queries involve finding the first element greater than or equal to a value
  // Use a standard maximum segment tree for this
  int n, m;
  cin >> n >> m;
  vector<int> t(n * 4);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    update(t, 1, 0, n - 1, i, x);
  }

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    int idx = getFirstGreater(t, 1, 0, n - 1, 0, n - 1, x);
    if (idx != -1) {
      cout << idx + 1 << ' ';
      int cur = query(t, 1, 0, n - 1, idx, idx);
      update(t, 1, 0, n - 1, idx, cur - x);
    } else {
      cout << "0 ";
    }
  }
}
