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

  int n;
  cin >> n;
  vii left, right;
  for (int i = 0; i < n; ++i) {
    int x, a;
    cin >> x >> a;
    if (x < 0) {
      left.eb(-x, a);
    } else {
      right.eb(x, a);
    }
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  ll tot = 0;
  if (right.size() > left.size()) {
    tot = right[left.size()].second;
    for (int i = 0; i < (int)left.size(); ++i) {
      tot += left[i].second + right[i].second;
    }
  } else if (left.size() > right.size()) {
    tot = left[right.size()].second;
    for (int i = 0; i < (int)right.size(); ++i) {
      tot += left[i].second + right[i].second;
    }
  } else {
    for (int i = 0; i < (int)right.size(); ++i) {
      tot += left[i].second + right[i].second;
    }
  }
  cout << tot;
}
