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

int fp(vi &p, int a) { return p[a] == a ? a : (p[a] = fp(p, p[a])); }
void us(vi &p, vi &r, int a, int b) {
  a = fp(p, a);
  b = fp(p, b);
  if (a == b)
    return;
  else if (r[a] < r[b])
    swap(a, b);
  else if (r[a] == r[b])
    ++r[a];
  p[b] = a;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, q;
  cin >> n >> q;

  vi p(n), r(n);
  iota(p.begin(), p.end(), 0);

  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t) {
      cout << (fp(p, u) == fp(p, v)) << '\n';
    } else {
      us(p, r, u, v);
    }
  }
}
