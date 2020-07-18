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

  // Editorial solution
  int h0, m0, h1, m1;
  scanf("%d:%d", &h0, &m0);
  scanf("%d:%d", &h1, &m1);
  h0 -= h1;
  m0 -= m1;

  if (m0 < 0) {
    m0 += 60;
    --h0;
  }
  if (h0 < 0) {
    h0 += 24;
  }

  printf("%02d:%02d", h0, m0);

  // My original solution
  // string s, t;
  // cin >> s >> t;

  // int hours = stoi(s.substr(0, 2));
  // int min = stoi(s.substr(3));
  // int curMin = hours * 60 + min;
  // hours = stoi(t.substr(0, 2));
  // min = stoi(t.substr(3));
  // curMin -= hours * 60 + min;

  // curMin += 1440;
  // curMin %= 1440;
  // hours = curMin / 60;
  // min = curMin % 60;
  // if (hours < 10) {
  //   cout << '0';
  // }
  // cout << hours << ':';
  // if (min < 10) {
  //   cout << '0';
  // }
  // cout << min;
}
