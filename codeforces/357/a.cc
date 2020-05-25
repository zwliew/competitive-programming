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
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
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

  int m;
  cin >> m;
  vi scores(m);
  for (auto &x : scores) cin >> x;
  int x, y;
  cin >> x >> y;

  int total = accumulate(scores.begin(), scores.end(), 0);
  int cur = 0;
  for (int i = 0; i < m; ++i) {
    cur += scores[i];
    if (cur >= x && cur <= y && total - cur >= x && total - cur <= y) {
      cout << i + 2 << '\n';
      return 0;
    }
  }
  cout << 0;
}
