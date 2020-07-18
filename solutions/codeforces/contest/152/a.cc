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

  int n, m;
  cin >> n >> m;
  vector<int> maxGrade(m);
  vector<vector<int>> grades(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      grades[i][j] = c - '0';
      maxGrade[j] = max(maxGrade[j], c - '0');
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool best = false;
    for (int j = 0; j < m && !best; ++j) {
      if (grades[i][j] == maxGrade[j])
        best = true;
    }
    if (best) {
      ans++;
    }
  }

  cout << ans;
}
