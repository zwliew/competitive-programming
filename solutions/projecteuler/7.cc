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

  bitset<10000001> bs;
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i = 2; i * i <= 1e7; ++i) {
    if (!bs[i]) continue;
    for (int j = i * i; j <= 1e7; j += i) {
      bs[j] = 0;
    }
  }

  int cnt = 1;
  for (int i = 3; i <= 1e7; i += 2) {
    if (bs[i]) ++cnt;
    if (cnt == 10001) {
      cout << i;
      return 0;
    }
  }
}
