/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, n1, n2;
  cin >> n >> n1 >> n2;
  if (n1 > n2) {
    swap(n1, n2);
  }

  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.rbegin(), a.rend());

  int64_t fsum = accumulate(a.begin(), a.begin() + n1, (int64_t)0),
          ssum = accumulate(a.begin() + n1, a.begin() + n1 + n2, (int64_t)0);
  cout << fixed << setprecision(6)
       << (long double)fsum / n1 + (long double)ssum / n2;
}
