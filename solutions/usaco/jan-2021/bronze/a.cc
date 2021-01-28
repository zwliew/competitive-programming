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

  array<int, 26> pos;
  for (int i = 0; i < 26; ++i) {
    char c;
    cin >> c;
    pos[c - 'a'] = i;
  }

  string S;
  cin >> S;
  int ans = 1;
  for (int i = 1; i < S.size(); ++i) {
    int cpos = pos[S[i] - 'a'];
    int ppos = pos[S[i - 1] - 'a'];
    if (cpos <= ppos) {
      ans++;
    }
  }
  cout << ans;
}
