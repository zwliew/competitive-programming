#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const vector<string> reps = {
      "AEIOUHWY", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R",
  };
  unordered_map<char, int> mp;
  for (char c = 'A'; c <= 'Z'; ++c) {
    int idx;
    for (idx = 0; idx < reps.size() && reps[idx].find(c) == string::npos; ++idx)
      ;
    mp[c] = idx;
  }

  string s;
  while (cin >> s) {
    for (int i = 0; i < s.size(); ++i) {
      int rep = mp[s[i]];
      if ((!i || rep != mp[s[i - 1]]) && rep)
        cout << rep;
    }
    cout << "\n";
  }
}
