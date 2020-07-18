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

  int n, m;
  cin >> n >> m;
  vector<int> dirty(m);
  for (auto& x : dirty)
    cin >> x;
  sort(dirty.begin(), dirty.end());

  if (dirty.size() && (dirty.back() == n || dirty.front() == 1)) {
    cout << "NO";
    return 0;
  }

  for (int i = 2; i < m; ++i) {
    if (dirty[i] == dirty[i - 1] + 1 && dirty[i - 1] == dirty[i - 2] + 1) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
