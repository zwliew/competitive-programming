#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() { cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N), C(M);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (auto &x : C) cin >> x;

    vector<vector<int>> needed(N + 1);
    vector<int> wanted(N + 1, -1);
    for (int i = 0; i < N; ++i) {
      wanted[B[i]] = i;
      if (B[i] != A[i]) {
        needed[B[i]].push_back(i);
      }
    }

    if (wanted[C[M - 1]] == -1) {
      cout << "no\n";
      continue;
    }

    vector<int> ans(M, -1);
    for (int i = M - 1; i >= 0; --i) {
      if (!needed[C[i]].empty()) {
        ans[i] = needed[C[i]].back();
        needed[C[i]].pop_back();
      } else if (wanted[C[i]] != -1) {
        ans[i] = wanted[C[i]];
      } else {
        ans[i] = ans.back();
      }
    }

    bool failed = false;
    for (int i = 1; i <= N; ++i) {
      if (!needed[i].empty()) {
        failed = true;
        break;
      }
    }
    if (failed) {
      cout << "no\n";
      continue;
    }

    cout << "yes\n";
    for (int x : ans) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
}
