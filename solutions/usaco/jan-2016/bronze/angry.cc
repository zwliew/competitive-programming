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
#define FILE "angry"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> pos(n);
  for (auto& x : pos)
    cin >> x;
  sort(pos.begin(), pos.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 1;
    int rad = 1;
    int cpos = pos[i];
    for (int j = i - 1; j >= 0;) {
      bool exploded = false;
      while (j >= 0 && cpos - pos[j] <= rad) {
        --j;
        ++cnt;
        exploded = true;
      }
      if (!exploded) {
        break;
      }
      ++rad;
      cpos = pos[j + 1];
    }

    rad = 1;
    cpos = pos[i];
    for (int j = i + 1; j < n;) {
      bool exploded = false;
      while (j < n && pos[j] - cpos <= rad) {
        ++j;
        ++cnt;
        exploded = true;
      }
      if (!exploded) {
        break;
      }
      ++rad;
      cpos = pos[j - 1];
    }

    ans = max(ans, cnt);
  }

  cout << ans;
}
