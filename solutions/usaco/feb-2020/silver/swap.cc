#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
#define FILE "swap"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M, K;
  cin >> N >> M >> K;
  vector<int> perm(N);
  iota(perm.begin(), perm.end(), 0);
  vector<int> res = perm;
  for (int i = 0; i < M; ++i) {
    int l, r;
    cin >> l >> r;
    reverse(perm.begin() + l - 1, perm.begin() + r);
  }

  auto permute = [](vector<int>& cur, vector<int>& p) {
    vector<int> res(cur.size());
    for (int i = 0; i < p.size(); ++i) {
      res[i] = cur[p[i]];
    }
    return res;
  };

  while (K) {
    if (K & 1) {
      res = permute(res, perm);
    }
    K >>= 1;
    perm = permute(perm, perm);
  }

  for (int x : res) {
    cout << x + 1 << "\n";
  }
}
