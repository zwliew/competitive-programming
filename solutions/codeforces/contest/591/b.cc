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

bool ok(vector<vector<char>>& grid, int r, int c) {
  return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
         grid[r][c] == '#';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> cur(26);
  iota(cur.begin(), cur.end(), 0);
  while (m--) {
    char a, b;
    cin >> a >> b;
    a -= 'a';
    b -= 'a';

    if (a == b) {
      continue;
    }

    for (int i = 0; i < 26; ++i) {
      if (cur[i] == a) {
        cur[i] = b;
      } else if (cur[i] == b) {
        cur[i] = a;
      }
    }
  }

  for (char c : s) {
    cout << (char)(cur[c - 'a'] + 'a');
  }
}
