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

  int n;
  cin >> n;
  vector<int> h(n);
  for (int &x : h) cin >> x;
  int best = 0;
  for (int i = 1; i < n; ++i) {
    int diff = abs(h[i] - h[(i + 1) % n]);
    if (diff < abs(h[best] - h[(best + 1) % n])) {
      best = i;
    }
  }
  cout << best + 1 << ' ' << (best + 1) % n + 1;
}
