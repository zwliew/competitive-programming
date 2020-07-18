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

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &z : a) cin >> z;

    bool ok = false;
    for (int z : a) {
      if (z % x) {
        ok = true;
        break;
      }
    }

    if (!ok) {
      cout << "-1\n";
      continue;
    }

    if (accumulate(a.begin(), a.end(), 0) % x) {
      cout << n << '\n';
      continue;
    }

    int firstNon = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] % x) {
        firstNon = i;
        break;
      }
    }

    int lastNon = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] % x) {
        lastNon = i;
        break;
      }
    }

    cout << n - min(firstNon + 1, n - lastNon) << '\n';
  }
}
