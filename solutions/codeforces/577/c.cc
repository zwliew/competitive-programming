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
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n;
  cin >> n;
  int cnt = 0;
  vector<pair<int, int>> ans;
  for (int i = 2; i <= n; ++i) {
    bool prime = true;
    for (int j = 2; j * j <= i && prime; ++j) {
      if (i % j == 0) prime = false;
    }
    if (prime) {
      int curCnt = 0;
      int cur = i;
      while (cur <= n) {
        ++curCnt;
        cur *= i;
      }
      cnt += curCnt;
      ans.emplace_back(i, curCnt);
    }
  }

  cout << cnt << '\n';
  for (auto &[k, v] : ans) {
    int cur = k;
    for (int i = 1; i <= v; ++i) {
      cout << cur << ' ';
      cur *= k;
    }
  }
}
