#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  unordered_map<string, int> cnt;
  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ans += cnt[s];
    ++cnt[s];
  }
  cout << ans;
}
