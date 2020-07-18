/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  // Optimal solution
  int n, m;
  cin >> n >> m;
  int s = n + m;
  if (n < m) n = m;
  cout << n - 1 << ' ' << s - n;

  // Brute force solution
  //   vector<int> left(2);
  //   cin >> left[0] >> left[1];
  //   int prev = -1;
  //   bool turn = true;
  //   int a = 0, b = 0;
  //   vector<int> copy = left;
  //   while (left[0] || left[1]) {
  //     if (prev == -1) {
  //       --left[0];
  //       prev = 0;
  //     } else if (turn) {
  //       if (left[prev]) {
  //         --left[prev];
  //         ++a;
  //       } else {
  //         --left[!prev];
  //         prev = !prev;
  //         ++b;
  //       }
  //     } else {
  //       if (left[!prev]) {
  //         --left[!prev];
  //         prev = !prev;
  //         ++b;
  //       } else {
  //         --left[prev];
  //         ++a;
  //       }
  //     }
  //     turn = !turn;
  //   }
  //   int a2 = a, b2 = b;
  //   a = 0, b = 0;
  //   prev = -1;
  //   left = copy;
  //   while (left[0] || left[1]) {
  //     if (prev == -1) {
  //       --left[1];
  //       prev = 1;
  //     } else if (turn) {
  //       if (left[prev]) {
  //         --left[prev];
  //         ++a;
  //       } else {
  //         --left[!prev];
  //         prev = !prev;
  //         ++b;
  //       }
  //     } else {
  //       if (left[!prev]) {
  //         --left[!prev];
  //         prev = !prev;
  //         ++b;
  //       } else {
  //         --left[prev];
  //         ++a;
  //       }
  //     }
  //     turn = !turn;
  //   }

  //   if (a2 > a) {
  //     cout << a2 << ' ' << b2;
  //   } else {
  //     cout << a << ' ' << b;
  //   }
}
