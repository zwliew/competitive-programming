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

  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<int, int>> rows(n), cols(m);
  for (int ki = 1; ki <= k; ++ki) {
    int x, i, a;
    cin >> x >> i >> a;
    --i;

    if (x == 1) {
      rows[i] = {a, ki};
    } else {
      cols[i] = {a, ki};
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rows[i].second > cols[j].second) {
        cout << rows[i].first;
      } else {
        cout << cols[j].first;
      }
      cout << ' ';
    }
    cout << '\n';
  }
}
