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
#include <iterator>
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
#define FILE ""
#endif

// struct SegTree {
//   vector<int> val, lazy;
//   int n;
//   SegTree(vector<int>& a) {
//     val.resize(n * 4);
//     lazy.resize(n * 4);
//     n = a.size();
//     build(a, 0, 0, n);
//   }
//   void build(vector<int>& a, int ti, int tl, int tr) {
//     if (tl == tr - 1) {
//       val[ti] = a[tl];
//       return;
//     }
//     int tm = tl + (tr - tl) / 2;
//     build(a, ti * 2 + 1, tl, tm);
//     build(a, ti * 2 + 2, tm, tr);
//   }
//   void update(int ti, int x) {
//     val[ti] = x;
//     lazy[ti] = x;
//   }
//   void propagate(int ti, int tl, int tr) {
//     if (!lazy[ti])
//       return;
//     int tm = tl + (tr - tl) / 2;
//     update(ti * 2 + 1, lazy[ti]);
//     update(ti * 2 + 2, lazy[ti]);
//     lazy[ti] = 0;
//   }
//   void set(int l, int r, int x) { set(l, r, x, 0, 0, n); }
//   void set(int l, int r, int x, int ti, int tl, int tr) {
//     if (l >= tr || tl >= r)
//       return;
//     if (tl >= l && tr <= r) {
//       val[ti] = x;
//       lazy[ti] = x;
//       return;
//     }
//     propagate(ti, tl, tr);
//     int tm = tl + (tr - tl) / 2;
//     set(l, r, x, ti * 2 + 1, tl, tm);
//     set(l, r, x, ti * 2 + 2, tm, tr);
//   }
//   int query(int i) { return query(i, 0, 0, n); }
//   int query(int i, int ti, int tl, int tr) {
//     if (tl == tr - 1) {
//       return val[ti];
//     }
//     propagate(ti, tl, tr);
//     int tm = tl + (tr - tl) / 2;
//     if (i < tm) {
//       return query(i, ti * 2 + 1, tl, tm);
//     }
//     return query(i, ti * 2 + 2, tm, tr);
//   }
// };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (auto& x : a)
    cin >> x;

  // Original segment tree solution (187ms)
  // SegTree st(a);
  // vector<int> flipped(N + 1);
  // while (Q--) {
  //   int l, r, x;
  //   cin >> l >> r >> x;
  //   --l;
  //   st.set(l, r, x);
  //   flipped[l]++;
  //   flipped[r]++;
  // }
  // partial_sum(flipped.begin(), flipped.end(), flipped.begin());
  // for (int i = 0; i < N; ++i) {
  //   int f = flipped[i];
  //   if (!a[i]) {
  //     f++;
  //   }
  //   f %= 2;
  //   if (f) {
  //     cout << "0 ";
  //   } else {
  //     cout << st.query(i) << ' ';
  //   }
  // }

  // sweep line (140ms)
  vector<vector<pair<int, int>>> events(N + 1);
  // vector<array<int, 3>> events(Q * 2);
  for (int i = 0; i < Q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    events[l].emplace_back(i, x);
    events[r].emplace_back(i, -x);
    // events[i * 2] = {l, x, i};
    // events[i * 2 + 1] = {r, -x, i};
  }
  // sort(events.begin(), events.end());

  set<pair<int, int>> ongoing;
  // int j = 0;
  for (int i = 0; i < N; ++i) {
    for (auto& [p, x] : events[i]) {
      if (x < 0) {
        ongoing.erase({p, -x});
      } else {
        ongoing.emplace(p, x);
      }
    }
    // while (j < Q * 2 && events[j][0] <= i) {
    //   if (events[j][1] < 0) {
    //     ongoing.erase({events[j][2], -events[j][1]});
    //   } else {
    //     ongoing.emplace(events[j][2], events[j][1]);
    //   }
    //   ++j;
    // }
    if (ongoing.empty()) {
      cout << a[i] << ' ';
    } else if ((ongoing.size() % 2 == 0) ^ (!a[i])) {
      cout << ongoing.rbegin()->second << " ";
    } else {
      cout << "0 ";
    }
  }
}
