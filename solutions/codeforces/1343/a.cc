/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int k = 2; k < 30; ++k) {
      int p = (1 << k) - 1;
      if (n % p == 0) {
        cout << n / p << '\n';
        break;
      }
    }
  }
}
