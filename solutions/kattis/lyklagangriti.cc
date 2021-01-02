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

  list<char> l;
  char c;
  list<char>::iterator cur = l.begin();
  while (cin >> c) {
    if (c == 'L') {
      --cur;
    } else if (c == 'R') {
      ++cur;
    } else if (c == 'B') {
      auto prv = prev(cur);
      l.erase(prv);
    } else {
      l.insert(cur, c);
    }
  }

  for (char c : l) {
    cout << c;
  }
}
