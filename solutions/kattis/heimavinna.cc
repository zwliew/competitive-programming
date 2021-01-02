#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  vector<bool> marked(1001);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    int start = 0;
    while (i < s.size() && s[i] != ';' && s[i] != '-') {
      start = start * 10 + (s[i] - '0');
      ++i;
    }

    if (i == s.size() || s[i] == ';') {
      marked[start] = true;
      debug(start);
      continue;
    }
    ++i;

    int end = 0;
    while (i < s.size() && s[i] != ';') {
      end = end * 10 + (s[i] - '0');
      ++i;
    }

    for (int j = start; j <= end; ++j) {
      marked[j] = true;
    }
  }

  cout << accumulate(marked.begin(), marked.end(), 0);
}
