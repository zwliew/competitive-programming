/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  map<int, pair<int, int>> m;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int rem = x - a[i] - a[j];
      if (m.count(rem)) {
        cout << m[rem].first + 1 << ' ' << m[rem].second + 1 << ' ' << i + 1
             << ' ' << j + 1 << '\n';
        return 0;
      }
    }

    for (int j = 0; j < i; ++j) {
      m[a[i] + a[j]] = {j, i};
    }
  }
  cout << "IMPOSSIBLE";
}
