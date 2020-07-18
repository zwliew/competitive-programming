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

  int n, m, k;
  cin >> n >> m >> k;
  vi arr(n);
  for (int &x : arr)
    cin >> x;
  vector<tuple<int, int, int>> ops(m);
  for (auto &[l, r, d] : ops) {
    cin >> l >> r >> d;
    --l, --r;
  }

  vi opsDiff(m + 1);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    opsDiff[x]++;
    opsDiff[y + 1]--;
  }

  vll arrDiff(n + 1);
  ll cur = 0;
  for (int i = 0; i < m; ++i) {
    cur += opsDiff[i];
    auto &[l, r, d] = ops[i];
    arrDiff[l] += cur * d;
    arrDiff[r + 1] -= cur * d;
  }

  cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += arrDiff[i];
    cout << arr[i] + cur << ' ';
  }
}
