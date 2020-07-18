/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  vector<bool> del(s.size());
  bool found = false;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '0') {
      del[i] = true;
      found = true;
      break;
    }
  }

  if (!found) {
    del[0] = true;
  }

  for (int i = 0; i < (int)s.size(); ++i) {
    if (!del[i]) {
      cout << s[i];
    }
  }
}
