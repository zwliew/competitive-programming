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

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<queue<int>> pos(10);
  for (int i = 0; i < (int)s.size(); ++i) {
    pos[s[i] - '0'].emplace(i);
  }

  int end = n - k;
  int j = 0;
  for (int i = 0; i < end; ++i, ++j) {
    bool found = false;
    for (int digit = !i && end != i + 1; digit < 10 && !found; ++digit) {
      while (pos[digit].size() && pos[digit].front() < j) {
        pos[digit].pop();
      }
      if (pos[digit].size() && pos[digit].front() <= j + k) {
        cout << digit;
        k -= pos[digit].front() - j;
        j = pos[digit].front();
        pos[digit].pop();
        found = true;
      }
    }
    if (!found) {
      cout << s[j];
    }
  }
}
