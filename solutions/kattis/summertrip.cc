#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  string S;
  cin >> S;
  vector<int> prev(26, -1);
  int ans = 0;
  for (int i = 0; i < S.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      if (prev[S[i] - 'a'] < prev[j])
        ++ans;
    }
    prev[S[i] - 'a'] = i;
  }
  cout << ans;
}
