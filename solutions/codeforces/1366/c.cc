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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }

    vector<vector<int>> cnt(n + m - 1, vector<int>(2));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cnt[i + j][grid[i][j]]++;
      }
    }

    int ans = 0;
    for (int i = 0; i < n + m - 1; ++i) {
      int j = n + m - 2 - i;
      if (i <= j) continue;
      ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
    }

    cout << ans << '\n';
  }
}
