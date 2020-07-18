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

  const vector<int> p = {150, 300, 450, 600, 750};
  vector<int> m(5), w(5);
  for (int &x : m) cin >> x;
  for (int &x : w) cin >> x;
  int s, u;
  cin >> s >> u;

  int score = s * 100 - u * 50;
  for (int i = 0; i < 5; ++i) {
    score += max(p[i], (250 - m[i]) * p[i] * 10 / 3 / 250 - 50 * w[i]);
  }
  cout << score;
}

