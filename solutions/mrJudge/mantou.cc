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

  bitset<1000001> p;
  p.set();
  p[0] = p[1] = 0;
  for (int j = 4; j <= 1000000; j += 2) {
    p[j] = 0;
  }

  for (ll i = 3; i * i <= 1000000; i += 2) {
    if (p[i]) {
      for (ll j = i * i; j <= 1000000; j += i) {
        p[j] = 0;
      }
    }
  }

  int n;
  cin >> n;
  vector<vc> grid(n, vc(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      int idx = i * n + j + 1;
      if (!p[idx]) {
        grid[i][j] = c;
      }
    }
  }

  for (int j = 0; j < n; ++j) {
    int lastEmpty = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (!grid[i][j]) continue;

      while (lastEmpty > i && grid[lastEmpty][j]) {
        lastEmpty--;
      }

      if (lastEmpty > i) {
        grid[lastEmpty][j] = grid[i][j];
        grid[i][j] = 0;
        lastEmpty--;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (grid[i][j] ? grid[i][j] : ' ');
    }
    cout << '\n';
  }
}

