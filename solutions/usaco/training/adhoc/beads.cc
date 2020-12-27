/*
ID: zhaowei10
LANG: C++14
TASK: beads
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
#define FILE "beads"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  string S;
  cin >> N >> S;

  auto inc = [&](int x) { return (x + 1) % N; };
  auto dec = [&](int x) { return (x - 1 + N) % N; };
  auto compute = [&](int i, char a, char b) {
    int cur = 0;
    int j;
    bool passed = false;
    for (j = i; (!passed || j != i) && (S[j] == 'w' || S[j] == a);
         j = inc(j), ++cur, passed = true)
      ;
    j = dec(j);
    for (int k = dec(i); k != j && (S[k] == 'w' || S[k] == b);
         k = dec(k), ++cur)
      ;
    return cur;
  };

  array<char, 2> avail = {'r', 'b'};
  int ans = INT_MIN;
  for (int i = 0; i < N; ++i) {
    for (char a : avail) {
      for (char b : avail) {
        ans = max(ans, compute(i, a, b));
      }
    }
  }
  cout << ans << "\n";
}
