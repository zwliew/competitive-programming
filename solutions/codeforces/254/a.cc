/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

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

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    int x;
    cin >> x;
    a[i] = {x, i + 1};
  }
  sort(a.begin(), a.end());

  vector<pair<int, int>> ans;
  for (int i = 0; i < n * 2 - 1; i += 2) {
    if (a[i].first != a[i + 1].first) {
      cout << -1;
      return 0;
    }
    ans.emplace_back(a[i].second, a[i + 1].second);
  }

  for (auto &[x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}
