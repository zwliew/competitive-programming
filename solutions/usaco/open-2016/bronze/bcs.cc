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
#define FILE "bcs"
#endif

struct Boundary {
  int lr = INT_MAX;
  int rr = INT_MIN;
  int lc = INT_MAX;
  int rc = INT_MIN;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<vector<vector<bool>>> pieces(k + 1,
                                      vector<vector<bool>>(n, vector<bool>(n)));
  vector<Boundary> boundaries(k + 1);
  for (int i = 0; i < k + 1; ++i) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        char x;
        cin >> x;
        if (x == '#') {
          pieces[i][r][c] = true;
          boundaries[i].lr = min(boundaries[i].lr, r);
          boundaries[i].rr = max(boundaries[i].rr, r);
          boundaries[i].lc = min(boundaries[i].lc, c);
          boundaries[i].rc = max(boundaries[i].rc, c);
        }
      }
    }
  }

  for (int i = 1; i <= k; ++i) {
    for (int ir = -boundaries[i].lr; ir + boundaries[i].rr < n; ++ir) {
      for (int ic = -boundaries[i].lc; ic + boundaries[i].rc < n; ++ic) {
        for (int j = i + 1; j <= k; ++j) {
          for (int jr = -boundaries[j].lr; jr + boundaries[j].rr < n; ++jr) {
            for (int jc = -boundaries[j].lc; jc + boundaries[j].rc < n; ++jc) {
              vector<vector<bool>> seen(n, vector<bool>(n));
              for (int r = 0; r < n; ++r) {
                if (r - ir < 0 || r - ir >= n)
                  continue;
                for (int c = 0; c < n; ++c) {
                  if (c - ic < 0 || c - ic >= n)
                    continue;
                  seen[r][c] = pieces[i][r - ir][c - ic];
                }
              }

              bool ok = true;
              for (int r = 0; r < n && ok; ++r) {
                if (r - jr < 0 || r - jr >= n)
                  continue;
                for (int c = 0; c < n && ok; ++c) {
                  if (c - jc < 0 || c - jc >= n)
                    continue;
                  if (seen[r][c] && pieces[j][r - jr][c - jc]) {
                    ok = false;
                    break;
                  }
                  seen[r][c] = seen[r][c] || pieces[j][r - jr][c - jc];
                }
              }

              if (ok) {
                for (int r = 0; r < n && ok; ++r) {
                  for (int c = 0; c < n && ok; ++c) {
                    if (seen[r][c] != pieces[0][r][c]) {
                      ok = false;
                      break;
                    }
                  }
                }

                if (ok) {
                  cout << i << ' ' << j;
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
}
