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
#define FILE "socdist"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s;
  cin >> s;
  unordered_map<char, int> m;
  for (char c : s) {
    ++m[c];
  }

  char odd = 0;
  for (char i = 'z'; i >= 'a'; --i) {
    if (m[i] % 2 == 0)
      continue;
    bool found = false;
    for (char j = 'a'; j <= 'z'; ++j) {
      if (j == i || m[j] % 2 == 0)
        continue;
      ++m[j];
      --m[i];
      found = true;
      break;
    }

    if (!found) {
      odd = i;
      break;
    }
  }

  vector<char> ans(s.size());
  if (odd) {
    ans[s.size() / 2] = odd;
  }
  int i = 0, j = s.size() - 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (c == odd)
      --m[c];
    for (int k = 0; k < m[c] / 2; ++k) {
      ans[i] = c;
      ans[j] = c;
      ++i;
      --j;
    }
  }

  for (char c : ans) {
    cout << c;
  }
}
