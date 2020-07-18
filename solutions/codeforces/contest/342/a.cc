/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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
  vector<int> cnt(8);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  vector<tuple<int, int, int>> triplets;
  while (cnt[1] && cnt[2] && cnt[4]) {
    triplets.emplace_back(1, 2, 4);
    cnt[1]--;
    cnt[2]--;
    cnt[4]--;
  }

  while (cnt[1] && cnt[2] && cnt[6]) {
    triplets.emplace_back(1, 2, 6);
    cnt[1]--;
    cnt[2]--;
    cnt[6]--;
  }

  while (cnt[1] && cnt[3] && cnt[6]) {
    triplets.emplace_back(1, 3, 6);
    cnt[1]--;
    cnt[3]--;
    cnt[6]--;
  }

  for (int i = 1; i <= 7; ++i) {
    if (cnt[i]) {
      cout << -1;
      return 0;
    }
  }

  for (auto &[a, b, c] : triplets) {
    cout << a << ' ' << b << ' ' << c << '\n';
  }
}
