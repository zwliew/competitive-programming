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

  int n;
  cin >> n;
  vector<int> cnt(101);
  int total = 0;
  while (n--) {
    int x;
    cin >> x;
    cnt[x]++;
    if (cnt[x] >= 2) {
      cnt[x] -= 2;
      ++total;
    }
  }
  cout << total / 2;
}
