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

  // Solution using hash tables/BST
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int rem = x - a[i] - a[j];
      if (m.count(rem)) {
        cout << m[rem] + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
    }
    m[a[i]] = i;
  }
  cout << "IMPOSSIBLE";

  // Solution using sorting and 2 pointers
  // int n, x;
  // cin >> n >> x;
  // vector<pair<int, int>> a(n);
  // for (int i = 0; i < n; ++i) {
  //   int c;
  //   cin >> c;
  //   a[i] = {c, i + 1};
  // }
  // sort(a.begin(), a.end());

  // for (int i = 0; i < n; ++i) {
  //   int rem = x - a[i].first;
  //   for (int j = i + 1, k = n - 1; j < k; ++j) {
  //     while (j < k && a[j].first + a[k].first > rem) {
  //       --k;
  //     }
  //     if (j < k && a[j].first + a[k].first == rem) {
  //       cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second <<
  //       '\n'; return 0;
  //     }
  //   }
  // }
  // cout << "IMPOSSIBLE";
}
