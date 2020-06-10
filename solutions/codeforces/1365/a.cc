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

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

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
    vector<vb> grid(n, vb(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        grid[i][j] = x;
      }
    }

    int unclaimedRows = 0, unclaimedCols = 0;
    for (int i = 0; i < n; ++i) {
      bool claimed = false;
      for (int j = 0; j < m; ++j) {
        if (grid[i][j]) {
          claimed = true;
          break;
        }
      }
      if (!claimed) ++unclaimedRows;
    }

    for (int i = 0; i < m; ++i) {
      bool claimed = false;
      for (int j = 0; j < n; ++j) {
        if (grid[j][i]) {
          claimed = true;
          break;
        }
      }
      if (!claimed) ++unclaimedCols;
    }

    int unclaimed = min(unclaimedCols, unclaimedRows);
    if (unclaimed % 2) {
      cout << "Ashish";
    } else {
      cout << "Vivek";
    }
    cout << '\n';
  }
}
