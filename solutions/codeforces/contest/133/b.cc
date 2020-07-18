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

  vector<char> v = {'>', '<', '+', '-', '.', ',', '[', ']'};
  string s;
  cin >> s;
  int64_t total = 0;
  for (char c : s) {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == c) {
        total = total * 16 + i + 8;
        total %= 1000003;
        break;
      }
    }
  }

  cout << total;
}
