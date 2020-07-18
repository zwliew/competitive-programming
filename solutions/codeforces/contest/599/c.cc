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
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr[i] = {x, i};
  }
  sort(arr.begin(), arr.end());

  int ans = 0;
  int i = 0;
  int j = 0;
  while (i < n) {
    while (i <= j) {
      j = max(j, arr[i].second);
      ++i;
    }
    j = i;
    ++ans;
  }
  cout << ans;
}
