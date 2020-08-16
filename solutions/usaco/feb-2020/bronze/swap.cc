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
#define FILE "swap"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k, al, ar, bl, br;
  cin >> n >> k >> al >> ar >> bl >> br;

  // Faster O(N^2) time solution.
  // Idea: find the cycle size for each position.
  auto nxt = [&](int x) {
    if (x >= al && x <= ar)
      x = al + ar - x;
    if (x >= bl && x <= br)
      x = bl + br - x;
    return x;
  };

  vector<int> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    int cur = i;
    int cycleLen = 0;
    do {
      ++cycleLen;
      cur = nxt(cur);
    } while (cur != i);

    int rem = k % cycleLen;
    cur = i;
    while (rem--) {
      cur = nxt(cur);
    }
    res[cur] = i;
  }

  for (int i = 1; i <= n; ++i) {
    cout << res[i] << '\n';
  }

  // Slower O(NS) time solution.
  // Idea: find the cycle size of the entire permutation.
  // vector<int> orig(n), cur(n);
  // iota(orig.begin(), orig.end(), 1);
  // iota(cur.begin(), cur.end(), 1);

  // int cnt = 0;
  // bool same = false;
  // do {
  //   ++cnt;
  //   same = true;
  //   reverse(cur.begin() + al - 1, cur.begin() + ar);
  //   reverse(cur.begin() + bl - 1, cur.begin() + br);
  //   for (int i = min(al, bl) - 1; i < max(ar, br); ++i) {
  //     if (orig[i] != cur[i]) {
  //       same = false;
  //       break;
  //     }
  //   }
  // } while (!same);

  // for (int i = 0; i < k % cnt; ++i) {
  //   reverse(orig.begin() + al - 1, orig.begin() + ar);
  //   reverse(orig.begin() + bl - 1, orig.begin() + br);
  // }

  // for (int x : orig) {
  //   cout << x << '\n';
  // }
}
