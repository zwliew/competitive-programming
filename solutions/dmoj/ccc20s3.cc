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

  string T, S;
  cin >> T >> S;
  int TN = T.size();
  array<int, 26> tcnt;
  fill(tcnt.begin(), tcnt.end(), 0);
  for (char c : T) {
    tcnt[c - 'a']++;
  }

  array<int, 26> cnt;
  fill(cnt.begin(), cnt.end(), 0);
  set<vector<int64_t>> ans;
  vector<int64_t> h(2), pw(2);
  const array<int, 2> p = {31, 131};
  const array<int, 2> m = {int(1e9 + 7), int(1e9 + 9)};
  for (int i = 0; i < 2; ++i) {
    pw[i] = 1;
    for (int j = 0; j < T.size(); ++j) {
      pw[i] = (pw[i] * p[i]) % m[i];
    }
  }
  for (int i = 0; i < S.size(); ++i) {
    cnt[S[i] - 'a']++;
    for (int j = 0; j < 2; ++j) {
      h[j] = (h[j] * p[j] + (S[i] - 'a')) % m[j];
    }
    if (i >= TN) {
      cnt[S[i - TN] - 'a']--;
      for (int j = 0; j < 2; ++j) {
        h[j] = ((h[j] - (S[i - TN] - 'a') * pw[j]) % m[j] + m[j]) % m[j];
      }
    }
    if (cnt == tcnt) {
      ans.insert(h);
    }
  }
  cout << ans.size();
}
