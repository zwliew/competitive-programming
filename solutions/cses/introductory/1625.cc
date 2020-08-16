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
#define FILE "backforth"
#endif

array<bitset<7>, 7> vis;
array<int, 48> s;
int ans = 0;

inline bool possible(int r, int c) {
  return r >= 0 && c >= 0 && r < 7 && c < 7 && !vis[r][c];
}

void backtrack(int idx, int r, int c) {
  if (r == 6 && c == 0) {
    ans += idx == 48;
    return;
  }
  if (!possible(r, c)) {
    return;
  }

  if ((!possible(r + 1, c) && !possible(r - 1, c) && possible(r, c + 1) &&
       possible(r, c - 1)) ||
      (!possible(r, c + 1) && !possible(r, c - 1) && possible(r + 1, c) &&
       possible(r - 1, c))) {
    return;
  }

  vis[r][c] = true;

  if (s[idx] == -1) {
    backtrack(idx + 1, r + 1, c);
    backtrack(idx + 1, r - 1, c);
    backtrack(idx + 1, r, c - 1);
    backtrack(idx + 1, r, c + 1);
  } else {
    int dr = 0, dc = 0;
    if (s[idx] == 0) {
      dr = -1;
    } else if (s[idx] == 1) {
      dr = 1;
    } else if (s[idx] == 2) {
      dc = -1;
    } else {
      dc = 1;
    }
    backtrack(idx + 1, r + dr, c + dc);
  }

  vis[r][c] = false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string x;
  cin >> x;
  for (int i = 0; i < 48; ++i) {
    if (x[i] == '?') {
      s[i] = -1;
    } else if (x[i] == 'U') {
      s[i] = 0;
    } else if (x[i] == 'D') {
      s[i] = 1;
    } else if (x[i] == 'L') {
      s[i] = 2;
    } else if (x[i] == 'R') {
      s[i] = 3;
    }
  }

  backtrack(0, 0, 0);
  cout << ans;
}
