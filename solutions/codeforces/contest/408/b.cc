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

  string s;
  cin >> s;
  vector<int> cnt(26);
  for (char c : s) {
    cnt[c - 'a']++;
  }

  cin >> s;
  vector<int> needed(26);
  for (char c : s) {
    needed[c - 'a']++;
  }

  int total = 0;
  for (int i = 0; i < 26; ++i) {
    if (needed[i] && !cnt[i]) {
      cout << -1;
      return 0;
    }
    total += min(needed[i], cnt[i]);
  }
  cout << total;
}
