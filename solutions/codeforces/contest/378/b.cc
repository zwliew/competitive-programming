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

  int n;
  cin >> n;
  vi sorted;
  vi first, second;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    first.eb(x);
    second.eb(y);
    sorted.eb(x);
    sorted.eb(y);
  }
  nth_element(sorted.begin(), sorted.begin() + n - 1, sorted.end());
  unordered_set<int> topN(sorted.begin(), sorted.begin() + n);
  for (int i = 0; i < n; ++i) {
    if (i < n / 2 || topN.count(first[i])) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    if (i < n / 2 || topN.count(second[i])) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
}
